#include<iostream>
#include <conio.h>
#include<stdlib.h>

using namespace std;
struct tree
{
	int info;
	struct tree * left,* right;
};
typedef struct tree * bstnode;
bstnode findmin(bstnode);
bstnode insert (bstnode t,int x)
{
	if(t==NULL)
	{
		t= new struct tree;
		t->info=x;
		t->left=t->right=NULL;
	}
	else
	if(t->info<x)
	{
		t->right=insert(t->right,x);
	}
	else 
	{
		t->left=insert(t->left,x);
	}
	
}
bstnode delet (bstnode t,int x)
{
	bstnode temp;
	if(t==NULL)
	cout<<"not found";
	else if(x<t->info)
	t->right=delet(t->right,x);
	else if(t->left!=NULL&&t->right!=NULL)
	{
		temp=findmin(t->right);
		t->info=temp->info;
		t->right=delet(t->right,temp->info);
	}
	else
	{
		temp=t;
		if(t->left==NULL)
		t=t->right;
		else if(t->right==NULL)
		t=t->left;
		free(temp);
		return t;
	}
	
}
void inorder(bstnode t)
{
	if(t->left!=NULL)
	inorder(t->left);
	cout<<t->info<<endl;
	if(t->right!=NULL)
	inorder(t->right);
	
}
bstnode findmin(bstnode t)
{
	if(t==NULL)
	return NULL;
	else
	if(t->left==NULL)
	return t;
	else
	return findmin(t->left);
}
bstnode summing(bstnode t)
{
	if (t->right==NULL && t->left==NULL)
	return t;
	else
	{
		if(t->left==NULL&&t->right!=NULL)
		{
			t->right=summing(t->right);
			bstnode r=t->right;
			t->info=r->info;
		}
		else if(t->left!=NULL&&t->right==NULL)
		{
		t->left=summing(t->left);
		t->info=t->left->info;
        }
        else
        {
        	t->left=summing(t->left);
        	t->right=summing(t->right);
        	bstnode r=t->right,l=t->left;
        	t->info=l->info+r->info;
        }
		return t;
	}
}
int main()
{
	bstnode t;
	int n,a,b,i;
	t=NULL;
	cout<<"enter no.of elements";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter element";
		cin>>a;
		t=insert(t,a);
	}
/*	cout<<"enter element to delete";
	cin>>b;
	t=delet(t,b);*/
	cout<<"before summing\n";
	inorder(t);
	summing(t);
	cout<<"\n after summing\n";
	inorder(t);
	getch();
}
