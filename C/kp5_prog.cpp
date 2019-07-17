#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*  kp5 */

	int main()
	{
		int n, i, j,p,max,temp, k=0;
		char q='Y';
		int b[k];
		int c[k];
		int h;
		int sum=0;

		srand(time(NULL));
		
		printf("Enter the parametre of your array n \n");
		scanf("%d", &n);
		
		int a[n];
		
		char str[5];
		printf("Should I fill an array by myself?(YES or NO(it's up to you))\n");
		scanf("%s", &str);
	if(toupper(q)==toupper(str[0]))

	{
		
		for(i=0; i<n; i++)
		
			{
				
				a[i]=rand()%10;
				printf("%5d",a[i]);
			
			}
			
		printf("\n");
	
	}
	
		else
		
	{
		
		printf("write down %d numbers \n", n);
		
		for(i=0; i<n; i++)
		
	{
		
		scanf("%d", &h);
		a[i]=h;
		
	}
	
	for(i=0; i<n; i++)
	
	{
		
	printf("%5d",a[i]);
	
	}
	
}

	printf("\n");
	printf("write down p \n");
	scanf("%d", &p);
	
	for(i=0; i<n;i++)
{
if(p<a[i])
{
b[k]=a[i];
c[k]=i;
k++;
}
}
int m=k, d[m], key;
j=k;
for(j=0;j<k;j++)
{
max=b[j];
for(i=j+1;i<k;i++)
{
if(b[i]>max)
{
max=b[i];
p=i;
}
}
temp=b[j];
b[j]=max;
b[p]=temp;
}
//d[0]=b[0];
/*for(k=0;k<j;k++)
{

key=b[k];
m=k-1;
while((m>=0)&&(d[m]<key))
{
d[m+1]=d[m];
m--;
}
d[m+1]=key;
}*/
printf("\n");

for(i=0; i<k;i++)
{
a[c[i]]=b[i];
}
printf("\n");
for(i=0; i<n; i++)
{
printf("%5d",a[i]);
}
printf("\n");
getch();
return 0 ;
}
