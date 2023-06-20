//AKKASANI YAGNESH REDDY
//CS21BTECH11003


#include<iostream>
#include<cstdlib>
using namespace std;

struct faculties {

    string name;
    int age;
    string gender;
    string department;
    short int left_thread;
    short int right_thread;
    struct faculties *leftchild;
    struct faculties *rightchild;
};

typedef struct faculties *faculty;

int insert(faculty *Base,string Name,int Age,string Gender,string Department) {


    faculty base=*Base;
    faculty temp;
    faculty New = new struct faculties;

  New->name=Name;
  New->age=Age;
  New->gender=Gender;
  New->department=Department;
  New->left_thread=1;
  New->right_thread=1;

    if(base==NULL){
      
      faculty head = new struct faculties;
      head->name="head";
      head->left_thread=0;
      head->right_thread=0;
      head->leftchild=New;
      head->rightchild=head;
      *Base=head;

      New->leftchild=head;
      New->rightchild=head;
      
                }


 else{
    faculty New = new struct faculties;

  New->name=Name;
  New->age=Age;
  New->gender=Gender;
  New->department=Department;
  New->left_thread=1;
  New->right_thread=1;

  temp=base->leftchild;

  while(temp!=base){

  if(temp->name>New->name){


    if(temp->left_thread!=1){
        temp=temp->leftchild;
 
  }
    else{

      New->leftchild=temp->leftchild;
        New->rightchild=temp;
        temp->leftchild=New;
        temp->left_thread=false;
         return 1; 
    }
  }

  else{
    if(temp->right_thread!=1){
        temp=temp->rightchild;
 
  }
    else{

      New->leftchild=temp;
        New->rightchild=temp->rightchild;
        temp->rightchild=New;
        temp->right_thread=false;
         return 1; 
    }
}
 };
   }
   return 0;
    }



 faculty search(faculty *Base,string Name){

    faculty base=*Base;
    faculty temp;

    if(base==NULL) return NULL;
    temp=base->leftchild;
     while(temp!=base){

        if(temp->name==Name) {
              return temp;
       }

  else if(temp->name>Name){


    if(temp->left_thread!=1){
        temp=temp->leftchild;
 
  }
    else{
           return NULL; 
    }
  }

  else{
    if(temp->right_thread!=1){
        temp=temp->rightchild;
 
  }
    else{
return NULL; 
    }
  }
  }
  return NULL;
 }

 void inorder(faculty *Base){

    faculty base=*Base;
    faculty temp;
    temp=base->leftchild;

    while(temp!=base){

        while(temp->left_thread!=1)
          temp=temp->leftchild;

          cout<<temp->name;

          while(temp->right_thread==1)
             {
                temp=temp->rightchild;
                 if(temp==base) break;
                 cout<<temp->name;
                 }
             temp=temp->rightchild;


    }
  }




 int Delete(faculty *Base,faculty temp,faculty parent){
  faculty base=*Base;
  faculty temp2;
   if(temp->left_thread==1 && temp->right_thread==1)
         {
                if(parent==base) {
                 base->leftchild=base;
                 base->left_thread=1;
               
                free(temp);
                return 0;}

                if(parent->leftchild==temp)
                {
                 parent->leftchild=temp->leftchild;
                 parent->left_thread=1;
                
                }
                else if(parent->rightchild==temp)
                {
                 parent->rightchild=temp->rightchild;
                 parent->right_thread=1;
              
                }
                  free(temp);
                 return 0 ;

         }   

         else if(temp->left_thread==0 && temp->right_thread==0) 
          {
             temp2=temp->rightchild;
             parent=temp;
             while(temp2->left_thread!=1) {
                 parent=temp2;
                 temp2=temp2->leftchild;
                }
                temp->age=temp2->age;
                temp->name=temp2->name;
                temp->gender=temp2->gender;
                temp->department=temp2->department;
                 temp=temp2;
                 Delete(Base,temp,parent);
                 return 0;
          }

          else if(temp->left_thread==1 && temp->right_thread==0)
        {
            temp2=temp->rightchild;
            parent=temp;
            while(temp2->left_thread!=1)
            {parent=temp2;
            temp2=temp2->leftchild;
              }
              temp->age=temp2->age;
                temp->name=temp2->name;
                temp->gender=temp2->gender;
                temp->department=temp2->department;
             temp=temp2;
             Delete(Base,temp,parent);
             return 0;
           

        }

        else if(temp->left_thread==0 && temp->right_thread==1)
         {
         
          parent=temp;
             temp2=temp->leftchild;
             while(temp2->right_thread!=1)
            {parent=temp2;
            temp2=temp2->rightchild;
              }
               temp->age=temp2->age;
                temp->name=temp2->name;
                temp->gender=temp2->gender;
                temp->department=temp2->department;
             temp=temp2;
              Delete(Base,temp,parent);
            
            
           
            return 0 ;
           
}
return 0;
}

faculty parentsearch(faculty *Base,string Name)
  
   {
     faculty base=*Base;
     faculty parent=NULL;
     faculty temp=NULL;
     faculty temp2;

     if(base==NULL) return parent ;
     temp=base->leftchild;
     parent=base;
      while(temp!=base){

         if(temp->name==Name) {
               break;
        }

   else if(temp->name>Name){


     if(temp->left_thread!=1){
        parent=temp;
         temp=temp->leftchild;
 
   }
     else {
            temp=NULL;
            break; 
     }
   }

   else if(temp->name<Name){
     if(temp->right_thread!=1){
        parent=temp;
         temp=temp->rightchild;
 
   }
     else{
 temp=NULL;
 break; 
     }
   }
   }

   return parent;
}






 




int calldelete(faculty *Base,string Name)
 { faculty parent,temp;
  parent=parentsearch(Base,Name);

  temp=search(Base,Name);
  if(temp==NULL) {return 0;}
  else Delete(Base,temp,parent);
  
return 0;
 }

  

int main(){

    faculty head;
    head=NULL;
    

     insert(&head,"M",19,"MALE","PHY");
    insert(&head,"G",19,"MALE","PHY");
    insert(&head,"T",19,"MALE","PHY");
    insert(&head,"D",19,"MALE","PHY");
    insert(&head,"N",19,"MALE","PHY");
    insert(&head,"R",19,"MALE","PHY");
    insert(&head,"Q",19,"MALE","PHY");
    insert(&head,"A",19,"MALE","PHY");
    insert(&head,"F",19,"MALE","PHY");
    insert(&head,"X",19,"MALE","PHY");
    insert(&head,"E",19,"MALE","PHY");
    insert(&head,"W",19,"MALE","PHY");
    insert(&head,"P",19,"MALE","PHY");


    
    inorder(&head);
    cout<<endl;
    calldelete(&head,"Q");
    calldelete(&head,"X");
     calldelete(&head,"W");
     calldelete(&head,"T");
    
        //inorder(&head);
   //cout<<head->leftchild->rightchild->leftchild->rightchild->rightchild->rightchild->leftchild->rightchild->name;
    inorder(&head);
    cout<<endl;

    // faculty test=search(&head,"Z");
    // cout<<test->name<<endl;
    
    //  cout<<head->leftchild->rightchild->(*rightchild)<<endl;
    //   cout<<head->leftchild->rightchild->name<<endl;




    return 0;
}