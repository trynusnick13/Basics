#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*  kp3 */

int co=0,sw=0, i, temp;//initialization of counters and the most popular variables
int printf_array(int a[], int n)
{
int i;
for(i = 0; i < n; i++) printf("%5d",a[i]);
}
void MAX_HEAPIFY(int *A, int i, int n) // Used pointers instead of a[] and it
worked??? The equestion is why a[] didn't work minding the fact it is a pointer as well
{
int temp,left,right,largest;
left=2*(i+1)-1;
right=2*(i+1);
//sw=sw+1;//
if ((left < n )&& (A[left] > A[i]))
{
largest=left;
sw++;
}
else
{
largest=i;
sw++;
}
co++;
if ((right < n )&& (A[right] > A[largest]))
{
largest=right;
sw++;
}
if (largest!=i)
{
temp=A[i];
A[i]=A[largest];
A[largest]=temp;
sw=sw+1;
MAX_HEAPIFY(A, largest, n);
}
co++;
}
void BUILD_MAX_HEAP (int *A, int n)//build a tree
{
for (i = n/2; i >= 0; i--)
{
MAX_HEAPIFY(A, i, n);
}
}
void HEAPSORT(int *A, int n)//the sorting by itself
{
int hs = n;
BUILD_MAX_HEAP(A, n);
sw=sw+2;
for (i = n-1; i > 0; i--)
{
temp=A[0];
A[0]=A[i];
A[i]=temp;

hs--;
sw=sw+7;
MAX_HEAPIFY(A, 0, hs);
}
}
int counting(int a[],int n, int k)
{
int b[n], c[k],i,j;
for(i=0;i<=k;i++)
{
c[i]=0;sw++;
}
for(j=0;j<n;j++)
{
c[a[j]]=c[a[j]]+1;sw++;
}
for(i=1;i<k;i++)
{
c[i]=c[i]+c[i-1];sw++;
}
for(j=n-1;j>=0;j--)
{
b[c[a[j]]-1]=a[j];
c[a[j]]--;
sw++;
}
// printf_array(b,n);
}
int bubble(int a[],int n)
{
int temp,j,i;
int k=n-1;
for(j=0;j<k;j++)
{
for(i=0;i<n;i++)
{
if(a[i+1]<a[i])
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
sw+=3;
}
co++;
}
}
}
int best_array(int a[], int n){
int i;
for( i=0; i<n; i++) a[i] = i;
}
int avg_array(int a[], int n){
int i;
srand(time(NULL));
for(i = 0; i < n; i++) a[i] = rand()%100;

}
int worst_array(int a[], int n){
int i;
for( i=0; i<n; i++) a[i] = n - 1 - i;

}
int main()
{
int n=1000, j=1;
int array[n];
//worst_array(array,n);
for( j=0; j<1000;j++)
{
avg_array(array, n);
HEAPSORT(array, n);// HEAPSORT(array, n); counting(array, n, 100);
}
// printf_array(array,n);
// HEAPSORT(array, n);
// printf_array(array,n);
printf("Swaps %d\n", sw/1000); //geting compares in the loop for bubble
demands extra dividing by 2
printf("Quantaty of compares %d\n", co/1000);
getch();
return 0;
}
