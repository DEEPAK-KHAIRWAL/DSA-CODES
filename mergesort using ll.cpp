#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
struct record
{
	char roll[20];
	char name[20];
	int age;
	char branch[20];
};
struct node
{
	struct record data;
	struct node *next;
};
typedef struct node * z;
 void merge(z head,int p,int q,int r)
{
	struct node *c,*temp,*f=head,*l=head,*e,*x=head;
	

	int l1,r1,i,j;
	l1=p;
	r1=q+1;
	i=p;
	for(j=0;j<l1;j++)
		f=f->next;
	for(j=0;j<r1;j++)
		l=l->next;
	c=new struct node;
	c->next=NULL;
	c->data=head->data;
	e=c;
	while((l1<=q)&&(r1<=r))
	{
	
		if(strcmp(f->data.roll,l->data.roll)<0)
		{
			temp=new struct node;
			temp->data=f->data;
			temp->next=NULL;
			c->next=temp;
		    c=temp;
			l1++;
			f=f->next;
			
		}
		else
		{
		    temp=new struct node;
			temp->data=l->data;
			temp->next=NULL;
			c->next=temp;
		    c=temp;
			r1++;
			l=l->next;
			
		}
	}
	while(l1<=q)
	{
	    	temp=new struct node;
			temp->data=f->data;
			temp->next=NULL;
			c->next=temp;
		    c=temp;
			
			f=f->next;
            l1++;
	}
	while(r1<=r)
	{
	    	temp=new struct node;
			temp->data=l->data;
			temp->next=NULL;
			c->next=temp;
		    c=temp;
			l=l->next;
		    r1++;
	}
	e=e->next;
	for(j=0;j<p;j++)
	{
		x=x->next;
	}
	for(j=p;j<=r;j++)
	{
		x->data=e->data;
		x=x->next;
		e=e->next;
	}
	
}
void mergesort(z h ,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(h,p,q);
		mergesort(h,q+1,r);
		merge(h,p,q,r);
		
	}
}
int main()
{
	struct node *n1,*temp,*head;
	n1= new struct node;
	head=n1;
	n1->next=NULL;
	int i,n;
	cout<<"enter no. of elements ";
	cin>>n;
	cout<<"enter name ";
	cin>>n1->data.name;
	cout<<"enter age ";
	cin>>n1->data.age;
	cout<<"enter roll ";
	cin>>n1->data.roll;
	cout<<"enter branch ";
	cin>>n1->data.branch;
	for(i=0;i<n-1;i++)
	{
		temp=new struct node;
		cout<<"enter name ";
	cin>>temp->data.name;
	cout<<"enter age ";
	cin>>temp->data.age;
	cout<<"enter roll ";
	cin>>temp->data.roll;
	cout<<"enter branch ";
	cin>>temp->data.branch;
		n1->next=temp;
		temp->next=NULL;
		n1=temp;
	}
	mergesort(head,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<"NAME: "<<head->data.name<<endl<<"AGE :"<<head->data.age<<endl<<"ROLL :"<<head->data.roll<<endl<<"BRANCH :"<<head->data.branch<<endl<<endl;
		head=head->next;
	}
	
	getch();
}

