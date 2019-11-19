#include "hashset.h"
#include "hashtable.h"

#include <stdio.h>
#include <string>



template <>
HashCommon::CodeType HashBase<std::string>::HashCode(const std::string &key) const
{
	HashCommon::CodeType c=0;
	unsigned int prime[]={1,3,5,7,11};
	int ctr=0;
	for(auto x : key)
	{
		c+=(x*prime[ctr%5]);
		++ctr;
	}
	return c;
}


void TestHashSet(void)
{
	printf("Testing Hash Set\n");

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
		auto keyPtr=stringSet[hd];
		printf("Key: %s\n",keyPtr->data());
	}
}

void TestHashTable(void)
{
	printf("Testing Hash Table\n");

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

	auto *nickNamePtr=stringSet["F-22"];
	if(nullptr!=nickNamePtr)
	{
		printf("Nickname for F-22 is %s\n",nickNamePtr->data());
	}
	else
	{
		printf("Not found.\n");
	}

	nickNamePtr=stringSet["**AA&*)(FS)"];
	if(nullptr!=nickNamePtr)
	{
		printf("Found for **AA&*)(FS) %s\n",nickNamePtr->data());
	}
	else
	{
		printf("Not found.\n");
	}


	for(auto hd=stringSet.First(); true==stringSet.IsNotNull(hd); hd=stringSet.Next(hd))
	{
		auto &key=stringSet.GetKey(hd);
		auto &value=stringSet.GetValue(hd);
		printf("Key: %s  Value %s\n",key.data(),value.data());
	}
}

int main(void)
{
	TestHashSet();
	TestHashTable();

	printf("End of program.\n");
	return 0;
}
