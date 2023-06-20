// AKKASANI YAGNESH REDDY
// CS21BTECH11003

#include <iostream>
#include <cstdlib>
using namespace std;
 

struct faculties {
     string name;
     int age;
     string gender;
     string department;
     struct faculties *next;
};
typedef struct faculties *faculty;

struct collections{
    faculty head;
};
typedef struct collections *collection;

int AddToCollection(collection c,string Name,int Age,string Gender,string Department){
faculty New = (faculty)malloc(sizeof(struct faculties));
New->name=Name;
New->age=Age;
New->department=Department;
New->gender=Gender;
New->next=c->head;
c->head=New;
return 1;
}

faculty Find(collection c,string Name){

    faculty point=c->head;
    while(point!=NULL){
        if(point->name==Name) return point;
        point=point->next;

    };
    return NULL;
}

int Delete(collection c,string Name){

    faculty prev_point=c->head;
    faculty point=prev_point->next;
    if(prev_point->name==Name) {c->head=prev_point->next;free(prev_point);return 1;}
    else{
        while(point!=NULL){
        if(point->name==Name) {
            prev_point->next=point->next;
            free(point);
            return 1;
        };
        prev_point=point;
        point=prev_point->next;
    };
    };
    return 0;
}

int main() {


     faculty test;
     struct collections c;
     c.head=NULL;
     AddToCollection(&c,"yagnesh",22,"OUT","phy");
     AddToCollection(&c,"kaiser",21,"Female","arts");
     AddToCollection(&c,"lonel",20,"Male","phil");
     Delete(&c,"kaiser");
     cout<<c.head->next->name<<endl;     
   
     return 0;


}

