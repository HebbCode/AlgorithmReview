#include<stdio.h>
// 01背包问题，回溯法解 
// https://blog.csdn.net/Prototype___/article/details/124782502
int n=3;
int c=9;
int wi[3]={3,4,4}; // 重量 
int vi[3]={6,10,3};// 价值 

int opt[3]; // 最优载入方式 
int opt_v=-1;//  最优价值 
 
int now_w = 0;// 当前载入 
int now_v = 0;// 当前价值 
int now_z[3]={0};//当前载入方式 

int bag01(int the)
{
	if(the==4)//到达子节点 
	{
		if(now_v>opt_v)//最优解判断 
		{
			opt_v = now_v;
			for(int i=0; i<n;i++)
            opt[i] = now_z[i];
		}
	}
	else 
	{
		for(int i=0; i<=1; ++i)
        {
            if(the!=0)now_z[the-1]=i;
            if(i==0) //不放入背包
            {
                bag01(the+1);
            }
            else //放入背包
            {
                //约束条件：当前物品是否放的下
                if((now_v+wi[the])<=c)
                {
                    now_w += wi[the];
                    now_v += vi[the];
                    bag01(the+1);//进行回溯 
                    now_w -= wi[the];
                    now_v -= vi[the];
                }
            }
        }	
	}
}
int main()
{
	bag01(0);
	printf("maxvalue:%d\n",opt_v);
	for(int i=0; i<=n; i++)
    if(opt[i])printf("%d ",i+1);
}
