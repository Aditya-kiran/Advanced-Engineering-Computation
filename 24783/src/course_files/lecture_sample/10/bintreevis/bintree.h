#ifndef BINTREE_H_IS_INCLUDED
#define BINTREE_H_IS_INCLUDED

#include <algorithm>

template <class KeyClass,class ValueClass>
class BinaryTree
{
private:
	BinaryTree(const BinaryTree <KeyClass,ValueClass> &incoming);
	BinaryTree <KeyClass,ValueClass> &operator=(const BinaryTree <KeyClass,ValueClass> &incoming);

protected:
	class Node
	{
	public:
		KeyClass key;
		ValueClass value;
		Node *up,*left,*right;
		int height;
		Node()
		{
			up=nullptr;
			left=nullptr;
			right=nullptr;
			height=1;
		}
	};
public:
	class NodeHandle
	{
	friend BinaryTree <KeyClass,ValueClass>;
	private:
		Node *ptr;
	public:
		inline void Nullify(void)
		{
			ptr=nullptr;
		}
		inline bool IsNull(void) const
		{
			return nullptr==ptr;
		}
		inline bool IsNotNull(void) const
		{
			return nullptr!=ptr;
		}
		inline bool operator==(NodeHandle hd) const
		{
			return this->ptr==hd.ptr;
		}
		inline bool operator!=(NodeHandle hd) const
		{
			return this->ptr!=hd.ptr;
		}
		inline bool operator==(std::nullptr_t) const
		{
			return this->ptr==nullptr;
		}
		inline bool operator!=(std::nullptr_t) const
		{
			return this->ptr!=nullptr;
		}
	};
protected:
	Node *GetNode(NodeHandle ndHd)
	{
		return ndHd.ptr;
	}
	const Node *GetNode(NodeHandle ndHd) const
	{
		return ndHd.ptr;
	}
	static NodeHandle MakeHandle(Node *nodePtr)
	{
		NodeHandle hd;
		hd.ptr=nodePtr;
		return hd;
	}
private:
	Node *root;
	long long int nElem;

public:
	BinaryTree()
	{
		nElem=0;
		root=nullptr;
	}
	~BinaryTree()
	{
		CleanUp();
	}
	void CleanUp(void)
	{
		DeleteNode(root);
		root=nullptr;
		nElem=0;
	}
private:
	void DeleteNode(Node *ptr)
	{
		if(nullptr!=ptr)
		{
			DeleteNode(ptr->left);
			DeleteNode(ptr->right);
			delete ptr;
		}
	}

public:
	static NodeHandle Null(void)
	{
		return MakeHandle(nullptr);
	}
	NodeHandle RootNode(void) const
	{
		return MakeHandle(root);
	}
	NodeHandle Left(NodeHandle ndHd) const
	{
		auto ptr=GetNode(ndHd);
		if(nullptr!=ptr)
		{
			return MakeHandle(ptr->left);
		}
		return Null();
	}
	NodeHandle Up(NodeHandle ndHd) const
	{
		auto ptr=GetNode(ndHd);
		if(nullptr!=ptr)
		{
			return MakeHandle(ptr->up);
		}
		return Null();
	}
	NodeHandle Right(NodeHandle ndHd) const
	{
		auto ptr=GetNode(ndHd);
		if(nullptr!=ptr)
		{
			return MakeHandle(ptr->right);
		}
		return Null();
	}

	long long int GetN(void) const
	{
		return nElem;
	}
	const KeyClass &GetKey(NodeHandle ndHd) const
	{
		auto ptr=GetNode(ndHd);
		return ptr->key;
	}
	ValueClass &GetValue(NodeHandle ndHd)
	{
		auto ptr=GetNode(ndHd);
		return ptr->value;
	}
	const ValueClass &GetValue(NodeHandle ndHd) const
	{
		auto ptr=GetNode(ndHd);
		return ptr->value;
	}
	NodeHandle FindNode(const KeyClass &key) const
	{
		for(auto ptr=root; nullptr!=ptr; )
		{
			if(key==ptr->key)
			{
				return MakeHandle(ptr);
			}
			else if(key<ptr->key)
			{
				ptr=ptr->left;
			}
			else // if(ptr->key<key)
			{
				ptr=ptr->right;
			}
		}
		return Null();
	}
	bool IsKeyIncluded(const KeyClass &key) const
	{
		return Null()!=FindNode(key);
	}

	NodeHandle Insert(const KeyClass &key,const ValueClass &value)
	{
		auto newNode=new Node;
		newNode->key=key;
		newNode->value=value;
		++nElem;
		if(nullptr==root)
		{
			root=newNode;
		}
		else
		{
			for(auto ptr=root; nullptr!=ptr; )
			{
				if(key<ptr->key)
				{
					if(nullptr!=ptr->left)
					{
						ptr=ptr->left;
					}
					else
					{
						ptr->left=newNode;
						newNode->up=ptr;
						break;
					}
				}
				else
				{
					if(nullptr!=ptr->right)
					{
						ptr=ptr->right;
					}
					else
					{
						ptr->right=newNode;
						newNode->up=ptr;
						break;
					}
				}
			}
		}
		UpdateHeightCascade(newNode);
		return MakeHandle(newNode);
	}


	void Delete(NodeHandle hd)
	{
		auto upHd=Up(hd);

		if(Null()==hd)
		{
			return;
		}
		else if(true==SimpleDetach(hd))
		{
			// Easy case
			auto ptr=GetNode(hd);
			delete ptr;
			--nElem;
			UpdateHeightCascade(GetNode(upHd));
		}
		else
		{
			auto rmol=RMOL(hd);
			NodeHandle upOfRmol=Up(rmol);

			if(true==SimpleDetach(rmol))
			{
				auto ptr=GetNode(hd);
				auto rmolPtr=GetNode(rmol);

				rmolPtr->up=ptr->up;
				rmolPtr->left=ptr->left;
				rmolPtr->right=ptr->right;

				if(nullptr!=rmolPtr->up)
				{
					if(ptr->up->right==ptr)
					{
						ptr->up->right=rmolPtr;
					}
					else // if(ptr->up->left==ptr)
					{
						ptr->up->left=rmolPtr;
					}
				}
				else
				{
					root=rmolPtr;
				}

				if(nullptr!=rmolPtr->left)
				{
					rmolPtr->left->up=rmolPtr;
				}
				if(nullptr!=rmolPtr->right)
				{
					rmolPtr->right->up=rmolPtr;
				}

				delete ptr;
				--nElem;

				UpdateHeightCascade(GetNode(upOfRmol));
				UpdateHeightCascade(GetNode(upHd));
			}
			else
			{
				printf("RMOL node could not be detached!\n");
			}
		}
	}
private:
	bool SimpleDetach(NodeHandle hd)
	{
		auto ptr=GetNode(hd);
		if(nullptr==ptr->left && nullptr==ptr->right)
		{
			if(nullptr==ptr->up)
			{
				root=nullptr;
			}
			else if(ptr->up->right==ptr)
			{
				ptr->up->right=nullptr;
			}
			else if(ptr->up->left==ptr)
			{
				ptr->up->left=nullptr;
			}
			ptr->up=nullptr;
			return true;
		}
		else if(nullptr==ptr->left || nullptr==ptr->right)
		{
			Node *subTree=nullptr;
			if(nullptr!=ptr->left)
			{
				subTree=ptr->left;
			}
			else // if(nullptr!=ptr->right)
			{
				subTree=ptr->right;
			}

			if(nullptr!=ptr->up)
			{
				if(ptr->up->right==ptr)
				{
					ptr->up->right=subTree;
				}
				else // if(ptr->up->left==ptr)
				{
					ptr->up->left=subTree;
				}
			}
			else // if(nullptr==ptr->up)
			{
				root=subTree;
			}
			subTree->up=ptr->up;
			ptr->up=nullptr;
			ptr->left=nullptr;
			ptr->right=nullptr;
			return true;
		}
		return false;
	}

	NodeHandle RMOL(NodeHandle hd)
	{
		if(Null()==hd)
		{
			return Null();
		}
		else
		{
			for(hd=Left(hd); Null()!=hd && Null()!=Right(hd); hd=Right(hd))
			{
			}
			return hd;
		}
	}

public:
	void MoveFrom(BinaryTree <KeyClass,ValueClass> &incoming)
	{
		if(&incoming!=this)
		{
			this->CleanUp();
			this->nElem=incoming.nElem;
			this->root=incoming.root;
			incoming.nElem=0;
			incoming.root=nullptr;
		}
	}

	NodeHandle FindFirst(void) const
	{
		return LeftMostOf(MakeHandle(root));
	}

	NodeHandle FindNext(NodeHandle hd) const
	{
		if(true==hd.IsNotNull())
		{
			if(true==Right(hd).IsNotNull())
			{
				return LeftMostOf(Right(hd));
			}
			else
			{
				while(true==hd.IsNotNull())
				{
					auto up=Up(hd);
					if(true==up.IsNotNull() && Left(up)==hd)
					{
						return up;
					}
					hd=up;
				}
			}
		}
		return Null();
	}

private:
	NodeHandle LeftMostOf(NodeHandle hd) const
	{
		for(; true==hd.IsNotNull(); hd=this->Left(hd))
		{
			if(true==Left(hd).IsNull())
			{
				return hd;
			}
		}
		return Null();
	}
public:
	// You implement the following in the assignment.
	NodeHandle Last(void) const;  // Do it in the assignment.
	NodeHandle FindPrev(NodeHandle ndHd) const;  // Do it in the assignment.

public:
	bool RotateLeft(NodeHandle hdA)
	{
		auto hdB=Right(hdA);
		if(hdB==nullptr)
		{
			return false;
		}
		auto hdC=Left(hdB);

		auto A=GetNode(hdA);
		auto B=GetNode(hdB);
		auto C=GetNode(hdC);

		if(nullptr==A->up)
		{
			root=B;
		}
		else
		{
			if(A->up->left==A)
			{
				A->up->left=B;
			}
			else // if(A->up->right==A)
			{
				A->up->right=B;
			}
		}
		B->up=A->up;


		B->left=A;
		A->up=B;

		A->right=C;
		if(nullptr!=C)
		{
			C->up=A;
		}

		UpdateHeightCascade(A);

		return true;
	}

private:
	bool UpdateHeight(Node *ptr)
	{
		int heightL=GetHeight(ptr->left);
		int heightR=GetHeight(ptr->right);
		auto newHeight=std::max(heightL,heightR)+1;

		if(newHeight!=ptr->height)
		{
			ptr->height=newHeight;
			return true;
		}
		return false;
	}
	void UpdateHeightCascade(Node *ptr)
	{
		UpdateHeight(ptr);
		ptr=ptr->up;
		while(nullptr!=ptr && true==UpdateHeight(ptr))
		{
			ptr=ptr->up;
		}
	}
	int GetHeight(Node *ptr) const
	{
		if(ptr!=nullptr)
		{
			return ptr->height;
		}
		else
		{
			return 0;
		}
	}

public:
	int GetHeight(NodeHandle hd) const
	{
		if(hd!=nullptr)
		{
			return GetNode(hd)->height;
		}
		else
		{
			return 0;
		}
	}

};

#endif