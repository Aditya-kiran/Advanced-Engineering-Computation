#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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
		Node()
		{
			up=nullptr;
			left=nullptr;
			right=nullptr;
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
		return MakeHandle(newNode);
	}

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
};



int main(void)
{
	BinaryTree <int,int> tree;

	srand((int)time(nullptr));

	for(int i=0; i<10; ++i)
	{
		int r=rand()%100;
		printf("Adding: %d, %d\n",r,123*r);
		tree.Insert(r,123*r);
	}

printf("%s %d\n",__FUNCTION__,__LINE__);
	for(auto hd=tree.FindFirst(); hd!=nullptr; hd=tree.FindNext(hd))
	{
		printf("Sorted: %d\n",tree.GetKey(hd));
	}

	for(int i=0; i<100; ++i)
	{
		auto found=tree.FindNode(i);
		if(found!=nullptr)
		{
			printf("%d -> %d\n",tree.GetKey(found),tree.GetValue(found));
		}
	}

	return 0;
}
