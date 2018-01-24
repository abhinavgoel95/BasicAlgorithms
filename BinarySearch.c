#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char usn[15];
	char name[30];
	char gpa[6];
}Record;

int equal(char *key, Record * str);
int less(char *a, Record *b);
int binarySearch(Record *arr, int size,char* key);

int main()
{
	Record *arr;
	int size;
	int i;
	int index;
	char key[20];

	scanf("%d",&size);
	arr = (Record *)malloc(size*sizeof(Record));
	for(i = 0; i < size;i++)
	{
		scanf("%s",arr[i].usn);
		scanf("%s",arr[i].name);
		scanf("%s",arr[i].gpa);
	}
	scanf("%s",key);
	index = binarySearch(arr,size,key);
	printf("%d\n",index);

	
	return 0;
}

int binarySearch(Record *arr, int size,char *key)
{
	int l = 0;
	int r = size-1;
	int m;
	int ans = -1;
	int ch;

	
	while((l <= r) && (ans == -1))
	{
		
		m = (l+r)/2;
		if(equal(key,&arr[m]))
		{
			ch = m;
			while(equal(key,&arr[ch]))
			{
				ch--;
			}
			ans = ch+1;
		}
		else if(less(key,&arr[m]))
		{
			r = m-1;
		}
		else
		{
			l = m+1;
		}
	}
	return ans;
}
int equal(char *key, Record * str)
{
	int c = strcmp(key, str->name);
	int ans;
	if(c == 0) 
	{
		ans = 1;
	} 
	else 
	{
		ans =0;
	}
	return ans;
}
int less(char *a, Record *b) 
{
	int c = strcmp(a, b->name);
	int ans;
	if(c < 0) 
	{
		ans = 1;
	} 
	else 
	{
		ans =0;
	}
	return ans;
}