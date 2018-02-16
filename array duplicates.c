main()
{
	int a[10],i,j,f,n=10;
	for (i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				for(f=j;f<n-1;f++)
				a[f]=a[f+1];
				n--;
				j--;
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}
