#include <stdio.h>
#include <stdlib.h>
#include <time.h>



class BinTreeNode
{
public:
	int i;
	BinTreeNode *parent,*left,*right;

	BinTreeNode()
	{
		parent=nullptr;
		left=nullptr;
		right=nullptr;
	}
};

void Print(BinTreeNode *ptr)
{
	if(nullptr!=ptr)
	{
		Print(ptr->left);
		printf("%d\n",ptr->i);
		Print(ptr->right);
	}
}

const BinTreeNode *FirstNode(const BinTreeNode *ptr)
{
	while(nullptr!=ptr && nullptr!=ptr->left)
	{
		ptr=ptr->left;
	}
	return ptr;
}

const BinTreeNode *FindNext(const BinTreeNode *ptr)
{
	if(nullptr==ptr)
	{
		return ptr;
	}
	else if(nullptr!=ptr->right)
	{
		return FirstNode(ptr->right);
	}
	else
	{
		while(nullptr!=ptr)
		{
			auto up=ptr->parent;
			if(nullptr!=up && up->left==ptr)
			{
				return up;
			}
			ptr=up;
		}
		return nullptr;
	}
}

int main(void)
{
	BinTreeNode *root=nullptr;

	srand((int)time(nullptr));

	for(int k=0; k<20; ++k)
	{
		auto *newNode=new BinTreeNode;
		newNode->i=rand()%100;

		if(nullptr==root)
		{
			root=newNode;
		}
		else
		{
			auto ptr=root;
			for(;;)
			{
				if(newNode->i<ptr->i)
				{
					if(nullptr==ptr->left)
					{
						ptr->left=newNode;
						newNode->parent=ptr;
						break;
					}
					else
					{
						ptr=ptr->left;
					}
				}
				else // if(ptr->i<=newNode->i)
				{
					if(nullptr==ptr->right)
					{
						ptr->right=newNode;
						newNode->parent=ptr;
						break;
					}
					else
					{
						ptr=ptr->right;
					}
				}
			}
		}
	}

	// Print(root);

	auto iter=FirstNode(root);
	while(nullptr!=iter)
	{
		printf("%d\n",iter->i);
		iter=FindNext(iter);
	}

	return 0;
}
