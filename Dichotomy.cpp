#include<stdio.h>
#define len 5
int arrayx[len] = {3,17,25,78,112};
int main()
{
	int l=0,r=len-1,s;
	int mid =(l+r)/2;
	printf("show array: ");
	for(int i=0;i<len;i++)
	printf("%d ",arrayx[i]);
	putchar('\n');
	printf("search:");
	scanf("%d",&s);
	while(l<r)
	{
		if(arrayx[mid]==s)
		{
			printf("%d in %d",s,mid+1);
			break;
		}
		if(arrayx[mid]>s)r=mid-1;
		else l=mid+1;
		mid =(l+r)/2;
	}
 } 
