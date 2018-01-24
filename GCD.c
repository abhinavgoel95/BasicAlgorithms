#include <stdio.h>
#include <time.h>
int gcd(int n1, int n2);
int main()
{
    int t,n1,n2;
    double time_taken;
    time_t start, end;
    scanf("%d",&t);
   start = clock();
    while(t--)
    {
        scanf("%d %d",&n1,&n2);
        int a = gcd(n1,n2);
        printf("%d\n",a);
    }
   end = clock();
    
    time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("%f ms \n",time_taken*1000);
    return 0;
}
int gcd(int m, int n)
{
    int t;
    while(n != 0)
    {
        t = m;
        m = n;
        n = t%n;
    }
    return m;
}