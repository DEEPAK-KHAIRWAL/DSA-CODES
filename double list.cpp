#include<iostream>
#include<stdlib.h>
using namespace std;
struct dlink
	{
		int data;
		struct dlink * next,* prev;
	};
void create(struct dlink*node)
{
	int i;
	for (i=0;i<4;i++)
	{
	struct dlink*temp=(struct dlink*)malloc(sizeof(struct dlink));
	temp->data=1000;
	temp->next=NULL;
	node->next=temp;
	temp->prev=node;
	node=temp;
}
}
void insert(struct dlink*node,int n,int x)
{
	int i=0;
	while(i<n)
	{
		node=node->next;
		i++;
	}
	struct dlink*curr=(struct dlink*)malloc(sizeof(struct dlink));
	curr->data=x;
	curr->prev=node->prev;
	node->prev->next=curr;
	curr->next=node;
	node->prev=curr;
}
void display(struct dlink*node)
{
	int i=0;
	for(i=0;i<5;i++)
	{
		cout<<node->data;
		node=node->next;
	}
}
main()
{
	struct dlink*node=(struct dlink*)malloc(sizeof(struct dlink));
	node->data=1000;
	node->prev=NULL;
	node->next=NULL;
	create(node);
	insert(node,2,10);
	display(node);
}
