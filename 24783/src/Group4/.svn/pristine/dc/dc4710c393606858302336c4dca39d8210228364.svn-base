from vpython import *
import random

def stl_to_triangles(fileinfo): # specify file
    # Accept a file name or a file descriptor; make sure mode is 'rb' (read binary)
    fd = open(fileinfo, mode='rb')
    text = fd.read()
    tris = [] # list of triangles to compound
    if False: # prevent executing code for binary file
        pass
    else:
        fd.seek(0)
        fList = fd.readlines()
    
        # Decompose list into vertex positions and normals
        vs = []
        for line in fList:
            FileLine = line.split( )
            if FileLine[0] == b'facet':
                N = vec(float(FileLine[2]), float(FileLine[3]), float(FileLine[4]))
            elif FileLine[0] == b'vertex':
                vs.append( vertex(pos=vec(float(FileLine[1]), float(FileLine[2]), float(FileLine[3])), normal=N, color=color.white) )
                if len(vs) == 3:
                    tris.append(triangle(vs=vs))
                    vs = []
                    
    return compound(tris)

def drawWalls():
    box(pos=vector(5,5,0), size=vector(8,0.1,3), color=color.black) 
    box(pos=vector(1,7,0), size=vector(0.1,4,3), color=color.black) 
    box(pos=vector(10,4,0), size=vector(3,0.1,3), color=color.black) 

def main():
    scene2 = canvas(title='Path planning visualiser\n', x=0, y=0, width=1280, height=800, center=vector(5,0,0), background=color.gray(0.1))

    boxList = []

    floor = box(pos=vector(0,0,0), size=vector(25,25,0.1), color=color.gray(0.5))
    zLoc = 0.6

    robot = stl_to_triangles("robot.stl")
    robot.pos = vector(0,0,1.8)
    robot.size *= 0.008
    robot.color = color.green
    robot.up = vector(0,0,1)
    #drawWalls()

    for xLoc in range(-5,6):
        for yLoc in range(-5,6):
            boxList.append(cylinder(pos=vector(xLoc*2,yLoc*2,zLoc), radius=0.5, axis=vector(0,0,1) , size=vector(0.5,0.5,0.5), color=color.red))



if __name__ == "__main__":
    main()
