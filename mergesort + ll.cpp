#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
struct record                // student record
{
	char roll[20];
	char name[20];
	int age;
	float cgpa;
	char branch[20];
};
int choice;
struct node       // node containing record
{
	struct record data;
	struct node *next;
};
typedef struct node * z;         // typedefining of node
 void merge(z head,int p,int q,int r)            // merge function  - sorts the portion of list passed
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
	if(choice==1)       // sort by roll
	{
	while((l1<=q)&&(r1<=r))
	{
	
		if(strcmp(f->data.roll,l->data.roll)<0)       // comparing roll no.
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
	e=e->next;   // challenging logic
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
else           //sort by name
{
		while((l1<=q)&&(r1<=r))
	{
	
		if(strcmp(f->data.name,l->data.name)<0)     // comparing names
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
	
}
void mergesort(z h ,int p,int r) // recusive funcion which uses divide and conquer technique
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(h,p,q);
		mergesort(h,q+1,r);
		merge(h,p,q,r);   //calling merge function
		
	}
}
void klarge(z head,int k)   //prints the k largest record on basis of cgpa

{
		z b,c=head;
	struct record a;
	int i,f;
	while(c!=NULL)
	{
		f=0;
		b=head;
		a=c->data;
		while(b!=NULL)
		{
			if(a.cgpa<b->data.cgpa)
			f++;
			b=b->next;
		}
		if(f==k-1)
		{
			cout<<"NAME: "<<a.name<<endl<<"AGE :"<<a.age<<endl<<"ROLL :"<<a.roll<<endl<<"BRANCH :"<<a.branch<<endl<<"CGPA :"<<a.cgpa<<endl<<endl;   //displaying output
			break;
		}
		c=c->next;
		if(f==k-1)
		break;
	}
	
}
int main()
{
	struct node *n1,*temp,*head;
	n1= new struct node;
	head=n1;
	n1->next=NULL;
	int i,n,k;
	cout<<"enter no. of elements ";   // taking inputs
	cin>>n;
	cout<<"enter name ";
	cin>>n1->data.name;
	cout<<"enter age ";
	cin>>n1->data.age;
	cout<<"enter roll ";
	cin>>n1->data.roll;
	cout<<"enter branch ";
	cin>>n1->data.branch;
	cout<<"enter cgpa ";
	cin>>n1->data.cgpa;
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
	cout<<"enter cgpa ";
	cin>>temp->data.cgpa;
		n1->next=temp;
		temp->next=NULL;
		n1=temp;
	}
	/*cout<<"enter 1 for sort by roll no. and 2 to sort by name";
	cin>>choice;
	mergesort(head,0,n-1);   // calling mergeort
	for(i=0;i<n;i++)
	{
		cout<<"NAME: "<<head->data.name<<endl<<"AGE :"<<head->data.age<<endl<<"ROLL :"<<head->data.roll<<endl<<"BRANCH :"<<head->data.branch<<endl<<"CGPA :"<<head->data.cgpa<<endl<<endl;
		head=head->next;
	}*/
	cout<<"enter the k largest value of cgpa you want to find : ";
	cin>>k;
	klarge(head,k);  //calling klarge
	for(i=1;i<=5;i++)
	klarge(head,i);
	getch();
}

