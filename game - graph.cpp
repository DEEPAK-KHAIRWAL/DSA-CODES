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
	
}edge;
void build_nodelist()
{
	node *curr,*prev=NULL;
	int i;
	cout<<"enter no. of persons :";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		curr=new node;
		cout<<"enter name "<<i<<": ";
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
		cout<<"enter no. of friends for "<<i<<": ";
		cin>>m;
		prev=NULL;
		for(j=1;j<=m;j++)
		{
			curr=new edge;
			ptr=start;
			curr->link=NULL;
			cout<<"enter "<<j<<" friend of "<<i<<": ";
			cin>>k;
			
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
void suggest(char s[20])
{
	cout<<"suggested friends for "<<s<<"  are :  ";
	node *temp=start,*t=start;
	edge *ed;
	while(temp!=NULL)
	{
	if(strcmp(temp->info,s)==0)
	break;
	else
	temp=temp->next;
	}
	int f;
	while(t!=NULL)
	{
		f=0;
		if(t==temp)
		t=t->next;
		ed=temp->adj;
		while(ed!=NULL)
		{
			if(ed->dest==t)
			{
			f=1;
			break;
		    }
		    ed=ed->link;
		}
		if(f==0)
		cout<<t->info<<"  ";
		t=t->next;
	}
}
void display()
{
	node *nptr;
	edge *eptr;
	nptr=start;
	while(nptr!=NULL)
	{
		eptr=nptr->adj;
		cout<<endl<<nptr->info<<"  ->  ";
		while(eptr!=NULL)
		{
			cout<<eptr->dest->info<<"   ";
			eptr=eptr->link;
		}
		nptr=nptr->next;
	}
}
int main()
{
	build_nodelist();
	insertedges();
	int i;
	cout<<"enter 1 for suggest , 2 for play game , 3 for delete";
	cin>>i;
	char s[20];
	switch(i)
	{
		case 1:
			cout<<"enter name for whom you want to suggest  : ";
			cin>>s;
			suggest(s);
			break;
		case 2:
			
			 break;
		case 3:
			//del();
			cout<<"after deleting"<<endl;
			display();
			break;
		default:
			cout<<"invalid input";
				
				
	}
	display();
	getch();
}
