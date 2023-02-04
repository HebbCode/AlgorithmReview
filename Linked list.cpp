#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node* next;
}linkc;
double c;
linkc* createLink()
{
	linkc* head;
	linkc* p;
	linkc* p1;
	int temp;
	int count = 1;
	scanf("%d",&temp);
	head = (linkc *)malloc(sizeof(linkc));
	p = head;
	p->data=temp;
	p->next=NULL;
	while(1)
	{
		scanf("%d",&temp);
		if(temp==-1)break;
		p1 =(linkc*)malloc(sizeof(linkc));
		p1->data=temp;
		p1->next=NULL;
		p->next=p1;
		p=p1;
		count++;
	}
	c = count;
	return head;
}
void putslink(linkc* p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    putchar('\n');
}
int rMax(linkc* p)
{
	int num;
	if(!p->next)return p->data;
	num = rMax(p->next); 
	return p->data>num?p->data:num; 
}
int Max(linkc* p)
{
	int num=p->data;
	p=p->next;
    while(p)
    {
      	num = p->data>num?p->data:num;
      	p=p->next;
    }
    return num;
}
double rAverageV(linkc* p)
{
	if(!p->next)return p->data/c;
	return p->data/c+rAverageV(p->next); 
}
double AverageV(linkc* p)
{
	double num=p->data/c;
	p=p->next;
    while(p)
    {
      	num += p->data/c;
      	p=p->next;
    }
    return num;
}
int main()
{
	linkc* head=createLink();
	putslink(head);
	printf("rMax %d\n",rMax(head));
	printf("Max %d\n",Max(head));
	printf("rAverageV %lf\n",rAverageV(head));
	printf("AverageV %lf\n",AverageV(head));
 } 
