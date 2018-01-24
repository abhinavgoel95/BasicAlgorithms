#include <stdio.h>
#include <time.h>
int seqsearch(int* arr, int n, int num);
int main()
{
	time_t start,end;
	double time_taken;
	int n,t,i,num;
	int arr[20];
	scanf("%d",&t);
	start = clock();
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0 ; i < n; i++)
			scanf("%d",&arr[i]);
		scanf("%d",&num);
		int ans = seqsearch(arr,n,num);
		printf("%d\n",ans);
	}
	end = clock();
	time_taken = ((double)(end - start))/CLOCKS_PER_SECS;
	printf("%f ms\n",time_taken*1000);
	return 0;
}
int seqsearch(int* arr, int n, int num)
{
	int i;
	for(i = 0 ;i < n; i++)
	{
		if(*(arr+i) == num)
			return i;
	}
	return -1;
}