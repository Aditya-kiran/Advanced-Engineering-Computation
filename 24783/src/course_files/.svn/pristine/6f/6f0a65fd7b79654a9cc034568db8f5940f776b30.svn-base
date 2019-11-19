#include <stdio.h>
#include <string.h>



char *MyFgets(char str[],int len,FILE *fp)
{
	auto ptr=fgets(str,len,fp);
	if(nullptr!=ptr)
	{
		for(int i=strlen(str); 0<=i; --i)
		{
			if(str[i]==0x0d || str[i]==0x0a)
			{
				str[i]=0;
			}
		}
	}
	return ptr;
}

int main(void)
{
	char str[256],newfn[256];
	while(nullptr!=MyFgets(str,255,stdin))
	{
		if(33<=strlen(str))
		{
			printf("%s\n",str);
			strcpy(newfn,str+33);

			for(int i=0; i<4; ++i)
			{
				if('A'<=newfn[i] && newfn[i]<='Z')
				{
					newfn[i]=newfn[i]+'a'-'A';
				}
			}

			printf("%s\n",newfn);

			rename(str,newfn);
		}
	}
	return 0;
}




