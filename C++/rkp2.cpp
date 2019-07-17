
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch,
system("pause") or input loop */
class Date{
int d,m,y;
public:
Date();
Date(int,int,int);
Date(char *);
// Date(int);
// Date(int,int);
Date(Date &);

~Date();
Date& set_d(int);
Date& set_m(int);
Date& set_y(int);
int get_d(){return d; };
int get_m(){return m; };
int get_y(){return y; };
void print();
};
Date::Date(int a, int b, int c){
d=a; m=b; y=c;
}
Date::Date(){
d=0,m=0,y=0;
}
Date::Date(Date &a){
d=a.d,m=a.m,y=a.y;
}

Date::Date(char *s){
printf("%s", s);
}
Date::~Date(){
d=0,m=0,y=0;
}
Date& Date::set_d(int a){
d=a;
return *this;

}
Date& Date::set_m(int a){
m=a;
return *this;
}
Date& Date::set_y(int a){
y=a;
return *this;
}
void Date::print(){
printf("day %d month %d year %d\n", d, m, y);
}
class Person {
char * last_name;
char * first_name;
char * phone_number;
Date birthday;
public:
Person();// dobro
Person(char *,char *,char *,Date);// dobro
Person(Person &);//dobro
~Person();// dobro
char * get_last_name(){ return last_name;}// ready
char * get_first_name(){ return first_name;}// ready
char * get_phone_number(){ return phone_number;}// steady
Date get_brthday(){ return birthday;}// go
Person& set_last_name(char *);
Person& set_first_name(char *);
Person& set_phone_number(char *);
Person& set_birthday(Date);
void printp();// dobro

};
Person::Person(){
last_name= new char [10];
first_name= new char[10];
phone_number= new char [10];
strcpy(last_name, "no info");
strcpy(first_name, "no info");
strcpy(phone_number, "no info");
birthday;
}
Person::Person(char * last1,char * first1, char * phone, Date dmy){
last_name= new char [strlen(last1)+1];
first_name= new char [strlen(first1)+1];
phone_number= new char [strlen(phone)+1];
strcpy(last_name, last1);
strcpy(first_name, first1);
strcpy(phone_number, phone);
birthday=dmy;
}
Person::~Person(){
delete last_name;
delete first_name;
delete phone_number;
}
Person::Person(Person &a){
last_name= new char [strlen(a.last_name)+1];
first_name= new char [strlen(a.first_name)+1];
phone_number= new char [strlen(a.phone_number)+1];
strcpy(last_name, a.last_name);
strcpy(first_name, a.first_name);
strcpy(phone_number, a.phone_number);
birthday=a.birthday;
}

Person& Person::set_first_name(char *s){
first_name= new char [strlen(s)+1];
strcpy(first_name, s);
return *this;
}
Person& Person::set_last_name(char *s){
last_name= new char [strlen(s)+1];
strcpy(last_name, s);
return *this;
}
Person & Person::set_phone_number(char *s){
phone_number= new char [strlen(s)+1];
strcpy(phone_number, s);
return *this;
}
void Person::printp(){
printf ("%s %s %s ",last_name,first_name,phone_number );
birthday.print();
}
int main(int argc, char** argv) {
Date d1;
Person obj1, obj2("33","44","33", d1);
obj1=obj2;
obj1.printp();
getch();
return 0;
}
