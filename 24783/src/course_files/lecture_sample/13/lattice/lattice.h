#ifndef LATTICE_IS_INCLUDED
#define LATTICE_IS_INCLUDED

#include <ysclass.h>
#include <vector>

template <class T>
class Lattice3d
{
protected:
	int nx,ny,nz;
	std::vector <T> elem;
	YsVec3 min,max;
public:
	/*! Create a lattice with nx*ny*nz blocks.  To store nodal information, the length of the
	    storage actually allocated will be (nx+1)*(ny+1)*(nz+1).
	*/
	void Create(int nx,int ny,int nz,const YsVec3 &min,const YsVec3 &max)
	{
		elem.clear();
		elem.resize((nx+1)*(ny+1)*(nz+1));
		this->min=min;
		this->max=max;
		this->nx=nx;
		this->ny=ny;
		this->nz=nz;
	}

	/*! Returns number of blocks in X,Y, and Z direction. */
	YSSIZE_T Nx(void) const
	{
		return nx;
	}
	YSSIZE_T Ny(void) const
	{
		return ny;
	}
	YSSIZE_T Nz(void) const
	{
		return nz;
	}

	/*! Returns the dimension of one block. */
	YsVec3 GetBlockDimension(void) const
	{
		auto D=max-min;
		D.DivX((double)nx);
		D.DivY((double)ny);
		D.DivZ((double)nz);
		return D;
	}

	/*! Returns the minimum (x,y,z) of the block at (bx,by,bz). */
	YsVec3 GetBlockPosition(int ix,int iy,int iz) const
	{
		auto d=GetBlockDimension();
		auto p=min;
		p.AddX((double)ix*d.x());
		p.AddY((double)iy*d.y());
		p.AddZ((double)iz*d.z());
		return p;
	}

	/*! Returns the index of the block that encloses the given position. */
	YsVec3i GetBlockIndex(const YsVec3 &pos) const
	{
		auto d=GetBlockDimension();
		auto off=pos-min;
		off.DivX(d.x());
		off.DivY(d.y());
		off.DivZ(d.z());

		YsVec3i idx;
		idx.SetX((int)off.x());
		idx.SetY((int)off.y());
		idx.SetZ((int)off.z());

		return idx;
	}

	/*! Returns if the block index is within the valid range.
	    The lattice elements can be nodal value or cell value.  To support the nodal values,
	    this class allocates (nx+1)*(ny+1)*(nz+1) elems.  Therefore, the index is valid
	    and this function returns true, if:
	       0<=idx.x() && idx.x()<=nx && 0<=idx.y() && idx.y()<=ny && 0<=idx.z() && idx.z()<=nz.
	*/
	bool IsInRange(const YsVec3i idx) const
	{
		return (0<=idx.x() && idx.x()<=nx && 0<=idx.y() && idx.y()<=ny && 0<=idx.z() && idx.z()<=nz);
	}

	/*! Returns a reference to the lattice element at the index. */
	T &operator[](const YsVec3i idx)
	{
		return elem[idx.z()*(nx+1)*(ny+1)+idx.y()*(nx+1)+idx.x()];
	}
	const T &operator[](const YsVec3i idx) const
	{
		return elem[idx.z()*(nx+1)*(ny+1)+idx.y()*(nx+1)+idx.x()];
	}
};

#endif
