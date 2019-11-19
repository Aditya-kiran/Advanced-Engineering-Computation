#include <stdio.h>
#include <stdlib.h>
#include <time.h>


template <class KeyType>
class BinaryTree
{
public:
	class Node
	{
	public:
		KeyType key;
		Node *up,*left,*right;
		Node()
		{
			up=nullptr;
			left=nullptr;
			right=nullptr;
		}
	};

private:
	Node *root;

public:
	BinaryTree()
	{
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
	Node *Add(const KeyType &key)
	{
		auto newNode=new Node;
		newNode->key=key;
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
		return newNode;
	}
	const Node *FindFirst(void) const
	{
		return LeftMostOf(root);
	}
	const Node *FindNext(const Node *ptr) const
	{
		if(nullptr!=ptr)
		{
			if(nullptr!=ptr->right)
			{
				return LeftMostOf(ptr->right);
			}
			else
			{
				while(nullptr!=ptr)
				{
					auto up=ptr->up;
					if(nullptr!=up && up->left==ptr)
					{
						return up;
					}
					ptr=ptr->up;
				}
			}
		}
		return nullptr;
	}
	const Node *LeftMostOf(const Node *ptr) const
	{
		for(; nullptr!=ptr; ptr=ptr->left)
		{
			if(nullptr==ptr->left)
			{
				return ptr;
			}
		}
		return nullptr;
	}
};


int main(void)
{
	BinaryTree <int> tree;

	srand((int)time(nullptr));

	for(int i=0; i<10; ++i)
	{
		int r=rand()%100;
		printf("Adding: %d\n",r);
		tree.Add(r);
	}

	for(const BinaryTree <int>::Node *ptr=tree.FindFirst(); nullptr!=ptr; ptr=tree.FindNext(ptr))
	{
		printf("Sorted: %d\n",ptr->key);
	}

	return 0;
}
