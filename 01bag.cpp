#include<stdio.h>
// 01�������⣬���ݷ��� 
// https://blog.csdn.net/Prototype___/article/details/124782502
int n=3;
int c=9;
int wi[3]={3,4,4}; // ���� 
int vi[3]={6,10,3};// ��ֵ 

int opt[3]; // �������뷽ʽ 
int opt_v=-1;//  ���ż�ֵ 
 
int now_w = 0;// ��ǰ���� 
int now_v = 0;// ��ǰ��ֵ 
int now_z[3]={0};//��ǰ���뷽ʽ 

int bag01(int the)
{
	if(the==4)//�����ӽڵ� 
	{
		if(now_v>opt_v)//���Ž��ж� 
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
            if(i==0) //�����뱳��
            {
                bag01(the+1);
            }
            else //���뱳��
            {
                //Լ����������ǰ��Ʒ�Ƿ�ŵ���
                if((now_v+wi[the])<=c)
                {
                    now_w += wi[the];
                    now_v += vi[the];
                    bag01(the+1);//���л��� 
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
