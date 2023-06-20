#include <iostream>
#include <cstdlib>
using namespace std;

struct faculties{
    string name;
    int age;
    string gender;
    string department;
    struct faculties *leftchild;
    struct faculties *rightchild;
};

typedef struct faculties *faculty;

 struct collections{
   faculty root;
};

typedef struct collections *collection;


int AddToTree(faculty *base,faculty New){

  if((*base)==NULL){
    (*base)=New;
    
    return 1;

  };

  if((*base)->name<New->name)
  {
    AddToTree(&((*base)->rightchild),New);
    
    return 1;
  }
   else if((*base)->name>New->name)
  {
    AddToTree(&((*base)->leftchild),New);
    return 1;
  };

  return 1;

}
 
 typedef struct collections *collection;

int AddToCollection(collection c,string Name,int Age,string Gender,string Department) {

  faculty New = new struct faculties;

  New->name=Name;
  New->age=Age;
  New->gender=Gender;
  New->department=Department;
  New->leftchild=NULL;
  New->rightchild=NULL;

  AddToTree(&(c->root),New);

  return 1;

}


faculty FindInTree(faculty *base,string Name){

if((*base)==NULL) {return NULL;};

if((*base)->name==Name) {return *base;};
if((*base)->name>Name) {return FindInTree(&((*base)->leftchild),Name);}
else if((*base)->name<Name) {return FindInTree(&((*base)->rightchild),Name); };
 return NULL;



}




faculty Find(collection c,string Name){
return FindInTree(&(c->root),Name);
}


// void DeleteInTree(faculty *parent,string lr,faculty *base,string Name){

 
// cout<<"1"<<endl;
// if((*base)==NULL) {return ;};

// if((*base)->name==Name) {
//   faculty *temparory;faculty *parent2;

//   if ((*base)->leftchild==NULL && (*base)->rightchild==NULL){


//     if(lr=="c") {faculty temp=(*base);(*base)=NULL;free (temp);return ;} 
//     else if(lr=="l") {(*parent)->leftchild=NULL;free (*base);return ;}
//     else if (lr=="r") {(*parent)->rightchild=NULL;free (*base);return ;};

    
//   }

//   else if(((*base)->leftchild==NULL && (*base)->rightchild!=NULL ))
//   {
//         if(lr=="c") {faculty temp=(*base);(*base)=(*base)->rightchild;free (temp);return ;} 
//         if(lr=="l") {(*parent)->leftchild=(*base)->rightchild;free (*base);return ;}
//         else if (lr=="r") {(*parent)->rightchild=(*base)->rightchild;free (*base);return ;};
    
//   }
//    else if(((*base)->rightchild==NULL && (*base)->leftchild!=NULL ))
//   {
//         if(lr=="c") {faculty temp=(*base);(*base)=(*base)->leftchild;free (temp);return ;}     
//         if(lr=="l") {(*parent)->leftchild=(*base)->leftchild;free (*base);return ;}
//         else if (lr=="r") {(*parent)->rightchild=(*base)->leftchild;free (*base);return ;};
    
//   }
//   else if(((*base)->rightchild!=NULL && (*base)->leftchild!=NULL )) {



//     if((*base)->rightchild->leftchild==NULL) {
      
//       (*base)->rightchild->leftchild=(*base)->leftchild;
//       if(lr=="c") {faculty temp=(*base);(*base)=(*base)->rightchild;free (temp);return ;} 
//        if(lr=="l") {(*parent)->leftchild=(*base)->rightchild;free (*base);return ;}
//         else if (lr=="r") {(*parent)->rightchild=(*base)->rightchild;(*base)->rightchild->leftchild=(*base)->leftchild;free (*base);return ;};
       
//     }

//     else if((*base)->rightchild->leftchild!=NULL) {
   
//      temparory=&((*base)->rightchild->leftchild);
//     parent2=&((*base)->rightchild);

     
     

//       while((*temparory)->leftchild!=NULL){
//        parent2=temparory;
//         temparory=&((*temparory)->leftchild);
//         cout<<"1"<<endl;
        
//       };
      
         
      
     
//       if(lr=="c") {
//          faculty tempa=*base;
//         *base = *temparory;
     
//       (*temparory)->leftchild=(tempa)->leftchild;
      
//          (*temparory)->rightchild=(tempa)->rightchild;
//        (*temparory)=NULL;
       
//           return ;};
     
      
//       if(lr=="l") {
//       (*base)->age=(*temparory)->age;
//         (*base)->name=(*temparory)->name;
//         (*base)->department=(*temparory)->department;
//         (*base)->gender=(*temparory)->gender;
//         (*temparory)=NULL;
        
          
        
//      return;};
//       if (lr=="r") {
        
//             cout<<"1"<<endl;
//         (*base)->age=(*temparory)->age;
//         (*base)->name=(*temparory)->name;
//         (*base)->department=(*temparory)->department;
//         (*base)->gender=(*temparory)->gender;
//         (*temparory)=NULL;
        
        
//       ;return;};

//       };





//   };
  


  
//   return ;};
// if((*base)->name>Name) {DeleteInTree(base,"l",&((*base)->leftchild),Name);return ;}
// else if((*base)->name<Name) {DeleteInTree(base,"r",&((*base)->rightchild),Name);return ; };
//  return ;

// }


// int Delete(collection c,string Name){
// DeleteInTree(NULL,"c",&(c->root),Name);
// return 1;
// }

void DeleteInTree(faculty parent,string lr,faculty base,string Name){

 

 
cout<<Name<<endl;
if((base)==NULL) {return ;};

if((base)->name==Name) {
  faculty temparory;faculty parent2;

  if ((base)->leftchild==NULL && (base)->rightchild==NULL){


    if(lr=="c") {cout<<"1"<<endl;faculty temp=(base);(base)=NULL;free (temp);return ;} 
    else if(lr=="l") {(parent)->leftchild=NULL;free (base);return ;}
    else if (lr=="r") {(parent)->rightchild=NULL;free (base);return ;};

    
  }

  else if(((base)->leftchild==NULL && (base)->rightchild!=NULL ))
  {
        if(lr=="c") {faculty temp=(base);(base)=(base)->rightchild;free (temp);return ;} 
        else if(lr=="l") {(parent)->leftchild=(base)->rightchild;free (base);return ;}
        else if (lr=="r") {(parent)->rightchild=(base)->rightchild;free (base);return ;};
    
  }
   else if(((base)->rightchild==NULL && (base)->leftchild!=NULL ))
  {
    cout<<"1"<<endl;
        if(lr=="c") {faculty temp=(base);(base)=(base)->leftchild;free (temp);return ;}     
        else if(lr=="l") {(parent)->leftchild=(base)->leftchild;free (base);return ;}
        else if (lr=="r") {(parent)->rightchild=(base)->leftchild;free (base);return ;};
    
  }
  else if(((base)->rightchild!=NULL && (base)->leftchild!=NULL )) {



    if((base)->rightchild->leftchild==NULL) {
      
      (base)->rightchild->leftchild=(base)->leftchild;
      if(lr=="c") {faculty temp=(base);(base)=(base)->rightchild;free (temp);return ;} 
       else if(lr=="l") {(parent)->leftchild=(base)->rightchild;free (base);return ;}
        else if (lr=="r") {(parent)->rightchild=(base)->rightchild;free (base);return ;};
       
    }

    else if((base)->rightchild->leftchild!=NULL) {
   
     temparory=((base)->rightchild->leftchild);
    parent2=((base)->rightchild);

     
     

      while((temparory)->leftchild!=NULL){
       parent2=temparory;
        temparory=((temparory)->leftchild);
        cout<<"1"<<endl;
        
      };
      
         
      
     
      if(lr=="c") {
      (base)->age=(temparory)->age;
        (base)->name=(temparory)->name;
        (base)->department=(temparory)->department;
        (base)->gender=(temparory)->gender;
        (temparory)=NULL;
       
          return ;};
     
      
      if(lr=="l") {
      (base)->age=(temparory)->age;
        (base)->name=(temparory)->name;
        (base)->department=(temparory)->department;
        (base)->gender=(temparory)->gender;
        (temparory)=NULL;
        
          
        
     return;};
      if (lr=="r") {
        
            cout<<"1"<<endl;
        (base)->age=(temparory)->age;
        (base)->name=(temparory)->name;
        (base)->department=(temparory)->department;
        (base)->gender=(temparory)->gender;
        (temparory)=NULL;
        
        
      ;return;};
};};
  return ;};
  if((base)->name>Name) {DeleteInTree(base,"l",((base)->leftchild),Name);return ;}
else if((base)->name<Name) {DeleteInTree(base,"r",((base)->rightchild),Name);return ; };
 return ;

}


int Delete(collection c,string Name){
DeleteInTree(NULL,"c",(c->root),Name);
return 1;
}









int main (){

  struct collections first;
  first.root==NULL;
  collection firstp=&first;
  

  AddToCollection(firstp,"E",19,"MALE","PHY");
  AddToCollection(firstp,"H",19,"MALE","PHY");
   AddToCollection(firstp,"G",19,"MALE","PHY");
  AddToCollection(firstp,"F",19,"MALE","PHY");
  AddToCollection(firstp,"A",19,"MALE","PHY");
  AddToCollection(firstp,"J",19,"MALE","PHY");
  AddToCollection(firstp,"I",19,"MALE","PHY");
  //AddToCollection(firstp,"kamesh",19,"MALE","PHY");
  //AddToCollection(firstp,"kaYNESH",19,"MALE","PHY");
  
  Delete(firstp,"H");
  cout<<firstp->root->name<<endl;

 



 return 0;
}
