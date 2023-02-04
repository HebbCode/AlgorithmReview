#include<stdio.h>
int arrayx[11][2]={1,4,3,5,0,6,5,7,3,8,5,9,6,10,8,11,8,12,2,13,12,14};
int main()
{
	int nexttime = 0;
	int arrayc[26]={0},ix=0;
	for(int i=0;i<11;i++)
	{
		if(nexttime<arrayx[i][0])
		{
			nexttime=arrayx[i][1];
			printf("%d-%d\n",arrayx[i][0],arrayx[i][1]);
		}
	}
}
