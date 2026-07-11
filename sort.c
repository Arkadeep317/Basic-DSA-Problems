#include<stdio.h>
#include<stdlib.h>
void b_sort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		if(a[j]>a[j+1])
		{
			t=a[j];
			   a[j]=a[j+1];
			   a[j+1]=t;
		}
	}
}
void i_sort(int a[],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while((t<a[j]) && (j>=0))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}
}
void s_sort(int a[],int n)
{
	int i,j,t,p,min;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		p=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				p=j;
			}
		}
			if(p!=i)
			{
				t=a[i];
				a[i]=a[p];
				a[p]=t;
			}
		
	}
}

void disp(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
}

int main()
{
	int a[10],n,i,m;
	
	while(1)
	{
		printf("\n1.bubble sort 2.insertion 3.selection");
		printf("\nenter choice: ");
		scanf("%d",&m);
		switch(m)
		{
			case 1:
				printf("Enter size of array: ");
	            scanf("%d",&n);
	            for(i=0;i<n;i++)
	            {
		          printf("\nenetr element: ");
		          scanf("%d",&a[i]);
		
	            }
				b_sort(a,n);
				disp(a,n);
				break;
			case 2:
				printf("Enter size of array: ");
	            scanf("%d",&n);
	            for(i=0;i<n;i++)
	            {
		          printf("\nenetr element: ");
		          scanf("%d",&a[i]);
		
	            }
				i_sort(a,n);
				disp(a,n);
				break;
			case 3:
				printf("Enter size of array: ");
	            scanf("%d",&n);
	            for(i=0;i<n;i++)
	            {
		          printf("\nenetr element: ");
		          scanf("%d",&a[i]);
		
	            }
				s_sort(a,n);
				disp(a,n);
				break;
			default:
				printf("\ninvalid");
				exit(0);
		}
	}
}
