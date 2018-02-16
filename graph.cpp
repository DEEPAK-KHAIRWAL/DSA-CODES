#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
typedef struct nodelist
{
	char info[20];
	struct nodelist *next;
	struct edgelist *adj;
}node;
node *start;
int n;
typedef struct edgelist
{
	struct nodelist *dest;
	struct edgelist *link;
	int wt;
}edge;
void build_nodelist()
{
	node *curr,*prev=NULL;
	int i;
	cout<<"enter no. of nodes : ";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		curr=new node;
		cout<<"enter city "<<i<<": ";
		cin>>curr->info;
		curr->next=NULL;
		curr->adj=NULL;
		if(prev==NULL)
		 start=curr;
		else
		 prev->next=curr;
		 prev=curr;
	}
}
void insertedges()
{
	edge *curr,*prev;
	node *temp,*ptr;
	char k[20];
	int j,m,i,w;
	temp=start;
	for(i=1;i<=n;i++)
	{
		prev=NULL;
		cout<<"enter no. of adjacent node for "<<i<<": ";
		cin>>m;
		prev=NULL;
		for(j=1;j<=m;j++)
		{
			curr=new edge;
			ptr=start;
			curr->link=NULL;
			cout<<"enter "<<j<<" adjacent node of "<<i<<": ";
			cin>>k;
			cout<<"enter weight "<<": ";
			cin>>curr->wt;
			while(strcmp(ptr->info,k)!=0)
			{
				ptr=ptr->next;
			}
			curr->dest=ptr;
			if(prev==NULL)
			 temp->adj=curr;
			else
			 prev->link=curr;
			prev=curr;
		}
		temp=temp->next;
	}
}
int outorder(node *nptr)
{
	int i=0;
	edge *ad=nptr->adj;
	while(ad!=NULL)
	{
		i++;
		ad=ad->link;
	}
	return i;
}
int inorder(node *nptr)
{
	int i=0;
	node *st=start;
	edge *ed;
	while(st!=NULL)
	{
		ed=st->adj;
		while(ed!=NULL)
		{
			if(strcmp(ed->dest->info,nptr->info)==0)
			i++;
			ed=ed->link;
		}
		st=st->next;
	}
	return i;
}
void display()
{
	node *nptr;
	edge *eptr;
	nptr=start;
	while(nptr!=NULL)
	{
		eptr=nptr->adj;
		cout<<nptr->info<<" ***  "<<"inorder : "<<inorder(nptr)<<" ***  "<<"outorder : "<<outorder(nptr)<<endl;
		while(eptr!=NULL)
		{
			cout<<eptr->dest->info<<"   weight : "<<eptr->wt<<endl;
			eptr=eptr->link;
		}
		nptr=nptr->next;
	}
}
int main()
{
	build_nodelist();
	insertedges();
	display();
	getch();
}
