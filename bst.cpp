#include<iostream>
#include <conio.h>
#include<stdlib.h>

using namespace std;
struct tree
{
	int info;
	struct tree * left,* right;
};
typedef tree * bstnode;
bstnode findmin(bstnode);
bstnode insert (bstnode t,int x)
{
	if(t==NULL)
	{
		t= new  tree;
		t->info=x;
		t->left=t->right=NULL;
	}
	else
	if(x<t->info)
	{
		t->left=insert(t->left,x);
	}
	else if(x>t->info)
	{
	    t->right=insert(t->right,x);
		return t;
	}
}
bstnode delet (bstnode t,int x)
{
	bstnode temp;
	if(t==NULL)
	cout<<"not found";
	else if(x>t->info)
	t->right=delet(t->right,x);
	else if(x<t->info)
	t->left=delet(t->left,x);
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
if(t==NULL)
    return;
    inorder(t->left);
    cout<<t->info<<" ";
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
bstnode reverse(bstnode t)
{
	if(t==NULL)
	return t;
	else
	{
		bstnode temp;
		temp=t->left;
		t->left=t->right;
		t->right=temp;                       // swapping
		t->left=reverse(t->left);
		t->right=reverse(t->right);
		return t;
	}
}
int main()
{
	bstnode t;
	int n,a,b,i;
	t=NULL;
	cout<<"enter no.of elements ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter element ";
		cin>>a;
		t=insert(t,a);
	}
	cout<<"elements in sorted order:"<<endl;
	inorder(t);
	cout<<"enter element to delete ";
	cin>>b;
	t=delet(t,b);
	cout<<"before reversing\n";
	inorder(t);
	reverse(t);
	cout<<"\n after reversing\n";
	inorder(t);
	cout<<"elements after deleting :"<<endl;
	inorder(t);
	
	getch();
}
