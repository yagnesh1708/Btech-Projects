// AKKASANI YAGNESH REDDY CS21BTECH11003

#include <cstdlib>
#include <iostream>
#include<ctime>
using namespace std;
string Max="zzzzzzzz";
string Min="aaaaaaaa";
int height=0;

struct nodes{
string name;
int age;
string gender;
string department;
struct nodes* left;
struct nodes* right;
struct nodes* up;
struct nodes* down;

};

typedef struct nodes* node;




void Inc(int m,node New){

  node temp=New->left;
  node max=New->left;
  node min=New->right;
  node New1=new struct nodes;
       
  New1->name=New->name;
  New1->age=New->age;
  New1->gender=New->gender;
  New1->department=New->department;
  



  while(max->left!=NULL){
    max=max->left;
  }
  while(min->right!=NULL){
  min=min->right;
   }
  int r;

  r=rand()%2;

  if(r==1){

 

    if(m==height){
node min1 = new struct nodes;
 node max1 = new struct nodes;
  

    max1->name=Max;
    max1->left=NULL;
    max1->down=max;
    max1->up=NULL;
    max1->age=-1;
    max->up=max1;
    
   

      min1->name=Min;
    min1->right=NULL;
    min1->down=min;
    min1->up=NULL;
min1->age=-2;
    min->up=min1;

  

    max1->right=New1;
    New1->left=max1;
    New1->right=min1;
    min1->left=New1;
    New1->up=NULL;
   

      New->up=New1;
      New1->down=New;
    
    
    height=height+1;
      m=m+1;
      Inc(m,New1);
      return;

      
    }

    else if(m<height){


      while(temp->up==NULL){
        temp=temp->left;
      }
      temp=temp->up;
  if(temp->right!=NULL)    temp->right->left=New1;
      New1->right=temp->right;
      temp->right=New1;
      New1->left=temp;

      New1->down=New;
      New->up=New1;

      Inc(m+1,New1);

      return ;


      
    }

    
  }
  else if(r==0) {

    return ;

    
  }

return;

  
}







void Addlist(node *starts,string Name,int Age,string Gender,string Department){

  int m=1;

  node start=*starts;

  if(height==0)
  {
    node max = new struct nodes;

    max->name=Max;
    max->left=NULL;
    max->down=NULL;
    max->up=NULL;
    max->age=-1;
    
    node min = new struct nodes;

      min->name=Min;
    min->right=NULL;
    min->down=NULL;
    min->up=NULL;
    min->age=-2;

    node New =new struct nodes;

    New->name=Name;
    New->age=Age;
    New->gender=Gender;
    New->department=Department;

    max->right=New;
    New->left=max;
    New->right=min;
    min->left=New;
    New->up=NULL;
    New->down=NULL;
    
    
    height=1;
    *starts=max;
    Inc(m,New);
    

  return ;  
  }


   

   node New =new struct nodes;

    New->name=Name;
    New->age=Age;
    New->gender=Gender;
    New->department=Department;
    New->up=NULL;
    New->down=NULL;

  
  //search in list
  
node temp=start;
  while(temp->right!=NULL){
    if(temp->name>New->name && temp->right->name<New->name) {break;
        
    }
    else {temp=temp->right;}
  }
if(temp->right==NULL){
    temp=temp->left;
}
//Add
  temp->right->left=New;
  New->right=temp->right;
  temp->right=New;
  New->left=temp;
  
//Random increase

  Inc(m,New);
return ;
  
}

node search(node start,string Name){
    
    if(start==NULL){cout<<"list is empty"<<endl;return NULL ;}

    node temp=start;

    while(temp->up!=NULL){
        temp=temp->up;
    }

    while(temp!=NULL){

if(temp->right->name==Name)
{
    break;
}
else if(temp->right->name>Name)
{
    temp=temp->right;
}

else if(temp->right->name<Name){
    temp=temp->down;

}

}

if(temp==NULL) {cout<<"not present"<<endl;
}
else {return temp->right;}
    
    

    
    return NULL ;
    
}

void Delete(node *starts,string Name){
  node start=*starts;

node temp=search(start,Name);
node prev=temp->left;
node next=temp->right;
node temp1;
node temp2;


while(temp!=NULL){

  if(prev->left==NULL && next->right==NULL){
  height=height-1;
 if(prev->down!=NULL) {prev->down->up=prev->up;}
 else *starts=NULL;
 if(next->down!=NULL)  {next->down->up=next->up;}

 else *starts=NULL;
}


temp1=temp->left;
  temp2=temp->right;
  temp1->right=temp2;
  temp2->left=temp1;
  temp1=temp;

      temp=temp->down;
 
    free (temp1);
  
}

return;

}


int main(){

srand(time(NULL));
  node testp=NULL;
  int i;
  

  Addlist(&testp,"f",19,"M","P");
   Addlist(&testp,"m",19,"M","P");
   Addlist(&testp,"c",19,"M","P");
   Addlist(&testp,"b",19,"M","P");
   Addlist(&testp,"x",19,"M","P");
   Addlist(&testp,"n",19,"M","P");

  node testp1=testp;

//  node temp= search(testp,"F");
// cout<<temp->name<<endl;

cout<<height<<endl;

 i=1;

node temp=testp1;

 while(temp!=NULL){
     testp=temp;

  cout<<i<<"-level  ";
  while(testp->right->right!=NULL){
   
    cout<<testp->right->name<<" ";
    testp=testp->right;
  }
  cout<<endl;
  
    i=i+1;
 

  temp=temp->up;

 }

  
  Delete(&testp1,"f");
  cout<<height<<endl;


 
 
 
 i=1;

 temp=testp1;

 while(temp!=NULL){
     testp=temp;

  cout<<i<<"-level  ";
  while(testp->right->right!=NULL){
   
    cout<<testp->right->name<<" ";
    testp=testp->right;
  }
  cout<<endl;
  
    i=i+1;
 

  temp=temp->up;

 }


return 0;
  
}