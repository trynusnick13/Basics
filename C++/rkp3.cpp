#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch,
system("pause") or input loop */
using namespace std;
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
int get_d(){ return d; };

int get_m(){ return m; };
int get_y(){ return y; };
void print();
};
class Person {
char * last_name;
char * first_name;
char * phone_number;
Date birthday;
public:
Person();// dobro
Person(char *,char *,char *,Date);// dobro
Person(char * ,char * ,char * ,int ,int ,int );
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

class Student: public Person{
char * group;
int course;
int rate;
static int count1;
public:
Student();//
Student(char*, int, int);//char * ,char * ,char * ,int ,int ,int
Student(char*, int, int,char * ,char * ,char * ,int ,int ,int );
Student(Student &);//
~Student();//
char * get_group();

int get_course();
int get_rate();
Student& set_group(char *);
Student& set_course(int);
Student& set_rate(int);
void print();
};
class Rabotyaga: public Person{
char * position;
int salary;
int experience;
static int count;
public:
Rabotyaga();//
Rabotyaga(char*, int, int);
Rabotyaga(Rabotyaga &);//
Rabotyaga(char*, int, int,char * ,char * ,char * ,int ,int ,int );//
~Rabotyaga();//
char * get_position();//
int get_salary();//
int get_experience();//
Rabotyaga& set_position(char *);
Rabotyaga& set_salary(int);
Rabotyaga& set_experience(int);
void print();
};

int Rabotyaga::count=0;
int Student::count1=0;
Rabotyaga::Rabotyaga(){
position = new char [10];
strcpy(position, "no info");
salary=0;
experience=0;
cout<<"Cons.Rabotyaga()\n";
count++;
}

Rabotyaga::~Rabotyaga(){
delete position;
cout<<"Destr.Rabotyaga\n";
count--;
}
Rabotyaga::Rabotyaga(char*pos, int sal, int exp): salary(sal),
experience(exp){
position = new char [strlen(pos)+1];
strcpy(position, pos);
cout<<"Cons.Rabotyaga(par)\n";
count++;
}
Rabotyaga:: Rabotyaga(Rabotyaga &a): salary(a.salary),
experience(a.experience) {
position = new char [strlen(a.position)+1];
strcpy(position, a.position);
cout<<"Copy.Rabotyaga\n";
}
Rabotyaga:: Rabotyaga(char*pos, int sal, int exp,char *last1 ,char *
first1,char *phone ,int d,int m,int y):salary(sal), experience(exp),
Person(last1 , first1, phone, d, m, y )
{
position = new char [strlen(pos)+1];
strcpy(position, pos);
// last_name= new char [strlen(last1)+1];
// first_name= new char [strlen(first1)+1];
// phone_number= new char [strlen(phone)+1];
// strcpy(last_name, last1);
// strcpy(first_name, first1);
// strcpy(phone_number, phone);
cout<<"Cons.Rabotyaga\n";
count++;
}
char * Rabotyaga:: get_position(){
return position;

}

int Rabotyaga:: get_salary(){
return salary;
}
int Rabotyaga:: get_experience(){
return experience;
}
Rabotyaga& Rabotyaga:: set_position(char * s){
if(!s)delete s;
position= new char [strlen(s)+1];
strcpy(position, s);
return *this;
}
Rabotyaga& Rabotyaga:: set_salary(int i){
salary = i;
return *this;
}
Rabotyaga& Rabotyaga:: set_experience(int i){
experience = i;
return *this;
}
void Rabotyaga :: print(){
Person::printp();
cout<<position<<" "<<salary<<" "<<experience;
}
/////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
Student::Student(){

group = new char [10];
strcpy(group, "no info");
course=1;
rate=0;
cout<<"Cons.Student()\n";
count1++;
}
Student::~Student(){
delete group;
cout<<"Destr.Student\n";
count1--;
}
Student::Student(char*pos, int sal, int exp): course(sal), rate(exp){
group = new char [strlen(pos)+1];
strcpy(group, pos);
cout<<"Cons.Student(par)\n";
count1++;
}
Student:: Student(Student &a): course(a.course), rate(a.rate) {
group = new char [strlen(a.group)+1];
strcpy(group, a.group);
cout<<"Copy.Student\n";
}
Student:: Student(char*pos, int sal, int exp,char *last1 ,char * first1,char
*phone ,int d,int m,int y):course(sal), rate(exp),
Person(last1 , first1, phone, d, m, y )
{
group = new char [strlen(pos)+1];
strcpy(group, pos);
// last_name= new char [strlen(last1)+1];
// first_name= new char [strlen(first1)+1];
// phone_number= new char [strlen(phone)+1];
// strcpy(last_name, last1);
// strcpy(first_name, first1);
// strcpy(phone_number, phone);
cout<<"Cons.Student(par)\n";

count1++;
}
char * Student:: get_group(){
return group;
}

int Student:: get_course(){
return course;
}
int Student:: get_rate(){
return rate;
}
Student& Student:: set_group(char * s){
if(!s)delete s;
group= new char [strlen(s)+1];
strcpy(group, s);
return *this;
}
Student& Student:: set_course(int i){
course = i;
return *this;
}
Student& Student:: set_rate(int i){
rate = i;
return *this;
}
void Student :: print(){
Person::printp();
cout<<group<<" "<<course<<" "<<rate<<count1;

}

///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
Date::Date(int a, int b, int c){
d=a; m=b; y=c;
cout<<"Cons.Date\n";
}
Date::Date(){
d=0,m=0,y=0;
cout<<"Cons.Date\n";
}
Date::Date(Date &a){
d=a.d,m=a.m,y=a.y;
cout<<"Copy.Date\n";
}

Date::Date(char *s){
printf("%s", s);
cout<<"Cons.Date\n";
}
Date::~Date(){
cout<<"Destr.Date\n";
// d=0,m=0,y=0;
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

Person::Person(){
last_name= new char [10];
first_name= new char[10];
phone_number= new char [10];
strcpy(last_name, "no info");
strcpy(first_name, "no info");
strcpy(phone_number, "no info");
birthday;
cout<<"Cons.Person()\n";
}
Person::Person(char * last1,char * first1, char * phone, Date dmy){
last_name= new char [strlen(last1)+1];
first_name= new char [strlen(first1)+1];
phone_number= new char [strlen(phone)+1];
strcpy(last_name, last1);
strcpy(first_name, first1);
strcpy(phone_number, phone);
birthday=dmy;
cout<<"Cons.Person(par)\n";
}

Person::Person(char *last1 ,char * first1,char *phone ,int d,int m,int y
):birthday(d,m,y){
last_name= new char [strlen(last1)+1];
first_name= new char [strlen(first1)+1];
phone_number= new char [strlen(phone)+1];
strcpy(last_name, last1);
strcpy(first_name, first1);
strcpy(phone_number, phone);
cout<<"Cons.Person(par)\n";
}

Person::~Person(){
delete last_name;
delete first_name;
delete phone_number;
cout<<"Destr.Person\n";
}
Person::Person(Person &a){
last_name= new char [strlen(a.last_name)+1];
first_name= new char [strlen(a.first_name)+1];
phone_number= new char [strlen(a.phone_number)+1];
strcpy(last_name, a.last_name);
strcpy(first_name, a.first_name);
strcpy(phone_number, a.phone_number);
birthday=a.birthday;
cout<<"Copy.Person\n";
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
Person & Person::set_birthday(Date s){
birthday.set_d(s.get_d());
birthday.set_m(s.get_m());
birthday.set_y(s.get_y());
return *this;
}
void Person::printp(){
printf ("%s %s %s ",last_name,first_name,phone_number );
birthday.print();
}

int main(int argc, char** argv) {
Date d1(1,23,4);
Person obj1, obj2("33","44","33", d1);
obj1=obj2;
obj1.set_first_name("jjjj");
obj1.printp();
obj2.printp();
Rabotyaga Arsen( "fff", 33,44);
cout<<Arsen.get_salary();
Arsen.print();
Student Avram;
Avram.print();
Avram.set_group("ncncnc");
Avram.print();
getch();
return 0;
}

