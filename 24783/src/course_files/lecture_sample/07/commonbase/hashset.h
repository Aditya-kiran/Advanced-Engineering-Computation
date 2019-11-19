#ifndef HASHSET_IS_INCLUDED
#define HASHSET_IS_INCLUDED
/* { */

#include <vector>
#include <stdio.h>

#include "hashbase.h"



////////////////////////////////////////////////////////////

template <class KeyType>
class HashSet : public HashCommon, public HashBase <KeyType>
{
private:
	class Entry
	{
	public:
		CodeType hashCode;
		KeyType hashKey;
	};
	std::vector <std::vector <Entry> > table;

public:
	using HashBase <KeyType>::HashCode;

	HashSet()
	{
		table.resize(MINIMUM_TABLE_SIZE);
	}
	~HashSet()
	{
		CleanUp();
	}
	void CleanUp(void)
	{
		HashCommon::CleanUp(table);
	}

	void Add(const KeyType &key)
	{
		auto hashCode=HashCode(key);
		if(true!=HashCommon::IsIncluded(table,key,hashCode))
		{
			auto row=hashCode%table.size();
			Entry ent;
			ent.hashCode=hashCode;
			ent.hashKey=key;
			table[row].push_back((Entry &&)ent);
			++nElem;
		}
	}
	bool IsIncluded(const KeyType &key) const
	{
		return HashCommon::IsIncluded(table,key,HashCode(key));
	}
	void SetSize(long long int tableSize);
	void Resize(long long int tableSize);

	void Delete(const KeyType &key)
	{
		HashCommon::Delete(table,key,HashCode(key));
	}

	Handle First(void) const
	{
		return HashCommon::First(table);
	}
	Handle Next(Handle hd) const
	{
		return HashCommon::Next(table,hd);
	}
	const KeyType *operator[](Handle hd) const
	{
		if(true==IsNotNull(hd))
		{
			return &table[hd.row][hd.column].hashKey;
		}
		return nullptr;
	}
};

/* } */
#endif
