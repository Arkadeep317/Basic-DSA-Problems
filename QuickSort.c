#include<stdio.h>
#define MAX 100
void swap(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[],int l,int h)
{
int i=l,j=h,p=l; //i---> //<---j
while(i<j){
	while(arr[i] <= arr[p]) i++;
	while(arr[j] > arr[p]) j--;	
	if(i<j) 
	swap(arr+i,arr+j);		
}
swap(arr+j,arr+p);
return j;
}
void quicksort(int arr[],int l, int h)
{
	
	int pivotindex;
	//By default I'll Choose the first as my pivot element
	//pivotindex=l
	//Now I'll Need a function to get my actual pivotinfex
	if(l<h)
	{
	pivotindex = partition(arr,l,h);
	quicksort(arr,l,pivotindex-1);
	quicksort(arr,pivotindex+1,h);
	}
}
//Main Code: 
int main()
{
	int n,i,arr[MAX] ;
	printf("Enter the number of elements: "); scanf("%d",&n);
	printf("\nEnter Elements: ");
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	printf("\nBefore Sorting: ");
	printf("\n[");
	for(i=0;i<n;i++)	printf("%d\t",arr[i]);
	printf("\n]");
	quicksort(arr,0,n-1);
	printf("\nAfter Sorting: ");
	printf("\n[");
	for(i=0;i<n;i++)	printf("%d\t",arr[i]);
	printf("\n]");
}
