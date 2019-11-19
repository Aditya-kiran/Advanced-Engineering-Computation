#include <algorithm>

#include "polygonalmesh.h"
#include "lattice.h"



PolygonalMesh::PolygonalMesh()
{
	searchKeySeed=1;
}
PolygonalMesh::~PolygonalMesh()
{
	CleanUp();
}
void PolygonalMesh::CleanUp(void)
{
	vtxList.clear();
}

bool PolygonalMesh::LoadBinStl(const char fName[])
{
	FILE *fp=fopen(fName,"rb");
	if(nullptr!=fp)
	{
		unsigned char buf[80];

		fread(buf,1,80,fp);


		fread(buf,4,1,fp);
		auto nTri=GetInteter(buf);
		printf("%d\n",nTri);


		int nActual=0;
		while(50==fread(buf,1,50,fp))
		{
			auto nx=GetFloat(buf+0);
			auto ny=GetFloat(buf+4);
			auto nz=GetFloat(buf+8);

			auto x0=GetFloat(buf+12);
			auto y0=GetFloat(buf+16);
			auto z0=GetFloat(buf+20);

			auto x1=GetFloat(buf+24);
			auto y1=GetFloat(buf+28);
			auto z1=GetFloat(buf+32);

			auto x2=GetFloat(buf+36);
			auto y2=GetFloat(buf+40);
			auto z2=GetFloat(buf+44);

			YsVec3 vtxPos[3]=
			{
				YsVec3(x0,y0,z0),
				YsVec3(x1,y1,z1),
				YsVec3(x2,y2,z2),
			};
			VertexHandle vtHd[3]=
			{
				AddVertex(vtxPos[0]),
				AddVertex(vtxPos[1]),
				AddVertex(vtxPos[2]),
			};
			auto plHd=AddPolygon(3,vtHd);

			SetPolygonNormal(plHd,YsVec3(nx,ny,nz));

			++nActual;
		}


		printf("%d\n",nActual);

		StitchVertex();
		DeleteUnusedVertex();

		fclose(fp);
		return true;
	}
	return false;
}

void PolygonalMesh::StitchVertexN2(void)
{
	for(auto vtHd0=FindFirstVertex(); NullVertex()!=vtHd0; vtHd0=FindNextVertex(vtHd0))
	{
		for(auto vtHd1=FindNextVertex(vtHd0); NullVertex()!=vtHd1; vtHd1=FindNextVertex(vtHd1))
		{
			if(GetVertexPosition(vtHd0)==GetVertexPosition(vtHd1))
			{
				auto plHdSet=FindPolygonFromVertex(vtHd1);
				for(auto plHd : plHdSet)
				{
					auto plVtHd=GetPolygonVertex(plHd);
					for(auto &v : plVtHd)
					{
						if(v==vtHd1)
						{
							v=vtHd0;
						}
					}
					SetPolygonVertex(plHd,plVtHd.size(),plVtHd.data());
				}
			}
		}
	}
}

void PolygonalMesh::StitchVertex(void)
{
	Lattice3d <std::vector <PolygonalMesh::VertexHandle> > ltc;
	YsVec3 bbx[2];

	GetBoundingBox(bbx);
	auto dgn=(bbx[1]-bbx[0]);
	auto lDgn=dgn.GetLength();
	bbx[0].SubX(lDgn/100.0);
	bbx[0].SubY(lDgn/100.0);
	bbx[0].SubZ(lDgn/100.0);
	bbx[1].AddX(lDgn/100.0);
	bbx[1].AddY(lDgn/100.0);
	bbx[1].AddZ(lDgn/100.0);
	ltc.Create(200,200,200,bbx[0],bbx[1]);

	for(auto vtHd=FindFirstVertex(); NullVertex()!=vtHd; vtHd=FindNextVertex(vtHd))
	{
		auto vtPos=GetVertexPosition(vtHd);
		auto blkIdx=ltc.GetBlockIndex(vtPos);
		if(ltc.IsInRange(blkIdx)==true)
		{
			ltc[blkIdx].push_back(vtHd);
		}
		else
		{
			printf("%s %d\n",__FUNCTION__,__LINE__);
		}
	}

	for(auto vtHd=FindFirstVertex(); NullVertex()!=vtHd; vtHd=FindNextVertex(vtHd))
	{
		if(0==FindPolygonFromVertex(vtHd).size())
		{
			continue;
		}

		auto vtPos=GetVertexPosition(vtHd);
		auto min=vtPos,max=vtPos;
		min.SubX(1e-6);
		min.SubY(1e-6);
		min.SubZ(1e-6);
		max.AddX(1e-6);
		max.AddY(1e-6);
		max.AddZ(1e-6);

		std::vector <PolygonalMesh::VertexHandle> matchingVtHd;

		auto minIdx=ltc.GetBlockIndex(min);
		auto maxIdx=ltc.GetBlockIndex(max);
		for(auto x=minIdx.x(); x<=maxIdx.x(); ++x)
		{
			for(auto y=minIdx.y(); y<=maxIdx.y(); ++y)
			{
				for(auto z=minIdx.z(); z<=maxIdx.z(); ++z)
				{
					YsVec3i blkIdx(x,y,z);
					if(true==ltc.IsInRange(blkIdx))
					{
						for(auto v : ltc[blkIdx])
						{
							if(GetVertexPosition(v)==GetVertexPosition(vtHd))
							{
								matchingVtHd.push_back(v);
							}
						}
						// matchingVtHd.insert(matchingVtHd.end(),ltc[blkIdx].begin(),ltc[blkIdx].end());
					}
				}
			}
		}

		PolygonalMesh::VertexHandle vtHd0=vtHd;

		for(auto vtHd1 : matchingVtHd)
		{
			if(vtHd0!=vtHd1)
			{
				auto plHdSet=FindPolygonFromVertex(vtHd1);
				for(auto plHd : plHdSet)
				{
					auto plVtHd=GetPolygonVertex(plHd);
					for(auto &v : plVtHd)
					{
						if(v==vtHd1)
						{
							v=vtHd0;
						}
					}
					SetPolygonVertex(plHd,plVtHd.size(),plVtHd.data());
				}
			}
		}
	}
}

void PolygonalMesh::GetBoundingBox(YsVec3 &min,YsVec3 &max) const
{
	if(0<GetNumVertex())
	{
		auto vtHd=FindFirstVertex();
		min=GetVertexPosition(vtHd);
		max=GetVertexPosition(vtHd);
		while(NullVertex()!=vtHd)
		{
			auto pos=GetVertexPosition(vtHd);
			min.SetX(std::min(pos.x(),min.x()));
			min.SetY(std::min(pos.y(),min.y()));
			min.SetZ(std::min(pos.z(),min.z()));
			max.SetX(std::max(pos.x(),max.x()));
			max.SetY(std::max(pos.y(),max.y()));
			max.SetZ(std::max(pos.z(),max.z()));
			vtHd=FindNextVertex(vtHd);
		}
	}
	else
	{
		min=YsVec3::Origin();
		max=YsVec3::Origin();
	}
}
void PolygonalMesh::GetBoundingBox(YsVec3 bbx[2]) const
{
	GetBoundingBox(bbx[0],bbx[1]);
}

long long int PolygonalMesh::GetNumVertex(void) const
{
	return vtxList.size();
}

PolygonalMesh::VertexHandle PolygonalMesh::FindFirstVertex(void) const
{
	VertexHandle vtHd;
	vtHd.iter=vtxList.begin();
	return vtHd;
}

PolygonalMesh::VertexHandle PolygonalMesh::FindNextVertex(VertexHandle vtHd) const
{
	if(vtxList.end()!=vtHd.iter)
	{
		++vtHd.iter;
		return vtHd;
	}
	return NullVertex();
}

PolygonalMesh::VertexHandle PolygonalMesh::AddVertex(const YsVec3 &pos)
{
	Vertex vtx;
	vtx.pos=pos;
	vtx.searchKey=searchKeySeed++;
	vtxList.push_back(vtx);

	VertexHandle vtHd;
	vtHd.iter=vtxList.end();
	--vtHd.iter;

	vtxSearch[vtx.searchKey]=vtHd;

	return vtHd;
}

void PolygonalMesh::DeleteVertex(VertexHandle vtHd)
{
	if(NullVertex()!=vtHd)
	{
		auto found=vtxSearch.find(GetSearchKey(vtHd));
		vtxSearch.erase(found);
		vtxList.erase(vtHd.iter);
	}
}

void PolygonalMesh::DeleteUnusedVertex(void)
{
	auto vtHd=FindFirstVertex();
	while(NullVertex()!=vtHd)
	{
		auto nextVtHd=FindNextVertex(vtHd);
		if(0==FindPolygonFromVertex(vtHd).size())
		{
			DeleteVertex(vtHd);
		}
		vtHd=nextVtHd;
	}
}

unsigned int PolygonalMesh::GetSearchKey(VertexHandle vtHd) const
{
	if(NullVertex()!=vtHd)
	{
		return vtHd.iter->searchKey;
	}
	return NullSearchKey;
}

PolygonalMesh::VertexHandle PolygonalMesh::FindVertex(unsigned int searchKey) const
{
	auto found=vtxSearch.find(searchKey);
	if(vtxSearch.end()!=found)
	{
		return found->second;
	}
	return NullVertex();
}

PolygonalMesh::VertexHandle PolygonalMesh::NullVertex(void) const
{
	VertexHandle vtHd;
	vtHd.iter=vtxList.end();
	return vtHd;
}

YsVec3 PolygonalMesh::GetVertexPosition(VertexHandle vtHd) const
{
	if(NullVertex()!=vtHd)
	{
		return vtHd.iter->pos;
	}
	else
	{
		return YsVec3::Origin();
	}
}

void PolygonalMesh::SetVertexPosition(VertexHandle vtHd,const YsVec3 &newPos)
{
	if(NullVertex()!=vtHd)
	{
		vtHd.iter->pos=newPos;
	}
}

long long int PolygonalMesh::GetNumPolygon(void) const
{
	return plgList.size();
}

PolygonalMesh::PolygonHandle PolygonalMesh::FindFirstPolygon(void) const
{
	PolygonHandle plHd;
	plHd.iter=plgList.begin();
	return plHd;
}

PolygonalMesh::PolygonHandle PolygonalMesh::FindNextPolygon(PolygonHandle plHd) const
{
	if(plgList.end()!=plHd.iter)
	{
		++plHd.iter;
		return plHd;
	}
	return NullPolygon();
}
PolygonalMesh::PolygonHandle PolygonalMesh::AddPolygon(long long int nVtx,const VertexHandle vtHdAry[])
{
	Polygon plg;
	plg.vtHdAry.resize(nVtx);
	for(int i=0; i<nVtx; ++i)
	{
		plg.vtHdAry[i]=vtHdAry[i];
	}
	plg.nom=YsVec3::Origin();
	plg.col.SetIntRGB(0,0,255);
	plg.searchKey=searchKeySeed++;

	plgList.push_back((Polygon &&)plg);

	PolygonHandle plHd;
	plHd.iter=plgList.end();
	--plHd.iter;

	plgSearch[plg.searchKey]=plHd;

	for(int i=0; i<nVtx; ++i)
	{
		vtxToPlg[GetSearchKey(vtHdAry[i])].push_back(plHd);
	}

	return plHd;
}
void PolygonalMesh::SetPolygonNormal(PolygonHandle plHd,const YsVec3 &nom)
{
	if(plHd!=NullPolygon())
	{
		plHd.iter->nom=nom;
	}
}

unsigned int PolygonalMesh::GetSearchKey(PolygonHandle plHd) const
{
	if(NullPolygon()!=plHd)
	{
		return plHd.iter->searchKey;
	}
	return NullSearchKey;
}

PolygonalMesh::PolygonHandle PolygonalMesh::FindPolygon(unsigned int searchKey) const
{
	auto found=plgSearch.find(searchKey);
	if(plgSearch.end()!=found)
	{
		return found->second;
	}
	return NullPolygon();
}

PolygonalMesh::PolygonHandle PolygonalMesh::NullPolygon(void) const
{
	PolygonHandle plHd;
	plHd.iter=plgList.end();
	return plHd;
}

void PolygonalMesh::SetPolygonVertex(PolygonHandle plHd,long long int nVtx,const VertexHandle vtHdAry[])
{
	{
		for(auto vtHd : GetPolygonVertex(plHd))
		{
			auto &plgSet=vtxToPlg[GetSearchKey(vtHd)];
			for(int i=plgSet.size()-1; 0<=i; --i)
			{
				if(plHd==plgSet[i])
				{
					plgSet[i]=plgSet.back();
					plgSet.pop_back();
				}
			}
		}
	}

	plHd.iter->vtHdAry.clear();
	for(int i=0; i<nVtx; ++i)
	{
		plHd.iter->vtHdAry.push_back(vtHdAry[i]);
		vtxToPlg[GetSearchKey(vtHdAry[i])].push_back(plHd);
	}
}

void PolygonalMesh::SetPolygonColor(PolygonHandle plHd,YsColor col)
{
	if(NullPolygon()!=plHd)
	{
		plHd.iter->col=col;
	}
}

YsColor PolygonalMesh::GetColor(PolygonHandle plHd) const
{
	if(NullPolygon()!=plHd)
	{
		return plHd.iter->col;
	}
	YsColor c;
	c.SetIntRGB(0,0,0);
	return c;
}

YsVec3 PolygonalMesh::GetCenter(PolygonHandle plHd) const
{
	YsVec3 cen=YsVec3::Origin();
	double div=0.0;
	for(auto vtHd : GetPolygonVertex(plHd))
	{
		cen+=GetVertexPosition(vtHd);
		div+=1.0;
	}
	return cen/div;
}

std::vector <PolygonalMesh::VertexHandle> PolygonalMesh::GetPolygonVertex(PolygonHandle plHd) const
{
	if(NullPolygon()!=plHd)
	{
		return plHd.iter->vtHdAry;
	}
	std::vector <PolygonalMesh::VertexHandle> empty;
	return empty;
}
YsVec3 PolygonalMesh::GetNormal(PolygonHandle plHd) const
{
	if(NullPolygon()!=plHd)
	{
		return plHd.iter->nom;
	}
	return YsVec3::Origin();
}

std::vector <PolygonalMesh::PolygonHandle> PolygonalMesh::FindPolygonFromVertex(VertexHandle vtHd) const
{
	auto found=vtxToPlg.find(GetSearchKey(vtHd));
	if(vtxToPlg.end()!=found)
	{
		return found->second;
	}
	std::vector <PolygonHandle> empty;
	return empty;
}

std::vector <PolygonalMesh::VertexHandle> PolygonalMesh::GetConnectedVertex(VertexHandle fromVtHd) const
{
	std::vector <VertexHandle> connVtHd;

	for(auto plHd : FindPolygonFromVertex(fromVtHd))
	{
		auto plVtHd=GetPolygonVertex(plHd);
		for(int i=0; i<plVtHd.size(); ++i)
		{
			if(plVtHd[(i+1)%plVtHd.size()]==fromVtHd ||
			   plVtHd[(i+plVtHd.size()-1)%plVtHd.size()]==fromVtHd)
			{
				if(connVtHd.end()==std::find(connVtHd.begin(),connVtHd.end(),plVtHd[i]))
				{
					connVtHd.push_back(plVtHd[i]);
				}
			}
		}
	}
	return connVtHd;
}

std::vector <PolygonalMesh::PolygonHandle> PolygonalMesh::FindPolygonFromEdgePiece(VertexHandle edVtHd0,VertexHandle edVtHd1) const
{
	std::vector <PolygonHandle> usingPlHd;

	for(auto plHd : FindPolygonFromVertex(edVtHd0))
	{
		auto plVtHd=GetPolygonVertex(plHd);
		if(plVtHd.end()!=std::find(plVtHd.begin(),plVtHd.end(),edVtHd1))
		{
			for(int i=0; i<plVtHd.size(); ++i)
			{
				if((plVtHd[i]==edVtHd0 && plVtHd[(i+1)%plVtHd.size()]==edVtHd1) ||
				   (plVtHd[i]==edVtHd1 && plVtHd[(i+1)%plVtHd.size()]==edVtHd0))
				{
					usingPlHd.push_back(plHd);
					break;
				}
			}
		}
	}

	return usingPlHd;
}

PolygonalMesh::PolygonHandle PolygonalMesh::GetNeighborPolygon(PolygonHandle plHd,int edIdx) const
{
	auto plVtHd=GetPolygonVertex(plHd);
	if(0<=edIdx && edIdx<plVtHd.size())
	{
		auto usingPlHd=FindPolygonFromEdgePiece(plVtHd[edIdx],plVtHd[(edIdx+1)%plVtHd.size()]);
		if(2==usingPlHd.size())
		{
			if(usingPlHd[0]==plHd)
			{
				return usingPlHd[1];
			}
			else
			{
				return usingPlHd[0];
			}
		}
	}

	return NullPolygon();
}
