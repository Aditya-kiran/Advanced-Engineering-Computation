#include <unordered_map>



class CollapseCandidate
{
public:
	unsigned int v[2];
};

bool operator==(const CollapseCandidate &c1,const CollapseCandidate &c2)
{
	return (c1.v[0]==c2.v[0] && c1.v[1]==c2.v[1]);
}

template <>
struct std::hash <CollapseCandidate>
{
public:
	size_t operator()(CollapseCandidate const &s) const
	{
		return s.v[0]+7*s.v[1];
	}
};



int main(void)
{
	std::unordered_map <CollapseCandidate,int> test;

	CollapseCandidate c;
	c.v[0]=123;
	c.v[1]=256;
	test[c]=10;

	c.v[0]=111;
	c.v[1]=333;
	test[c]=20;

	auto &x=test[c];
	printf("%d\n",x);

	c.v[0]=123;
	c.v[1]=256;
	printf("%d\n",test[c]);

	return 0;
}

