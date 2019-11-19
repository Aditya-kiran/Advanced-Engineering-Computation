#include <fssimplewindow.h> // For FsSubSecondTimer
#include <meshlattice.h>
#include <math.h>
#include <unordered_set>
#include "ps7lib.h"
#include <stdio.h>

std::vector <float> MakeSliceVertexArray(const YsShellExt &mesh)
{
	auto t0=FsSubSecondTimer();
	std::vector <float> sliceVtx;

	YsVec3 minBB;
	YsVec3 maxBB;

	mesh.GetBoundingBox(minBB, maxBB);

	auto miny = minBB[1];

	auto maxy = maxBB[1];

	std::vector <float> vtx, vty, vtz;

	for(auto plHd=mesh.NullPolygon(); true==mesh.MoveToNextPolygon(plHd); )
	{
		vtz.clear();
		vty.clear();
		vtx.clear();

		auto plVtHd=mesh.GetPolygonVertex(plHd);
		auto plNom=mesh.GetNormal(plHd);
		auto plCol=mesh.GetColor(plHd);
		
		float pl_min_y = 100;
		float pl_max_y = -100; 

		if(3==plVtHd.size())
		{
			for(int i=0; i<3; ++i)
			{
				auto vtPos=mesh.GetVertexPosition(plVtHd[i]);

				vtx.push_back(vtPos.xf());
				vty.push_back(vtPos.yf());
				vtz.push_back(vtPos.zf());
				
				if (vtPos.yf()>pl_max_y)
				{
					pl_max_y = vtPos.yf();
				}

				if (vtPos.yf()<pl_min_y)
				{
					pl_min_y = vtPos.yf();
				}
			}
		}

		auto m = int(pl_min_y*100/(maxy-miny));
		m++;
		auto start = (maxy-miny)*m/100.0;
		auto update = (maxy-miny)/100.0;

		for (float y = start; y<=pl_max_y; y+=update)
		{
			auto points_on_plane = YsVec3(0.0, y, 0.0);
			auto normal = YsVec3(0.0, 1.0, 0.0);
			auto plane = YsPlane(points_on_plane, normal);



			for (int i=0; i<3; i++)
			{

				auto i2 = (i+1)%3;
				YsVec3 inters;
				if ((vty[i]<y && vty[i2]>y) || (vty[i]>y && vty[i2]<y))
				{
					auto pt1 = YsVec3(vtx[i], vty[i], vtz[i]);
					auto pt2 = YsVec3(vtx[i2], vty[i2], vtz[i2]);

					plane.GetPenetration(inters, pt1, pt2);

					sliceVtx.push_back(inters.xf());
					sliceVtx.push_back(inters.yf());
					sliceVtx.push_back(inters.zf());
				}
			}

		}
	}
	printf("%d milli seconds\n",(int)FsSubSecondTimer()-t0);
	return sliceVtx;
}


#define USE_LATTICE

double triangular_area(YsVec3 v1, YsVec3 v2, YsVec3 v3)
{
	auto edge1 = v2 - v1;
	auto edge2 = v3 - v1;
	auto normal = edge1^edge2;

	auto length = normal.GetLength();

	return 0.5*length;
}

double angles(YsVec3 v1, YsVec3 v2)
{
	auto dot_product = v1.xf()*v2.xf() + v1.yf()*v2.yf() + v1.zf()*v2.zf();  

	auto seq_1 = v1.xf()*v1.xf() + v1.yf()*v1.yf() + v1.zf()*v1.zf();
	auto seq_2 = v2.xf()*v2.xf() + v2.yf()*v2.yf() + v2.zf()*v2.zf();

	auto angle = acos(dot_product/sqrt(seq_1 * seq_2));
	return fabs(angle*180.0/YsPi);
}

std::vector <float> MakeRayIntersectionVertexArray(const YsShellExt &mesh)
{
	auto t0=FsSubSecondTimer();
	std::vector <float> rayItscVtx;
	std::vector <float> vtx, vty, vtz;

	YsVec3 minBB;
	YsVec3 maxBB;

	mesh.GetBoundingBox(minBB, maxBB);

	auto minx = minBB[0];
	auto miny = minBB[1];
	auto minz = minBB[2];

	auto maxx = maxBB[0];
	auto maxy = maxBB[1];
	auto maxz = maxBB[2];



	for(auto plHd=mesh.NullPolygon(); true==mesh.MoveToNextPolygon(plHd); )
	{
		vtx.clear();
		vty.clear();
		vtz.clear();

		auto plVtHd=mesh.GetPolygonVertex(plHd);

		float pl_min_y = maxy;
		float pl_max_y = miny; 
		float Plminx = maxx;
		float Plmaxx = minx; 

		if(3==plVtHd.size())
		{
			for(int i=0; i<3; ++i)
			{
				auto vtPos=mesh.GetVertexPosition(plVtHd[i]);
				vtx.push_back(vtPos.xf());
				vty.push_back(vtPos.yf());
				vtz.push_back(vtPos.zf());
				if (vtPos.yf()>pl_max_y)
				{
					pl_max_y = vtPos.yf();
				}

				if (vtPos.yf()<pl_min_y)
				{
					pl_min_y = vtPos.yf();
				}
				if (vtPos.xf()>Plmaxx)
				{
					Plmaxx = vtPos.xf();
				}

				if (vtPos.xf()<Plminx)
				{
					Plminx = vtPos.xf();
				}
			}
		}
		auto deltax = (maxx-minx)/100.0;
		auto mx = int((Plminx-minx)/deltax);
		auto deltay = (maxy-miny)/100.0;
		auto my = int((pl_min_y-miny)/deltay);

		mx++;
		my++;
		// printf("mx:%d, my:%d\n", mx, my);
		auto startx = minx + deltax*mx;
		auto starty = miny + deltay*my;


		for (float x = startx; x<=Plmaxx; x+=deltax)
		{
			
			for (float y = starty; y<=pl_max_y; y+=deltay) 
			{
				auto pt1 = YsVec3(x,y,minz);
				auto pt2 = YsVec3(x,y,maxz);
				
				auto plane = YsPlane();
				auto vt1 = YsVec3(vtx[0], vty[0], vtz[0]);
				auto vt2 = YsVec3(vtx[1], vty[1], vtz[1]);
				auto vt3 = YsVec3(vtx[2], vty[2], vtz[2]);

				plane.MakePlaneFromTriangle(vt1, vt2, vt3);
				YsVec3 inters;
				plane.GetPenetration(inters, pt1, pt2);

				auto Area = triangular_area(vt1, vt2, vt3);
				auto area1 = triangular_area(vt1, vt2, inters);
				auto area2 = triangular_area(vt2, vt3, inters);
				auto area3 = triangular_area(vt3, vt1, inters);

				if (area1+area2+area3 == Area)
				{
					rayItscVtx.push_back(inters.xf());
					rayItscVtx.push_back(inters.yf());
					rayItscVtx.push_back(inters.zf());
				}
			}
		}
	}

	printf("%d milli seconds\n",(int)FsSubSecondTimer()-t0);
	return rayItscVtx;
}



void Paint(YsShellExt &mesh,YsShell::PolygonHandle from,const double angleTolerance)
{
	std::vector <YsShellExt::PolygonHandle> todo;
	std::unordered_set <unsigned int> visited;

	todo.push_back(from);
	auto fromAngle = mesh.GetNormal(from);
	visited.insert(mesh.GetSearchKey(from));

	for(int i=0; i<todo.size(); ++i)
	{
		auto plHd=todo[i];
		mesh.SetPolygonColor(plHd,YsRed());
		for(int edIdx=0; edIdx<mesh.GetPolygonNumVertex(plHd); ++edIdx)
		{
			auto neiPlHd=mesh.GetNeighborPolygon(plHd,edIdx);
			auto neiAngle = mesh.GetNormal(neiPlHd);
			if(visited.end()==visited.find(mesh.GetSearchKey(neiPlHd)) && angles(fromAngle, neiAngle)<angleTolerance)
			{
				todo.push_back(neiPlHd);
				visited.insert(mesh.GetSearchKey(neiPlHd));
			}
		}
	}

}