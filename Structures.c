#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct student
{
	char USN[10];
	char name[50];
	float gpa;
};
int BinSearch(struct student* stud, int left, int right, char* name);
int main()
{
	time_t start,end;
	int n,i;
	scanf("%d",&n);
	struct student *stud = (struct student*)malloc(n * sizeof(struct student)); //Array of structures
	char name[50];
	for(i =0; i< n;i++)
	{
		scanf("%s",stud[i].USN);
		scanf("%s",stud[i].name);
		scanf("%f",&stud[i].gpa);	
	}
	scanf("%s",name);
	int left = 0;
	int right = n-1;
	start = clock();
	int k = BinSearch(stud,left,right,name);
	end = clock();
	printf("%d\n",k);
	double taken = (double)(end - start)/CLOCKS_PER_SEC;
	printf("%f ms\n",taken*1000);
	return 0;
}
int BinSearch(struct student* stud, int left, int right, char* name)
{
	int ans;
	if(left > right)
		ans = -1;
	else
	{
		int mid = (left + right)/2;
		int k = strcmp(name, stud[mid].name);
		if(k == 0)
		{
			while(mid-1 > 0 && !strcmp(stud[mid-1].name, stud[mid].name))
				mid--;
			ans = mid;
		}
		else if(k<0)
		{
			right = mid - 1;
			ans = BinSearch(stud,left,right,name);
		}
		else
		{
			left = mid + 1;
			ans = BinSearch(stud,left,right,name);
		}
	}
	return ans;
}
