

void NonRepeatRand(int n,int r[])
{
	for(int i=0; i<n; ++i)
	{
		int x;
		bool found;
	RETRY:
		found=false;
		x=rand()%n;
		for(int j=0; j<i; ++i)
		{
			if(r[j]==x)
			{
				found=true;
				break;
			}
		}

		if(true==found)
		{
			goto RETRY;
		}
	}
}
