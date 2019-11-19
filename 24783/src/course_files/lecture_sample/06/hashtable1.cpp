#include <vector>
#include <string>

#include <stdio.h>



template <class KeyType,class ValueType>
class HashTable
{
public:
	typedef unsigned int CodeType;

	class Entry
	{
	public:
		CodeType hashCode;
		KeyType hashKey;
		ValueType value;
	};

private:
	std::vector <std::vector <Entry> > set;

public:
	HashTable()
	{
		set.resize(7);
	}
	~HashTable()
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

	void Add(const KeyType &key,const ValueType &value)
	{
		if(true!=IsIncluded(key))
		{
			auto code=CalcHashCode(key);
			auto row=code%set.size();

			Entry ent;
			ent.hashCode=code;
			ent.hashKey=key;
			ent.value=value;
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

	ValueType *Find(const KeyType &key)
	{
		auto code=CalcHashCode(key);
		auto row=code%set.size();
		for(auto &x : set[row])
		{
			if(code==x.hashCode && key==x.hashKey)
			{
				return &x.value;
			}
		}
		return nullptr;
	}
	const ValueType *Find(const KeyType &key) const
	{
		auto code=CalcHashCode(key);
		auto row=code%set.size();
		for(const auto &x : set[row])
		{
			if(code==x.hashCode && key==x.hashKey)
			{
				return &x.value;
			}
		}
		return nullptr;
	}
};

template <>
typename HashTable<std::string,std::string>::CodeType HashTable<std::string,std::string>::CalcHashCode(const std::string &key)
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
	HashTable <std::string,std::string> stringSet;

	stringSet.Add("F-4","PhantomII");
	stringSet.Add("F-5","Tiger");
	stringSet.Add("F-8","Crusader");
	stringSet.Add("F-14","Tomcat");
	stringSet.Add("F-15","Eagle");
	stringSet.Add("F-16","Falcon");
	stringSet.Add("F-18","Hornet");
	stringSet.Add("F-22","Raptor");
	stringSet.Add("F-35","LightningII");

	auto *nickNamePtr=stringSet.Find("F-22");
	if(nullptr!=nickNamePtr)
	{
		printf("Nickname for F-22 is %s\n",nickNamePtr->data());
	}
	else
	{
		printf("Not found.\n");
	}

	nickNamePtr=stringSet.Find("**AA&*)(FS)");
	if(nullptr!=nickNamePtr)
	{
		printf("Found for **AA&*)(FS) %s\n",nickNamePtr);
	}
	else
	{
		printf("Not found.\n");
	}

	printf("End of program.\n");
	return 0;
}

