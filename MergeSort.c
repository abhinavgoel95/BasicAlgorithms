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
void mergeSort(struct student* studA, int n);
void merge(struct student* studC,struct student* studB,struct student* studA,int j,int k,int n);
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
	mergeSort(stud,n);
	for(i =0; i< n;i++)
	{
		printf("%s %s %f\n",stud[i].USN,stud[i].name,stud[i].gpa);	
	}
}
void mergeSort(struct student* studA, int n)
{
	struct student *studB = (struct student*)malloc(n/2 * sizeof(struct student));
	struct student *studC = (struct student*)malloc(n/2 * sizeof(struct student));
	int i,j=0,k=0;
	if(n >1)
	{
		for(i =0; i< n/2 - 1;i++)
		{
			studB[k++] = studA[i];
		}
		for(i =n/2; i< n - 1;i++)
		{
			studC[j++] = studA[i];
		}
		mergeSort(studC,j);
		mergeSort(studB,k);
		merge(studC,studB,studA,j,k,n);
	}
}
void merge(struct student* studC,struct student* studB,struct student* studA,int j,int k,int n)
{
	int p =0,q=0,r=0;
	while(p <j && q < k)
	{
		int cmp = strcmp(studC[p].name,studB[q].name);
		if(cmp > 0)
		{
			studA[r++] = studB[q++];
		}
		else
		{
			studA[r++] = studC[p++];
		}
	}
	if(p == j)
	{
		while(q < k)
		{
			studA[r++] = studB[q++];
		}
	}
	else if(q == k)
	{
		while(p < j)
		{
			studA[r++] = studC[p++];
		}
	}
}