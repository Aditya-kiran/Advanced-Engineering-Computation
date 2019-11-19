#include "hashset.h"
#include "hashtable.h"
#include "simplebitmap.h"
template <class SimpleBitmap>
HashCommon::CodeType HashBase<SimpleBitmap>::HashCode(const SimpleBitmap &key) const {
	return key.HashKey();
}
template <>
HashCommon::CodeType HashBase<int>::HashCode(const int &key) const {
	return key;
}
