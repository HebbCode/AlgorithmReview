#include<stdio.h>
#define maxlen 100
//�������� https://alchemist-al.com/algorithms/longest-common-subsequence
//��⣺https://blog.csdn.net/qq_39521554/article/details/79265232
//����η�������https://www.cnblogs.com/ZeroTensor/p/10550071.html 
//13456778 357486782 �������� 
int getvalue(char *a) //��ֵ 
{
    char c;
    int i=0;
    for(;i<maxlen;i++)
    {
        c = getchar();
        if(c=='\n')break;
        *(a+i)=c;
    }
    return i;
}

int main()
{
	char s1[maxlen]="";
	char s2[maxlen]="";
	char over[maxlen]="";
	int slcs[maxlen][maxlen]={0}; //��ϵ�ϲ��� 
    s1len = getvalue(s1);//��ȡ���� 
    s2len = getvalue(s2);
	int i,j,n,get;
	for(i=0;i<s1len;i++)
	{
		char temp = s1[i];
		for(j=0;j<s2len;j++)
		{
			if(temp == s2[j]){
				slcs[i+1][j+1] = slcs[i][j]+1;//��Ⱦ͸�ֵ 
			}
			else{
				slcs[i+1][j+1] = slcs[i][j+1]>slcs[i+1][j]?slcs[i][j+1]:slcs[i+1][j];//����ȿ��ڿ����ֵ 
			}
			//printf("%d ",slcs[i+1][j+1]);
		}
		//putchar('\n'); 
	}
	get = n = slcs[s1len][s2len];
	printf("len:%d ",get);
	i=s1len-1;
	j=s2len-1;
	
	//�������ҳ�������� 
	//��Ӧ����ȣ��ҵ��ڿ����ֵ ������ͬ��ѡ��һ���̶��ķ��� 
    //��Ӧ��������
	while(n)
	{
		if(s1[i]==s2[j])
		{
			over[n-1]=s1[i];
			i--;j--;n--;
			continue; 
		}
		if(slcs[i+1][j]>slcs[i][j+1])
		{
			j--;
			continue;
		}
		else{
			i--;
			continue;
		}
		if(slcs[i+1][j]==slcs[i][j+1])
		{
			i--;
		}
	}
	printf("Longest subsequence:");//��� 
	i=0;
	while(i<get){
		printf("%c",over[i++]);
	}
}
 
