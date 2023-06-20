//AKKASANI YAGNESH REDDY
//CS21BTECH11003


#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

struct faculties{
    string name;
    int age;
    string gender;
    string department;
    struct faculties *next;
    struct faculties *prev;
};

typedef struct faculties *faculty;
struct collections{
    faculty head;
    faculty tail;
};
typedef struct collections *collection;

int Insert(collection c,string Name,int Age,string Gender,string Department){

    if(c->head==NULL || c->tail==NULL) {
        faculty New = (faculty)malloc(sizeof(struct faculties));
        New->name=Name;
        New->age=Age;
        New->gender=Gender;
        New->department=Department;
        New->next=NULL;
        New->prev=NULL;
        c->head=New;
        c->tail=New;
      }
      else{
   faculty New = (faculty)malloc(sizeof(struct faculties));
        New->name=Name;
        New->age=Age;
        New->gender=Gender;
        New->department=Department;
        New->prev=NULL;
        New->next=c->head;
        c->head->prev=New;
        c->head=New;       
      };
      return 1;
}

 faculty Find(collection c,string Name){
    
    faculty point = c->head;
    while(point!=NULL){
        if(point->name==Name) {return point;};
        point=point->next;
    }
     
     return NULL;

 }

  int Delete(collection c,string Name){

    faculty point=c->head;
    if(point->prev==NULL && point->name==Name) {c->head=point->next;free(point);return 1;}
    else{
        while(point->next!=NULL){
        if(point->name==Name) {
            point->prev->next=point->next;
            point->next->prev=point->prev;
            free(point);
            return 1;
        };
        point=point->next;
        };
        if(point->name==Name){
      point->prev->next=NULL;
      c->tail=point->prev;
      free(point);
      
       };

    };
    return 0;
}


int main() {
    int a=15;

    struct collections c;
    c.head=NULL;
    c.tail=NULL;

    faculty test;

    Insert(&c,"yagnesh",22,"OUT","phy");
     Insert(&c,"kaiser",21,"Female","arts");
     Insert(&c,"lonel",20,"Male","phil");

     //test = Find(&c,"yagnesh");

     Delete(&c,"yagnesh");
     cout<<c.head->name<<endl;
     cout<<c.head->next->name<<endl;
    //cout<<test->age<<endl;





    return 0;
}