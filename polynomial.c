main()
{
	int n1,n2,e1[100],c1[100],e2[100],c2[100],i,j,s,f,k;
	printf("enter no.of terms in poly 1 ");
	scanf("%d",&n1);
	printf("enter no.of terms in poly 2 ");
	scanf("%d",&n2);
	s=n2-1;
	for(i=0;i<n1;i++)
	{
		printf("enter poly 1 exp%d ",i+1);
		scanf("%d",&e1[i]);
		printf("enter poly 1 coeff%d ",i+1);
		scanf("%d",&c1[i]);
	}
		for(i=0;i<n2;i++)
	{
		printf("enter poly 2 exp%d ",i+1);
		scanf("%d",&e2[i]);
		printf("enter poly 2 coeff%d ",i+1);
		scanf("%d",&c2[i]);
	}
	for(i=n1-1;i>=0;i--)
	{
	   f=0;
	   for(j=s;j>=0;j--)
	   {
	   	if(e2[j]>e1[i])
	   	{
		   
	   	printf("coeff %d exp %d\n",c2[j],e2[j]);
	   }
	   else if(e2[j]==e1[i])
	   	{
	   	printf("coeff %d exp %d\n",c2[j]+c1[i],e2[j]);
	   	f=1;
	   	s=j-1;
	   	break;
	   }
       else if(e2[j]<e1[i])
        {
        	printf("coeff %d exp %d\n",c1[i],e1[i]);
        	f=1;
        	s=j;
        	break;
		}
	   }
	   if(f==0)
	   {
	   	s=-1;
	   	for(k=i;k>=0;k--){
		   
	   printf("coeff %d exp %d\n",c1[k],e1[k]);}
	   break;
}
}
if(s>=0)
{
	for(i=s;i>=0;i--)
	printf("coeff %d exp %d\n",c2[s],e2[s]);
}
	   
}
