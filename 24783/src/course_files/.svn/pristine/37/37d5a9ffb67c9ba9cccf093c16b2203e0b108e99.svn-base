#include <stdio.h>



bool CPUIsLittleEndian(void)
{
/*	union {
		unsigned char a[4];
		int b;
	} x;

	x.b=1;

	printf("%d %d %d %d\n",x.a[0],x.a[1],x.a[2],x.a[3]);

	if(1==x.a[0])
	{
		return true;
	}
	else
	{
		return false;
	} */

	int b=1;
	auto a=(unsigned char *)&b;

	printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);

	if(1==a[0])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	if(true==CPUIsLittleEndian())
	{
		printf("Little Endian CPU\n");
	}
	else
	{
		printf("Big Endian CPU\n");
	}
}
