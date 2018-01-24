#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr1[10000000];
char arr2[10000000];
char* multiply1(int* num1, int* num2, int n1, int n2, char* ans);
int main()
{
	scanf("%s",arr1);
	scanf("%s",arr2);
	int n1 = strlen(arr1);
	int n2 = strlen(arr2);
	int* num1 = (int *)malloc(sizeof(int) * n1);
	int* num2 = (int *)malloc(sizeof(int) * n2);
	char* ans = (char *)malloc(sizeof(int) * (n2+n1));
	int i;
	for(i =0; i<n1;i++)
		num1[i] = arr1[i] - 48;
	for(i =0;i<n2;i++)
		num2[i] = arr2[i] - 48;
	ans = multiply1(num1,num2,n1,n2,ans);
	printf("\n%s",ans);
}
char* multiply1(int* num1, int* num2, int n1, int n2, char* ans)
{
	int i, j, k, r;
	int p , q;
	int sum = 0;
	int* temp = (int *)malloc(sizeof(int) * (n2+n1));
	int* c = (int *)malloc(sizeof(int) * (n2+n1));
	for(i=n2-1;i>=0;i--)
	{
         r=0;
         for(j=n1-1;j>=0;j--)
         {
             temp[k++] = (num2[i] * num1[j] + r)%10;
             r = (num1[j] * num2[i] + r)/10;
         }
         temp[k++] = r;
         p++;
         for(q = 0; q < p; q++)
         {
             temp[k++] = 0;
         }
    }
    k=0;
    r=0;
    for(i=0;i<n1+n2+2;i++)
    {
         sum =0;
         q=0;
         for(j=1;j<=n2+1;j++)
         {
             if(i <= n1+j)
             {
                 sum = sum + temp[q+i];
             }
             q += j + n1 + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--)
    {
         ans[j++]=c[i] + 48;
    }
    ans[j]='\0';
    return ans;
}