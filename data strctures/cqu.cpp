//AKKASANI YAGNESH REDDY
//CS21BTECH11003


#include <iostream>
using namespace std;
#define length 5


int add(int *ages,int *front,int *rear,int age){

    if((*front)==-1 && (*rear) ==-1){
        ages[0]=age;
        *front=0;
        *rear=0; }
  else
       {if((((*rear)+1)%length)==(*front)){return 0;};

        ages[(((*rear)+1)%length)]=age;
        *rear=(((*rear)+1)%length);

       } ;
       return 0;
}

int Delete(int *ages,int *front,int *rear){
      if((*front)==-1 && (*rear) ==-1){
        return 0;}
        else if(*front==*rear){
            *front=-1;
            *rear=-1;}
             else{  *front=(((*front)+1)%length);

            };
            return 0;
}



int main(){

int age[length];

int front=-1;
int rear =-1;

 add(&age[0],&front,&rear,13);
 add(&age[0],&front,&rear,12);
 add(&age[0],&front,&rear,11);
 add(&age[0],&front,&rear,10);
 add(&age[0],&front,&rear,9);
 add(&age[0],&front,&rear,8);
Delete(&age[0],&front,&rear);
 cout<<front<<endl<<rear<<endl<<age[0]<<endl;



 

 return 0;

}