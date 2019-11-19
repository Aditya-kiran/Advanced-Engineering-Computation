#ifndef HASHTABLE_IS_INCLUDED
#define HASHTABLE_IS_INCLUDED
/* { */

#include <vector>
#include <stdio.h>

#include "hashbase.h"



////////////////////////////////////////////////////////////

template <class KeyType,class ValueType>
class HashTable : public HashCommon, public HashBase <KeyType>
{
private:
	class Entry
	{
	public:
		CodeType hashCode;
		KeyType hashKey;
		ValueType value;
	};
	std::vector <std::vector <Entry> > table;

public:
	using HashBase <KeyType>::HashCode;

	HashTable()
	{
		table.resize(MINIMUM_TABLE_SIZE);
	}
	~HashTable()
	{
		CleanUp();
	}
	void CleanUp(void)
	{
		HashCommon::CleanUp(table);
	}

	void Add(const KeyType &key,const ValueType &value)
	{
		auto hashCode=HashCode(key);
		if(true!=HashCommon::IsIncluded(table,key,hashCode))
		{
			auto row=hashCode%table.size();
			Entry ent;
			ent.hashCode=hashCode;
			ent.hashKey=key;
			ent.value=value;
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
	const KeyType &GetKey(Handle hd) const
	{
		return table[hd.row][hd.column].hashKey;
	}
	const ValueType &GetValue(Handle hd) const
	{
		return table[hd.row][hd.column].value;
	}

	ValueType *Find(const KeyType &key)
	{
		auto code=HashCode(key);
		auto row=code%table.size();
		for(auto &x : table[row])
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
		auto code=HashCode(key);
		auto row=code%table.size();
		for(auto &x : table[row])
		{
			if(code==x.hashCode && key==x.hashKey)
			{
				return &x.value;
			}
		}
		return nullptr;
	}

	ValueType *operator[](const KeyType &key)
	{
		return Find(key);
	}
	const ValueType *operator[](const KeyType &key) const
	{
		return Find(key);
	}
};

/* } */
#endif
