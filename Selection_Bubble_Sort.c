#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selsort(int* arr, int cn);
void bubsort(int* arr, int n);
void swap(int *arr1,int *arr2);
int main()
{
	int n,i;
	int* arr;
	double timetaken;
	time_t start, end;
	scanf("%d",&n);
	arr = (int *)malloc(n * sizeof(int));
	for(i =0; i<n; i++)
		scanf("%d",&arr[i]);
	start = clock();
	//selsort(arr, n);
	bubsort(arr,n);
	end = clock();
	timetaken = (double)(end - start)/CLOCKS_PER_SEC;
	for(i =0; i<n; i++)
		printf("%d\n",arr[i]);
	printf("\nTime Taken: %fms\n", timetaken*1000);
}
void selsort(int* arr, int n)
{
	int i,j,min;
	for(i = 0; i< n-1;i++)
	{
		min = i;
		for(j = i+1; j<n;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(&arr[i],&arr[min]);
	}
}
void bubsort(int* arr, int n)
{
	int i,j,k;
	for(i =0; i<n-1;i++)
	{
		k = 0;
		for(j = 0; j <n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				k = 1;
			}
		}
		if(k == 0)
			break;
	}
}
void swap(int *arr1,int *arr2)
{
	int t;
	t= *arr1;
	*arr1 = *arr2;
	*arr2 = t;
}