

#include <stdio.h>
#include <stdlib.h>

#include <conio.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch,
system("pause") or input loop */
typedef struct Pers{
char first_name[20], last_name[20], phone_number[20];
}Person;
typedef struct per_list{
Person a;
struct per_list * next;
}Person_list;
// void add_info(Person a){
// char b[20];
// char c[20];
// char v[20];
// printf("Enter first name, last name and phone number\n");
// scanf("%s %s %s", b, c, v);
// strcpy(a.first_name, b );
// strcpy(a.last_name, c);
// strcpy(a.phone_number, v );
// printf("%s %s %s ", a.first_name, a.last_name, a.phone_number);
//
// }
void add_info(Person a){
printf("Enter first name, last name and phone number\n");
scanf("%s %s %s", a.first_name, a.last_name, a.phone_number);
printf("%s %s %s ", a.first_name, a.last_name, a.phone_number);
}

// void add_to_head(Person_list * h){
Person_list * add_to_head(Person_list * h){
Person b;
Person_list * k = new Person_list;

k->next=h;
printf("Enter first name, last name and phone number\n");
scanf("%s %s %s",k->a.first_name, k->a.last_name, k->a.phone_number);
printf("%s %s %s ", k->a.first_name,k->a.last_name, k->a.phone_number);
return k;
}
Person_list * last_pointer(Person_list * h){
while(h->next){
h=h->next;
}
return h;
}
void add_to_tail(Person_list * h){
Person b;
Person_list * k = new Person_list;
h=last_pointer(h);
h->next=NULL;
h->next=k;
printf("Enter first name, last name and phone number\n");
scanf("%s %s %s",k->a.first_name, k->a.last_name, k->a.phone_number);
printf("%s %s %s \n", k->a.first_name,k->a.last_name, k->a.phone_number);
}
void print_list(Person_list * h){
Person_list * k = h;
while(h){
printf("%s %s %s \n", h->a.first_name,h->a.last_name, h->a.phone_number);
printf("\n");
h=h->next;

}
}

void k_to_j(int k, int j, Person_list * h ){
Person_list * temp=h;
Person_list * p = new Person_list;
Person_list * l=h;
l=h;
int i=1,m=1;
while(i<k){
h=h->next; i++; }
while(m<j) {
temp=temp->next; m++; }
strcpy(p->a.first_name, temp->a.first_name);
strcpy(p->a.last_name, temp->a.last_name);
strcpy(p->a.phone_number, temp->a.phone_number);
////////////////////////////////////////////
strcpy(temp->a.first_name, h->a.first_name);
strcpy(temp->a.last_name, h->a.last_name);
strcpy(temp->a.phone_number, h->a.phone_number);
////////////////////////////////////////////
strcpy(h->a.first_name, p->a.first_name);
strcpy(h->a.last_name, p->a.last_name);
strcpy(h->a.phone_number, p->a.phone_number);
print_list(l);
// printf("%s %s %s \n", temp->a.first_name,temp->a.last_name, temp-
>a.phone_number);
}
//
void exterminating_before_k(int k, Person_list * h ){
Person_list * p = h ;
Person_list * l = h ;
Person_list * m = h ;
int i=1,j=1;
printf("Enter the number greater than 1\n");
if(k==2){
p=h->next;
delete h;
print_list(p);

}
else {
while (i<(k-2)) {
m=m->next; i++;}

while(j<k-1){
p=p->next;
j++;
}
m->next=p->next;
delete p;
print_list(l);
}
}
Person_list * clear_list(Person_list * h){

Person_list * x= h;
Person_list * temp;
while (temp)
{
temp = x -> next;
delete x;
x = temp;
}
return temp;
}
void outpf( Person_list * h){
FILE *fp;
char name[20]="C://new//new.text";
fp=fopen(name, "w");
while(h){
fprintf(fp,"%s %s %s \n", h->a.first_name,h->a.last_name, h-
>a.phone_number);
printf("\n");
h=h->next;
}

fclose(fp);
}
int main() {
Person_list * h = new Person_list;
Person_list * temp=h;

h->next=NULL;
printf("Enter first name, last name and phone number\n");
scanf("%s %s %s",h->a.first_name, h->a.last_name, h->a.phone_number);
printf("%s %s %s \n", h->a.first_name,h->a.last_name, h->a.phone_number);
// char b[20];
printf("\n");
h=add_to_head(h);
add_to_tail(h);
printf("\n");
printf("\n");
print_list(h);
//exterminating_before_k(3,h);
// k_to_j(1,3,h);

// printf("Enter first name, last name and phone number\n");
//
// scanf("%s", b);
// strcpy(a.first_name, b );
// printf("%s ", a.first_name);

// strcpy(h->a.last_name, "Trynus");
// strcpy(h->a.phone_number, "0505531372");
// printf("%s %s %s", h->a.first_name, h->a.last_name, h->a.phone_number);
outpf(h);
h=clear_list( h);
print_list(h);
printf("the list is clear");

getch();
return 0;

}
