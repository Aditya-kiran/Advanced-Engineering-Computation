#include <stdio.h>
#include <stdlib.h>

#include <vector>



template <class T>
class SimpleHashSet
{
private:
	std::vector <std::vector <T> > set;
public:
	SimpleHashSet()
	{
		set.resize(7);
	}
	~SimpleHashSet()
	{
		CleanUp();
	}
	void CleanUp(void)
	{
		set.clear();
	}

	bool IsIncluded(T incoming)
	{
		int row=incoming%set.size();
		for(auto x : set[row])
		{
			if(x==incoming)
			{
				return true;
			}
		}
		return false;
	}
	void Add(T incoming)
	{
		if(true!=IsIncluded(incoming))
		{
			int row=incoming%set.size();
			set[row].push_back(incoming);
		}
	}
	void Delete(T toDel)
	{
		int row=incoming%set.size();
		for(int i=0; i<set[row].size(); ++i)
		{
			if(set[row][i]==toDel)
			{
				set[row][i]=set[row].back();
				set[row].pop_back();
			}
		}
	}
};


int main(void)
{
	srand(1234);

	SimpleHashSet <int> used;
	int r[20];
	for(int i=0; i<sizeof(r)/sizeof(int); ++i)
	{
	RETRY:
		auto x=rand()%20;
		if(true!=used.IsIncluded(x))
		{
			r[i]=x;
			used.Add(x);
		}
		else
		{
			goto RETRY;
		}
	}

	for(auto x : r)
	{
		printf("%d\n",x);
	}

	return 0;
}
