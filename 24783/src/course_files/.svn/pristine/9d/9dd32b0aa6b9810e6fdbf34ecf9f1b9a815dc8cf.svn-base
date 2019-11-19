#include <vector>
#include <string>

#include <stdio.h>



template <class KeyType>
class HashSet
{
public:
	typedef unsigned int CodeType;

	class Entry
	{
	public:
		CodeType hashCode;
		KeyType hashKey;
	};

private:
	std::vector <std::vector <Entry> > set;

public:
	HashSet()
	{
		set.resize(7);
	}
	~HashSet()
	{
		CleanUp();
	}
	void CleanUp(void)
	{
		set.clear();
	}

	CodeType CalcHashCode(const KeyType &key);

	bool IsIncluded(const KeyType &key)
	{
		auto code=CalcHashCode(key);
		auto row=code%set.size();
		for(const auto &x : set[row])
		{
			if(code==x.hashCode && key==x.hashKey)
			{
				return true;
			}
		}
		return false;
	}

	void Add(const KeyType &key)
	{
		if(true!=IsIncluded(key))
		{
			auto code=CalcHashCode(key);
			auto row=code%set.size();

			Entry ent;
			ent.hashCode=code;
			ent.hashKey=key;
			set[row].push_back((Entry &&)ent);
		}
	}
	void Delete(const KeyType &key)
	{
		auto code=CalcHashCode(key);
		auto row=code%set.size();
		for(auto &x : set[row])
		{
			if(code==x.hashCode && key==x.hashKey)
			{
				std::swap(x,set[row].back());
				set[row].pop_back();
				return;
			}
		}
	}
};

template <>
HashSet<std::string>::CodeType HashSet<std::string>::CalcHashCode(const std::string &key)
{
	CodeType c=0;
	unsigned int prime[]={1,3,5,7,11};
	int ctr=0;
	for(auto x : key)
	{
		c+=(x*prime[ctr%5]);
		++ctr;
	}
	return c;
}

int main(void)
{
	HashSet <std::string> stringSet;

	stringSet.Add("Phantom");
	stringSet.Add("Tiger");
	stringSet.Add("Crusader");
	stringSet.Add("Tomcat");
	stringSet.Add("Eagle");
	stringSet.Add("Falcon");
	stringSet.Add("Hornet");
	stringSet.Add("Raptor");
	stringSet.Add("LightningII");

	if(true==stringSet.IsIncluded("Tomcat"))
	{
		printf("Tomcat included.\n");
	}
	if(true==stringSet.IsIncluded("19827401"))
	{
		printf("19827401 included.\n");
	}

	if(true==stringSet.IsIncluded("Phantom"))
	{
		printf("Phantom included.\n");
	}
	stringSet.Delete("Phantom");
	if(true==stringSet.IsIncluded("Phantom"))
	{
		printf("Phantom still included.\n");
	}
	else
	{
		printf("Phantom retired.\n");
	}


	printf("End of program.\n");
	return 0;
}

