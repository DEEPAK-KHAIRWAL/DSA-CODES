/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
#include<vector>
static vector<int>a,b;
static int nr;int rmax;int nl;int lmax=-1;
void print()
{
    for(int i=a.size()-1;i>=0;i--)
    {
        
        cout<<a[i]<<" ";
       
    }
    for(int j=0;j<b.size();j++)
    {
        
        cout<<b[j]<<" ";
       
    }
}
void l(node*root);
void r(node*root)
{
    if(root==NULL)
 { nr--;nl++;
     return;}
    if(nr>rmax){
    b.push_back(root->data);
        rmax=nr;}
    nr++;
    nl--;
    r(root->right);
    nl++;
    nr--;
    l(root->left);
    nl++;
    nr--;
    return;
}
void l(node*root)
{
    if(root==NULL)
 { nr++;nl--;
     return;}
   if(nl>lmax){
    a.push_back(root->data);
       lmax=nl;}
    nl++;
    nr--;
    l(root->left);
    nr++;
    nl--;
    r(root->right);
    nl--;
    nr++;
    return;
}
void topView(node * root) {
    l(root);
    print();
    
    
  
}
*/* RUNNABLE IN HACKERRANK*/
/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
#include<vector>
static vector<int>a,b;
static int nr;int rmax;int nl;int lmax;
void printa()
{
    for(int i=a.size()-1;i>=0;i--)
        cout<<a[i]<<" ";
}
void printb()
{
    for(int j=0;j<b.size();j++)
        cout<<b[j]<<" ";
}
void l(node*root);
void r(node*root)
{
    if(root==NULL)
 { nr--;
     return;}
    if(nr>rmax){
    b.push_back(root->data);
        rmax=nr;}
    nr++;
    r(root->right);
    nr--;
    return;
}
void l(node*root)
{
    if(root==NULL)
 { nl--;
     return;}
   if(nl>lmax){
    a.push_back(root->data);
       lmax=nl;}
      nl++;
    l(root->left);
    nl--;
    return;
}
void topView(node * root) {
    lmax=-1;
    l(root);
    printa();
    r(root);
    printb();
}

