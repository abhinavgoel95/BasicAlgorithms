#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char numc1[1000000000];
char numc2[1000000000];
int num1[1000000000];
int num2[1000000000];
int ans[1000000000];
int main()
{
	int i,n1,n2,j,k,l,sum,a,carry;
	scanf("%s",numc1);
	scanf("%s",numc2);
	n1 = strlen(numc1);
	n2 = strlen(numc2);
	int **arr = (int **)malloc(sizeof(int*)*(n1));
	for(i =0 ; i<n1+n2;i++)
		arr[i] = (int *)malloc(sizeof(int) *(n2+n1));

	//CHAR TO INT
	for(i = 0; i< n1; i++)
	{
		num1[i] = numc1[i]-48;
	}
	for(i = 0; i< n2; i++)
	{
		num2[i] = numc2[i]-48;
	}

	//FILLING MATRIX WITH 0s
	for(i =0; i<n1;i++)
	{
		for(j =0; j<n2+n1;j++)
			arr[i][j] = 0;
	}

	//PERFORMING MULTIPLICATION
	for(i = 0; i<n1;i++)
	{
		l = n1 - i-1;
		k = n2 - 1;
		for(j = n2+n1-i-1; j>0;j--)
		{
			arr[i][j] = num1[l]*num2[k--];
			if(k == -1)
				break;
		}
	}

	//ADDING COLUMNS OF FINAL MATRIX
	k = n1+n2-1;
	carry = 0;
	for(j = n1 + n2 -1 ; j >= 0; j--)
	{
		sum = 0;
		for(i =0; i <n1; i++)
		{
			sum = sum + arr[i][j];
		}
		sum = sum + carry;
		a = sum % 10;
		carry = sum/10;
		ans[k--] = a;
	}

	//PRINTING ANSWER
	for(j =0; j<n1+n2;j++)
	{
		printf("%d",ans[j]);
	}
	printf("\n");
}