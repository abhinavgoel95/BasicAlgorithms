#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char numc1[100000];
char numc2[100000];
int num1[100000];
int num2[100000];
int ans[100000];
int max(int a, int b)
{
	int ans;
	if(a > b)
		ans =  a;
	else if(a < b)
		ans =  b;	
	if(a == b)
		ans = a;
	return ans;
}
int divide(int* num1,int* num2, int l1, int n1,int l2, int n2)
{
	int m1 = (l1 + n1)/2;
	int m2 = (l2 + n2)/2;
	int n = max(n1 , n2);
	if(n1 == 1 || n2 == 1)
		return num1[l1] * num2[l2]; 
	int x1 = divide(num1,num2,l1,m1,l2,m2);
	int x2 = divide(num1,num2,m1,n1,l2,m2);
	int x3 = divide(num1,num2,l1,m1,m2,n2);
	int x4 = divide(num1,num2,m1,n1,m2,n2);
	return x1*pow(10,n) + (x2 + x3) * pow(10,n/2) +x4;
}
int main()
{
	int i,n1,n2,j;
	scanf("%s",numc1);
	scanf("%s",numc2);
	n1 = strlen(numc1)-1;
	n2 = strlen(numc2)-1;
	int **arr = (int **)malloc(sizeof(int*)*n1);
	for(i =0 ; i<n1+n2;i++)
		arr[i] = (int *)malloc(sizeof(int) *(n2+n1));
	for(i = 0; i< n1; i++)
	{
		num1[i] = numc1[i]-48;
	}
	for(i = 0; i< n2; i++)
	{
		num2[i] = numc2[i]-48;
	}
	int a = divide(num1,num2,0,n1,0,n2);
	printf("%d",a);
}