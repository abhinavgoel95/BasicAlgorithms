#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	char usn[10];
	char name[10];
};
void heapsort1(struct student* stud, int n, int i)
{
	int j = 2*i;
	struct student temp;
	if(j <= n)
	{
		if((j+1) <= n)
		{
			if(strcmp(stud[j].name, stud[j+1].name) < 0)
				j++;
		}
		if(strcmp(stud[j].name, stud[i].name) > 0)
		{
			temp = stud[j];
			stud[j] = stud[i];
			stud[i] = temp;
		}
		//printf("here %d\n", j);
		heapsort1(stud, n, j);
	}
}
void check(struct student* stud, int i)
{
	int j = i /2;
	struct student temp;
	while(j > 0)
	{
		if(strcmp(stud[j].name, stud[i].name) < 0 )
		{
			temp = stud[j];
			stud[j] = stud[i];
			stud[i] = temp;
		}
		i = j;
		j = i /2;
	}
}
int main()
{
	int n,i,k;
	struct student temp;
	scanf("%d",&n);
	k = n;
	struct student* stud = (struct student*)malloc((n+1) * sizeof(struct student));
	for(i =1; i< n+1; i++)
	{
		scanf("%s",stud[i].usn);
		scanf("%s",stud[i].name);
		check(stud, i);
	}
	for(i = 1; i <= n; i++)
	{
		temp = stud[k];
		stud[k] = stud[1];
		stud[1] = temp;
		heapsort1(stud, --k,1);
	}
	for(i =1; i< n+1; i++)
	{
		printf("%s ",stud[i].usn);
		printf("%s\n",stud[i].name);
	}
}