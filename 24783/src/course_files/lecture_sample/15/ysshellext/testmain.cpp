#include <stdio.h>

#include "polygonalmesh.h"


void MakeCube(PolygonalMesh &mesh)
{
	PolygonalMesh::VertexHandle vtHd[8]=
	{
		mesh.AddVertex(YsVec3(-1,-1,-1)), //0
		mesh.AddVertex(YsVec3( 1,-1,-1)), //1
		mesh.AddVertex(YsVec3( 1, 1,-1)), //2
		mesh.AddVertex(YsVec3(-1, 1,-1)), //3
		mesh.AddVertex(YsVec3(-1,-1, 1)), //4
		mesh.AddVertex(YsVec3( 1,-1, 1)), //5
		mesh.AddVertex(YsVec3( 1, 1, 1)), //6
		mesh.AddVertex(YsVec3(-1, 1, 1)), //7
	};

	PolygonalMesh::VertexHandle plVtHd[6][4]=
	{
		{vtHd[0],vtHd[1],vtHd[2],vtHd[3]},
		{vtHd[7],vtHd[6],vtHd[5],vtHd[4]},

		{vtHd[1],vtHd[0],vtHd[4],vtHd[5]},
		{vtHd[2],vtHd[1],vtHd[5],vtHd[6]},
		{vtHd[3],vtHd[2],vtHd[6],vtHd[7]},
		{vtHd[0],vtHd[3],vtHd[7],vtHd[4]},
	};

	PolygonalMesh::PolygonHandle plHd[6]=
	{
		mesh.AddPolygon(4,plVtHd[0]),
		mesh.AddPolygon(4,plVtHd[1]),
		mesh.AddPolygon(4,plVtHd[2]),
		mesh.AddPolygon(4,plVtHd[3]),
		mesh.AddPolygon(4,plVtHd[4]),
		mesh.AddPolygon(4,plVtHd[5]),
	};
}

int main(void)
{
	PolygonalMesh mesh;
	MakeCube(mesh);

	printf("Test begins.\n");
	for(auto vtHd=mesh.FindFirstVertex() ; mesh.NullVertex()!=vtHd; vtHd=mesh.FindNextVertex(vtHd))
	{
		printf("Vtx SearchKey=%d\n",mesh.GetSearchKey(vtHd));

		auto key=mesh.GetSearchKey(vtHd);
		auto reverse=mesh.FindVertex(key);
		if(reverse!=vtHd)
		{
			printf("Reverse search failure.\n");
		}

		auto vtxToPlg=mesh.FindPolygonFromVertex(vtHd);
		printf("Used from %d polygons\n",(int)vtxToPlg.size());
	}

	for(auto plHd=mesh.FindFirstPolygon(); mesh.NullPolygon()!=plHd; plHd=mesh.FindNextPolygon(plHd))
	{
		auto plVtHd=mesh.GetPolygonVertex(plHd);
		printf("Plg SearchKey=%d\n",mesh.GetSearchKey(plHd));
		printf("Using %d vertices\n",(int)plVtHd.size());

		auto key=mesh.GetSearchKey(plHd);
		auto reverse=mesh.FindPolygon(key);
		if(reverse!=plHd)
		{
			printf("Reverse search failure.\n");
		}

		for(auto vtHd : plVtHd)
		{
			auto usingPlHd=mesh.FindPolygonFromVertex(vtHd);
			auto found=std::find(usingPlHd.begin(),usingPlHd.end(),plHd);
			if(usingPlHd.end()==found)
			{
				printf("Vertex to Polygon table broken.\n");
			}
			else
			{
				printf("Verified Vertex to Polygon table\n");
			}
		}
	}

	return 0;
}
