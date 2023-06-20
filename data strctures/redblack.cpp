//AKKASANI YAGNESH REDDY
//CS21BTECH11003

#include<iostream>
#include<cstdlib>
using namespace std;

struct faculties{
int age;
string color;

struct faculties *left_child;
struct faculties *right_child;
struct faculties *parent;

};

typedef struct faculties *faculty;

struct faculties NILL;
faculty NIL=&NILL;



faculty search(faculty *base,int number){

if((*base)==NIL) {return NULL;};

if((*base)->age==number) {return *base;}
else if((*base)->age>number) {return search(&((*base)->left_child),number);}
else if((*base)->age<number) {return search(&((*base)->right_child),number); };
 return NULL;



}



//int rb_add(faculty base)

// int leftrotation(faculty base,faculty root ){

//     faculty right=root->right_child;
//     if(right->left_child!=NULL) {
//         root->right_child=right->left_child;
//         right->left_child->parent=root;
//     }
//     right->parent=root->parent;

//     if(root->parent==NULL) {base->left_child=right;}
//     else if(root->parent->left_child==root) {root->parent->left_child=right;}
//     else if(root->parent->right_child==root) {root->parent->right_child=right;};

//     right->left_child=root;
//     root->parent=right;

// return 0;

// }



// int rightrotation(faculty base,faculty root ){

//     faculty left=root->left_child;
//     if(left->right_child!=NULL) {
//         root->left_child=left->right_child;
//         left->right_child->parent=root;
//     }
//     left->parent=root->parent;

//     if(root->parent==NULL) {base->left_child=left;}
//     else if(root->parent->left_child==root) {root->parent->left_child=left;}
//     else if(root->parent->right_child==root) {root->parent->right_child=left;};

//     left->right_child=root;
//     root->parent=left;

//     return 0;


// }
int leftrotation(faculty base,faculty root){
    faculty right=root->right_child;
    faculty parent1=root->parent;

      if(root->parent==NULL) {base->left_child=right;}
    else if(root->parent->left_child==root) {root->parent->left_child=right;}
    else if(root->parent->right_child==root) {root->parent->right_child=right;};

    right->parent=parent1;

     root->right_child=right->left_child;

     if(right->left_child!=NULL) {
       
        right->left_child->parent=root;
    }

      right->left_child=root;
    root->parent=right;

return 0;

}

int rightrotation(faculty base,faculty root){

    faculty left=root->left_child;
    faculty parent1=root->parent;

    if(root->parent==NULL) {base->left_child=left;}
    else if(root->parent->left_child==root) {root->parent->left_child=left;}
    else if(root->parent->right_child==root) {root->parent->right_child=left;};

       left->parent=parent1;

         root->left_child=left->right_child;
       if(left->right_child!=NULL) {
      
        left->right_child->parent=root;
    }

        left->right_child=root;
    root->parent=left;


    return 0;
}


int insert(faculty *rootp,faculty parent,faculty New)
{

if((*rootp)==NIL) {(*rootp)=New;New->parent=parent;return 0;}
else if((*rootp)->age>New->age) {parent=(*rootp);insert(&((*rootp)->left_child),parent,New);return 0;}
else if((*rootp)->age<New->age) {parent=(*rootp);insert(&((*rootp)->right_child),parent,New);return 0;}

return 0;

}


void add(faculty base,faculty *rootp,int number){
    faculty root=(*rootp);
    faculty parent=NULL;

    faculty New = new struct faculties;
    New->age=number;
    New->left_child=NIL;
    New->right_child=NIL;
    New->parent=NULL;
    

    insert(rootp,parent,New);
      root=(*rootp);
     New->color="red";

     faculty uncle;

     while ( (New != root) && (New->parent->color == "red") )

 {if ( New->parent == New->parent->parent->left_child ) {

uncle = New->parent->parent->right_child;

if ( uncle->color == "red" ) {
New->parent->color = "black";
uncle->color = "black";
New->parent->parent->color = "red";
New = New->parent->parent;
}

else {
if(New==New->parent->right_child ) {
New = New->parent;
leftrotation( base, New );}

else { 
New->parent->color = "black";
New->parent->parent->color = "red";
rightrotation( base, New->parent->parent );

}
}
}


else if( New->parent == New->parent->parent->right_child ) {

uncle = New->parent->parent->left_child;

if ( uncle->color == "red" ) {
New->parent->color = "black";
uncle->color = "black";
New->parent->parent->color = "red";
New = New->parent->parent;
}

else {

if ( New == New->parent->left_child ) {
New = New->parent;
rightrotation( base, New );}

else { 
New->parent->color = "black";
New->parent->parent->color = "red";
leftrotation( base, New->parent->parent );

}
}
}

 }

if(New==root) New->color="black";  





      return ;
}



void inorder(faculty root)
{
    if(root!=NIL){

        inorder(root->left_child);
        cout<<root->age<<" "<<root->color<<endl;
        inorder(root->right_child);
    }
    return ;

}





int main(){

    NIL->age=0;
NIL->color="black";
NIL->left_child=NULL;
NIL->right_child=NULL;
NIL->parent=NULL;



    struct faculties base;
    base.left_child=NIL;
    add(&base,&(base.left_child),-1);
    add(&base,&(base.left_child),1);
     add(&base,&(base.left_child),12);
     add(&base,&(base.left_child),5);
      add(&base,&(base.left_child),4);
    //  add(&base,&(base.left_child),206);
    //  add(&base,&(base.left_child),-15);
    //  add(&base,&(base.left_child),-3);
    //  add(&base,&(base.left_child),-10);
    //  add(&base,&(base.left_child),11);

     
 inorder((base.left_child));

//    rightrotation(&(base),(base.left_child));

//cout<<base.left_child->age<<endl;
//    leftrotation(&(base),(base.left_child));

//     cout<<base.left_child->age<<endl;

// inorder((base.left_child));

// faculty test=search(&(base.left_child),-12);
// cout<<test->age<<endl;
       


 



}

