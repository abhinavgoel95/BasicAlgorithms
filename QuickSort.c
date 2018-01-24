#include <stdio.h>
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int partion(int *arr,int l, int r)
{
	int pivot = arr[l];
	int i = l+1, j = r;
	while(i <= j)
	{
		while(arr[i] <= pivot)
			i++;
		while(arr[j] >= pivot)
			j--;
		if(i < j)
			swap(arr,i,j);
	}
	if(pivot > arr[j])
		swap(arr,j,l);
	return j;
}
void sort(int* arr, int l, int r)
{
	int s;
	if(l < r)
	{
		s = partion(arr, l, r);
		sort(arr,l,s-1);
		sort(arr,s+1,r);
	}
}
int main()
{
	int i;
	int arr[50] = {10,1,20,14,3,18,2};
	sort(arr,0,6);
	for(i =0; i<7; i++)
		printf("%d ",arr[i]);
	return 0;
}