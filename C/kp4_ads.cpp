#include <stdio.h>
#include <conio.h>
//#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>

/*  linked list ads    */

typedef struct student_list{
char tl[7]; //title
int am; //amount
struct student_list * next;
}st_list; //student list
st_list * create_node(char k [] , int p)
{

st_list * result=(st_list*)malloc(sizeof(st_list));
strcpy(result->tl, k);
result->am=p;
result->next=NULL;
return result;

}
st_list * last_pointer(st_list * head) {
while (head -> next) {
head = head -> next;
}
return head;
}
void add_to_tail(st_list * head, char b[], int u)
{
//st_list * last = head; //
st_list * last = last_pointer(head);
st_list * result =create_node(b, u);
last -> next = result;
}
/*void min_to_tail(st_list * head)
{
int min=100;
//int k=0;
st_list * t = head;
st_list * k;
st_list * prev1;
st_list * prev2;

st_list * last = last_pointer(head);
st_list * p = last;
while (t->next)
{
if((t->am)<min)
{
min=t->am;
k=t;
}
t=t->next;
}
prev1->next= k;
prev2->next= last;
prev1->next=last;
last->next=k->next;
prev2->next= k;
k->next=NULL;
}*/
void min_to_tail(st_list * head)
{
int min=INT_MAX;
//int k=0;
st_list * t = head;
st_list * k;
int temp_int;char temp_char[7];
st_list * last = last_pointer(head);
while (t -> next)
{
if((t -> am) < min)
{
min=t -> am;
k=t;
}
t=t->next;
}
temp_int = k->am;
strcpy(temp_char, k->tl);
k->am=last->am;
last->am=temp_int;
strcpy(k->tl, last->tl);
strcpy(last->tl, temp_char);
// strcpy(k->tl, last->tl);
}
void print_list( st_list * temp) {
while(temp)
{
printf("%s: %d", temp->tl,temp->am);
temp = temp -> next;
}
}
st_list * exterminating_head(st_list * head)
{
st_list * t = head -> next;
free (head);
return t;
}
st_list * clear_list(st_list * head)
{

st_list * x= head;
st_list * temp;
while (temp)
{
temp = x -> next;
free(x);
x = temp;
}
return temp;
}
int main()
{
/*Every comment in "main" consits of the implementation of the particular
function.
Deleting the cooment signs, you activate the function. Mind about
incompatibility of the specific bunch of functions */
st_list * head=(st_list*)malloc(sizeof(st_list));
head -> next=NULL;
strcpy(head -> tl, "KA-81");
head->am=57;
add_to_tail(head,"Ka-84",13);
add_to_tail(head,"Ka-83",23819);
//head= exterminating_head(head);
//head = clear_list(head);
st_list * temp=head;
while(temp)
{
printf("%s %d\n", temp->tl,temp->am);
temp=temp->next;
}
/* min_to_tail(head);
st_list * m=head;
printf("\n");
while(m)
{
printf("%s %d\n", m->tl,m->am);
m=m->next;
}*/
//print_list(temp);
getch();
return 0;
}
