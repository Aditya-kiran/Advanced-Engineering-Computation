


template <class T>
class BinTree
{
public:
	class Node
	{
	public:
		T value;
		Node *up,*left,*right;
	};

private:
	Node *root;

public:
	BinTree()
	{
		root=nullptr;
	}
	~BinTree()
	{
		CleanUp();
	}
	void CleanUp(void)
	{
		Delete(root);
	}
private:
	void Delete(Node *ptr)
	{
		if(nullptr!=ptr)
		{
			Delete(ptr->left);
			Delete(ptr->right);
			delete ptr;
		}
	}
public:
	void Add(const T &incoming)
	{
		auto *newNode=new Node;
		newNode->value=incoming;

		if(nullptr==root)
		{
			root=newNode;
		}
		else
		{
			auto ptr=root;
			for(;;)
			{
				if(newNode->value<ptr->value)
				{
					if(nullptr==ptr->left)
					{
						ptr->left=newNode;
						newNode->up=ptr;
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
						newNode->up=ptr;
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
	const Node *First(void) const
	{
		for(auto *ptr=root; nullptr!=ptr; ptr=ptr->left)
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
	BinTree <int> x;
	return 0;
}
