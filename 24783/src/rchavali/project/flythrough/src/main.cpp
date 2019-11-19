/* ////////////////////////////////////////////////////////////

File Name: main.cpp
Copyright (c) 2017 Soji Yamakawa.  All rights reserved.
http://www.ysflight.com

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS 
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//////////////////////////////////////////////////////////// */
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fslazywindow.h>

#include "hiredis.h"
#include <iostream>

#include <vector>
#include "cJSON.h"

const double YsPi=3.1415927;

struct physical_node {
    int physical_node_id;
    double x;
    double y;
    int type;
    std::vector<int> phy_adjacent_nodes;
    std::vector<int> logicl_nodes;
    std::vector<int> lock_nodes;
};


class CameraObject
{
public:
    double x,y,z;
    double h,p,b;

    double fov,nearZ,farZ;

    CameraObject();
    void Initialize(void);
    void SetUpCameraProjection(void);
    void SetUpCameraTransformation(void);

    void GetForwardVector(double &vx,double &vy,double &vz);
    void GetUpVector(double &vx,double &vy,double &vz);
    void GetRightVector(double &vx,double &vy,double &vz);
};



CameraObject::CameraObject()
{
    Initialize();
}

void CameraObject::Initialize(void)
{
    x=0;
    y=0;
    z=0;
    h=0;
    p=0;
    b=0;

    fov=YsPi/6.0;  // 30 degree
    nearZ=0.1;
    farZ=200.0;
}

void CameraObject::SetUpCameraProjection(void)
{
    int wid,hei;
    double aspect;

    FsGetWindowSize(wid,hei);
    aspect=(double)wid/(double)hei;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov*180.0/YsPi,aspect,nearZ,farZ);
}

void CameraObject::SetUpCameraTransformation(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotated(-b*180.0/YsPi,0.0,0.0,1.0);  // Rotation about Z axis
    glRotated(-p*180.0/YsPi,1.0,0.0,0.0);  // Rotation about X axis
    glRotated(-h*180.0/YsPi,0.0,1.0,0.0);  // Rotation about Y axis
    glTranslated(-x,-y,-z);
}

void CameraObject::GetForwardVector(double &vx,double &vy,double &vz)
{
    vx=-cos(p)*sin(h);
    vy= sin(p);
    vz=-cos(p)*cos(h);
}

void CameraObject::GetUpVector(double &vx,double &vy,double &vz)
{
	const double ux0=0.0;
	const double uy0=1.0;
	const double uz0=0.0;

	const double ux1=cos(b)*ux0-sin(b)*uy0;
	const double uy1=sin(b)*ux0+cos(b)*uy0;
	const double uz1=uz0;

	const double ux2=ux1;
	const double uy2=cos(p)*uy1-sin(p)*uz1;
	const double uz2=sin(p)*uy1+cos(p)*uz1;

    vx=cos(-h)*ux2-sin(-h)*uz2;
    vy=uy2;
    vz=sin(-h)*ux2+cos(-h)*uz2;
}

void CameraObject::GetRightVector(double &vx,double &vy,double &vz)
{
	const double ux0=1.0;
	const double uy0=0.0;
	const double uz0=0.0;

	const double ux1=cos(b)*ux0-sin(b)*uy0;
	const double uy1=sin(b)*ux0+cos(b)*uy0;
	const double uz1=uz0;

	const double ux2=ux1;
	const double uy2=cos(p)*uy1-sin(p)*uz1;
	const double uz2=sin(p)*uy1+cos(p)*uz1;

    vx=cos(-h)*ux2-sin(-h)*uz2;
    vy=uy2;
    vz=sin(-h)*ux2+cos(-h)*uz2;
}





class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;

protected:
	CameraObject camera;
	int wid,hei;

public:
	FsLazyWindowApplication();
	virtual void BeforeEverything(int argc,char *argv[]);
	virtual void GetOpenWindowOption(FsOpenWindowOption &OPT) const;
	virtual void Initialize(int argc,char *argv[]);
	virtual void Interval(void);
	virtual void BeforeTerminate(void);
	virtual void Draw(void);
	virtual bool UserWantToCloseProgram(void);
	virtual bool MustTerminate(void) const;
	virtual long long int GetMinimumSleepPerInterval(void) const;
	virtual bool NeedRedraw(void) const;

protected:
    std::vector<float> robot_x;
    std::vector<float> robot_y;
    void RetrieveRobotPoistion(void);
    redisContext* ctx;
    std::vector<physical_node> physical_node_list;
    std::vector<physical_node> readPhysicalNodes();

};

std::vector<physical_node> FsLazyWindowApplication::readPhysicalNodes() {
    std::vector<physical_node> result;
    redisReply * replyId = (redisReply *)redisCommand(ctx, "lrange physical_node_list 0 -1");
    for(int i = 0 ; i < replyId->elements; i++)
    {
        std::string ids = replyId->element[i]->str;
        const char * data = ids.c_str();
        cJSON * json = cJSON_Parse(data);
        physical_node node;

        std::vector<int> lock_nodes;
        std::vector<int> phy_adjacent_nodes;
        std::vector<int> logical_nodes;

        int physical_node_id;
        double y;
        double x;

        cJSON * ptr = json->child;
        while (ptr != NULL) {
            std::string tempString = ptr->string;
            if (tempString == "x") {
                x = ptr->valuedouble;
            } else if (tempString == "physical_node_id") {
                physical_node_id = ptr->valueint;
            } else if (tempString == "phy_adjacent_nodes") {
                cJSON * tempPtr = ptr->child;
                while (tempPtr != NULL) {
                    phy_adjacent_nodes.push_back(tempPtr->valueint);
                    tempPtr = tempPtr->next;
                }
            } else if (tempString == "logical_nodes") {
//                cJSON * tempPtr = json->child;
//                while (tempPtr != NULL) {
//                    logical_nodes.push_back(tempPtr->valueint);
//                    tempPtr = tempPtr->next;
//                }
            } else if (tempString == "type") {

            } else if (tempString == "lock_nodes") {
                cJSON * tempPtr = ptr->child;
                while (tempPtr != NULL) {
                    lock_nodes.push_back(tempPtr->valueint);
                    tempPtr = tempPtr->next;
                }
            } else if (tempString == "y") {
                y = ptr->valuedouble;
            }
            ptr = ptr->next;
        }

//        int type;
//        type = std::stoi(json->child->next->next->next->next->next->next->valuestring);

        node.lock_nodes = lock_nodes;
        logical_nodes.push_back(physical_node_id);
        node.logicl_nodes = logical_nodes;
        node.physical_node_id = physical_node_id;
        node.phy_adjacent_nodes = phy_adjacent_nodes;
        node.x = x;
        node.y = y;
//        node.type = type;
        result.push_back(node);

    }
    freeReplyObject(replyId);
    return result;
}



void FsLazyWindowApplication::RetrieveRobotPoistion(void) {
    for (int i = 0; i < 3; i++) {
        //std::cout << "haha7" << std::endl;
        redisReply * x_reply = (redisReply *) redisCommand(ctx, "HGET robot_x %d", i + 1);
        redisReply * y_reply = (redisReply *) redisCommand(ctx, "HGET robot_y %d", i + 1);
        //std::cout << "haha6" << std::endl;
        std::cout << x_reply->str << std::endl;
        float temp_x = std::stof(x_reply->str);
        //std::cout << "haha4" << std::endl;
        float temp_y = std::stof(y_reply->str);
        //std::cout << "haha5" << std::endl;
        robot_x[i] = temp_x;
        robot_y[i] = temp_y;

        freeReplyObject(x_reply);
        freeReplyObject(y_reply);
    }
}


FsLazyWindowApplication::FsLazyWindowApplication()
{
	needRedraw=false;
}

/* virtual */ void FsLazyWindowApplication::BeforeEverything(int argc,char *argv[])
{
}
/* virtual */ void FsLazyWindowApplication::GetOpenWindowOption(FsOpenWindowOption &opt) const
{
	opt.x0=16;
	opt.y0=16;
	opt.wid=800;
	opt.hei=600;
}
/* virtual */ void FsLazyWindowApplication::Initialize(int argc,char *argv[])
{
    for (int i = 0; i < 3; i++) {
        robot_x.push_back(-1);
        robot_y.push_back(-1);
    }



    ctx = redisConnect("127.0.0.1", 6379);
    if(ctx->err)
    {
        std::cout<<"No connection with ctx_get"<<std::endl;
    } else {
        std::cout << "Successfully connected to Redis!" << std::endl;
    }


    std::cout << "11111" << std::endl;
    physical_node_list = readPhysicalNodes();
    std::cout << "22222" << std::endl;
    for (int i = 0; i < physical_node_list.size(); i++) {
        std::cout << physical_node_list[i].physical_node_id << std::endl;
    }

	camera.z=10.0;
    camera.y=5.0;
}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{

    RetrieveRobotPoistion();
    for (int i = 0; i < robot_x.size(); i++) {
        //std::cout << "haha2" << std::endl;
        std::cout << "robot_x " << i + 1 << " : " << robot_x[i] << std::endl;
        std::cout << "robot_y " << i + 1 << " : " << robot_y[i] << std::endl;
        //std::cout << "haha3" << std::endl;
    }

	FsPollDevice();

    FsGetWindowSize(wid,hei);

	auto key=FsInkey();
	if(FSKEY_ESC==key)
	{
		SetMustTerminate(true);
	}

    if(0!=FsGetKeyState(FSKEY_LEFT))
    {
        camera.h+=YsPi/180.0;
    }
    if(0!=FsGetKeyState(FSKEY_RIGHT))
    {
        camera.h-=YsPi/180.0;
    }
    if(0!=FsGetKeyState(FSKEY_UP))
    {
        camera.p+=YsPi/180.0;
    }
    if(0!=FsGetKeyState(FSKEY_DOWN))
    {
        camera.p-=YsPi/180.0;
    }
    if(0!=FsGetKeyState(FSKEY_F))
    {
        double vx,vy,vz;
        camera.GetForwardVector(vx,vy,vz);
        camera.x+=vx*0.5;
        camera.y+=vy*0.5;
        camera.z+=vz*0.5;
    }
    if(0!=FsGetKeyState(FSKEY_B))
    {
        double vx,vy,vz;
        camera.GetForwardVector(vx,vy,vz);
        camera.x-=vx*0.5;
        camera.y-=vy*0.5;
        camera.z-=vz*0.5;
    }

	needRedraw=true;
}
void DrawCube(double x1,double y1,double z1,double x2,double y2,double z2,int color)
{
    glColor3ub(0,0,color);

    glBegin(GL_QUADS);

    glVertex3d(x1,y1,z1);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x1,y2,z1);

    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x1,y2,z2);

    glVertex3d(x1,y1,z1);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y1,z2);
    glVertex3d(x1,y1,z2);

    glVertex3d(x1,y2,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x2,y2,z2);
    glVertex3d(x1,y2,z2);

    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y2,z2);
    glVertex3d(x1,y1,z2);

    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y1,z2);

    glEnd();

}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    glViewport(0,0,wid,hei);
    //std::cout << wid << " " << hei << std::endl;

    // Set up 3D drawing
    camera.SetUpCameraProjection();
    camera.SetUpCameraTransformation();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1,1);

    // 3D drawing from here
    glColor3ub(0,0,255);


    glBegin(GL_LINES);
    int x;
    for(x=-500; x<=500; x+=20)
    {
        glVertex3i(x,0,-500);
        glVertex3i(x,0, 500);
        glVertex3i(-500,0,x);
        glVertex3i( 500,0,x);
    }
    glEnd();


    for (int i = 0; i < physical_node_list.size(); i++) {
        // std::cout << physical_node_list[i].x << std::endl;
        DrawCube(physical_node_list[i].x,physical_node_list[i].y, 0,physical_node_list[i].x+1, physical_node_list[i].y+1,0,255);
    }

    for (int i=0; i < robot_x.size(); i++){
        
        DrawCube(robot_x[i],robot_y[i],0,robot_x[i]+1,robot_y[i]+1,0,0);
    }

    // Set up 2D drawing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,(float)wid-1,(float)hei-1,0,-1,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);
    FsSwapBuffers();	
	needRedraw=false;
}
/* virtual */ bool FsLazyWindowApplication::UserWantToCloseProgram(void)
{
	return true; // Returning true will just close the program.
}
/* virtual */ bool FsLazyWindowApplication::MustTerminate(void) const
{
	return FsLazyWindowApplicationBase::MustTerminate();
}
/* virtual */ long long int FsLazyWindowApplication::GetMinimumSleepPerInterval(void) const
{
	return 25;
}
/* virtual */ void FsLazyWindowApplication::BeforeTerminate(void)
{
}
/* virtual */ bool FsLazyWindowApplication::NeedRedraw(void) const
{
	return needRedraw;
}


static FsLazyWindowApplication *appPtr=nullptr;

/* static */ FsLazyWindowApplicationBase *FsLazyWindowApplicationBase::GetApplication(void)
{
	if(nullptr==appPtr)
	{
		appPtr=new FsLazyWindowApplication;
	}
	return appPtr;
}
