#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
struct record      //RECORD OF STUDENT
{
	char roll[20];
	char name[20];
	int age;
	char branch[20];
};
struct node               // node containing record
{
	struct record data;
	struct node *next;
};
typedef struct node * z;         // typedefining of node
int partition(z head,int p,int r)        // PARTITION function  - returns a intiger before which all elements are smaller after which all elements are larger

{
	int i,j,m;
	z  x=head,f,l,temp=new struct node; //first element as pivot
	temp->next=NULL;
	for(m=0;m<p;m++)
	{
		x=x->next;
	}
	
	
	i=p-1;
	j=r+1;
	while(1)       //infinite loop
	{
		do
		{
			f=head;
			j--;
			for(m=0;m<j;m++)
			{
			
			f=f->next;
		}
		}while(strcmp(f->data.roll,x->data.roll)>0);         // comparing roll no.
		do
		{
			l=head;
			i++;
			for(m=0;m<i;m++)
			{
			
			l=l->next;
		}
		}while(strcmp(l->data.roll,x->data.roll)<0);        // comparing roll no.
		if(i<j)
		{
			
			temp->data=f->data;
			f->data=l->data;
			l->data=temp->data;
		}
		else
		return j;
	}
}
void quicksort(z head,int p,int r)           // quicksort function (recursive) - divides of list passed on basis of q
{
	int q;
	if(p<r)
	{
		q=partition(head,p,r);  //caling partition function
		quicksort(head,p,q);
		quicksort(head,q+1,r);
	}
}
int main()
{
	struct node *n1,*temp,*head;
	n1= new struct node;
	head=n1;
	n1->next=NULL;
	int i,n;
	cout<<"enter no. of elements ";  // taking inputs
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
	quicksort(head,0,n-1); //calling quicksort function
	for(i=0;i<n;i++)
	{
	    cout<<"NAME: "<<head->data.name<<endl<<"AGE :"<<head->data.age<<endl<<"ROLL :"<<head->data.roll<<endl<<"BRANCH :"<<head->data.branch<<endl<<endl;
		head=head->next;
	}
	
	getch();
}

