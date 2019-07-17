#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*  kp4 programming */

int main()
{
int n, i, j;
char q='Y';
int h;
int min1=101,min2=101,min;
srand(time(NULL));
printf("Enter the parametre of your array n \n");
scanf("%d", &n);
int a[n][n];
char str[4];
printf("Should I fill an array by myself?(YES or NO(it's up to
you))\n");
scanf("%s", &str);
if(toupper(q)==toupper(str[0]))
{
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
a[i][j]=rand()%100;
printf("%5d",a[i][j]);
}
printf("\n");
}
}
else
{
printf("write down %d numbers \n", n*n);
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)

{
scanf("%d", &h);
a[i][j]=h;
}
}
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
printf("%5d",a[i][j]);
}
printf("\n");
}
}
for(i=(n/2); i<n; i++)
{
for(j=n-1-i; j<=i; j++)
{
if(min2>a[i][j]) min2=a[i][j];
}
}
for(i=0; i<(n/2); i++)
{
for(j=i; j<=n-1-i; j++)
{
if(min1>a[i][j]) min1=a[i][j];
}
}
printf("The Min value of the first quarter is %d\n", min1);
printf("The Min value of the second quarter is %d\n", min2);
min=min1<min2?min1:min2;
printf("The winner is %d", min);
getch();
return 0;
}
