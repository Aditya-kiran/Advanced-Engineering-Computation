#include <vector>
#include <string>

#include <stdio.h>



template <class KeyType>
class HashSet
{
public:
	typedef unsigned int CodeType;

	class EnumHandle
	{
	public:
		long long int rowIdx,columnIdx;
	};

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

	EnumHandle First(void) const
	{
		EnumHandle hd;
		hd.rowIdx=-1;
		hd.columnIdx=-1;

		for(long long int row=0; row<set.size(); ++row)
		{
			if(0<set[row].size())  // if(!set[row].empty())
			{
				hd.rowIdx=row;
				hd.columnIdx=0;
				break;
			}
		}

		return hd;
	}
	bool IsNotNull(EnumHandle hd) const
	{
		if(0<=hd.rowIdx && 0<=hd.columnIdx)
		{
			return true;
		}
		return false;
	}

	EnumHandle Next(EnumHandle hd) const
	{
		if(true==IsNotNull(hd))
		{
			if(hd.columnIdx+1<set[hd.rowIdx].size())
			{
				++hd.columnIdx;
				return hd;
			}

			for(int row=hd.rowIdx+1; row<set.size(); ++row)
			{
				if(0<set[row].size())
				{
					hd.rowIdx=row;
					hd.columnIdx=0;
					return hd;
				}
			}
		}
		hd.rowIdx=-1;
		hd.columnIdx=-1;
		return hd;
	}

	const KeyType &GetKey(EnumHandle hd) const
	{
		return set[hd.rowIdx][hd.columnIdx].hashKey;
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


	for(auto hd=stringSet.First(); true==stringSet.IsNotNull(hd); hd=stringSet.Next(hd))
	{
		auto &key=stringSet.GetKey(hd);
		printf("Key: %s\n",key.data());
	}



	printf("End of program.\n");
	return 0;
}

