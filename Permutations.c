
//DAA Lab Exercise
//Find next permutation in lexicographic order
#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int next_perm(int *perm, int n);
int TSP(int *p, int n, int ip[15][15]);
void print_perm(int *perm, int n);
void swap(int *arr, int i, int j);

int main () 
{
    time_t start, end;
    int n, cost, mincost = INT_MAX;
    int i,j;
    int ip[15][15];
    int *perm;

    scanf("%d", &n);
    for(i = 0; i< n;i ++)
    {
        for(j = 0; j < n; j++)
            scanf("%d",&ip[i][j]);
    }
    perm = (int *) malloc(n * sizeof(int));
    for(i=0; i<n; i++) 
        perm[i] = i;
    i = 0;
    int k =1;
    printf("\n\n");
    start = clock();
    while(k != 0) 
    {
        cost = TSP(perm,n,ip);
        if(cost < mincost)
            mincost = cost;
        k = next_perm(perm, n);
    }
    end = clock();
    double time_taken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\n%d\n%f ms \n", mincost, time_taken*10000);
    return 0;
}
int TSP(int *p, int n, int ip[15][15])
{
    int i;
    int cost = 0;
    for(i = 0; i < n-1; i++)
        cost = cost + ip[p[i]][p[i+1]];
    cost = cost + ip[p[i]][p[0]];
    return cost;
}
//Generate next permutation in lexicographic order.
//Returns 0 if there is no next permutation, else returns 1.
int next_perm(int *perm, int n)
{
    int i, j;
    //find the farthest i such that perm[i] < perm[i+1]
    i = n-2; //i points to last but one element of the array
    while( (i >= 0) && (perm[i] > perm[i+1]) ) 
        i--;
    //if there is no such i, it'll be -1 indicating there is no new perm
    if(i <= -1) //when n == 0, i will be -2
    { 
        return 0;
    }
    //find the farthest j such that perm[j] > perm[i]
    j = i+1;
    while( (j < n) && (perm[j] > perm[i]) ) 
    {
        j++;
    }
    j--;
    //swap perm[i] and perm[j], and then reverse perm[i+1 .. n-1]
    swap(perm, i, j);
    perm += i+1;
    n -= i+1;
    for(i = 0; i < n/2; i++)
        swap(perm, i, n-1-i);
    return 1;
}
//Prints a permutation
void print_perm(int *p, int n) 
{
    int i;
    for(i = 0; i < n; i++) 
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}
//Swaps two elements of an array
void swap(int *arr, int i, int j) 
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}