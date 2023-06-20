  //AKKASANI YAGNESH REDDY
//CS21BTECH11003

#include<iostream>
#include<cstdlib>
using namespace std;
#define N 5 

struct faculties{
    int age[N];
    int count;
    int leaf;
    struct  faculties *parent;
    struct  faculties *child[N+1];
    };

 typedef struct faculties *faculty;

 struct collections{

 faculty root;

 };   

 typedef struct collections *collection;



 void addb(collection c,faculty temp,int n){

    int i,j,l,s,p;
     

    faculty New1=new struct faculties;
    faculty New2=new struct faculties;

    temp->age[temp->count]=n;
    temp->count=temp->count+1;

     for(i=((temp->count)-1);i>0;i--){
        if(temp->age[i-1]>temp->age[i]){

            s=temp->age[i-1];
           temp->age[i-1]=temp->age[i];
            temp->age[i]=s;
        }
       }

       if(temp->count<N) {return;}

       else if(temp->count==N){
        p=temp->age[N/2];

        New1->count=N/2;
        New2->count=N/2;
        for(i=0;i<N/2;i++){

            New1->age[i]=temp->age[i];
            New2->age[i]=temp->age[N/2+i+1];
        }
        for(i=0;i<=N/2;i++){

       New1->child[i]=temp->child[i];
       if(New1->child[i]!=NULL) New1->child[i]->parent=New1;
       New2->child[i]=temp->child[N/2+i+1];
      if(New2->child[i]!=NULL) New2->child[i]->parent=New2;


        }
        if(temp->leaf==1) New1->leaf=1;
        if(temp->leaf==0) New1->leaf=0;
        if(temp->leaf==1) New2->leaf=1;
        if(temp->leaf==0) New2->leaf=0;

        New1->parent=temp->parent;
        New2->parent=temp->parent;

        

       

        if(temp->parent==NULL){

faculty Nparnet= new struct faculties;

Nparnet->count=0;
Nparnet->parent=NULL;
Nparnet->child[0]=New1;
Nparnet->child[1]=New2;
New1->parent=Nparnet;
New2->parent=Nparnet;
c->root=Nparnet;
Nparnet->leaf=0;
        }

        else{
            
            for(i=0;i<=(temp->parent->count);i++){

            if(temp->parent->child[i]==temp){

                temp->parent->child[i]=New1;
                for(j=temp->parent->count;j>(i);j--){

                    temp->parent->child[j+1]=temp->parent->child[j];
                }
                temp->parent->child[i+1]=New2;

                //cout<<temp->parent->child[2]->age[1]<<endl;

                
            }
        }
        }
           free(temp);
        addb(c,New1->parent,p);



       }



    



 return ;
 }


 void add(collection c,int n){

     faculty temp=c->root;
    int i,j,l,s;


    if(c->root==NULL){
         faculty New = new struct faculties;  
         for(i=0;i<=N;i++){
            New->child[i]=NULL;
         }
         New->age[0]=n;
         New->leaf=1;
         New->parent=NULL;
         New->count=1;

         c->root=New;
         return;
    }

    else if(c->root->leaf==1 && c->root->count<=(N-2)){

       c->root->age[c->root->count]=n;
       c->root->count=c->root->count+1;

       for(i=((c->root->count)-1);i>0;i--){
        if(c->root->age[i-1]>c->root->age[i]){

            s=c->root->age[i-1];
            c->root->age[i-1]=c->root->age[i];
            c->root->age[i]=s;
        }
       }
        return ;}


        while(temp->leaf!=1){

            l=temp->count;
            for(i=0;i<l;i++){

                if(n<temp->age[i]) {break;}

            }
            temp=temp->child[i];

         }
      
       

           addb(c,temp,n);




return ;


}


void inorder(faculty temp){

    int i,j;
    if(temp!=NULL && temp->count!=0){
    i=temp->count;
    
    for(j=0;j<i;j++){
        inorder(temp->child[j]);
        cout<<temp->age[j]<<endl;
   }
   inorder(temp->child[i]);}

   return ;

}

void printn(faculty temp){


    int i,j,l,k;
if(temp!=NULL && temp->count!=0){
    for(i=0;i<temp->count;i++){
        cout<<temp->age[i]<<" " ;

    }
      cout<<endl;

      for(i=0;i<=temp->count;i++){
       printn(temp->child[i]);

    }
}

    return ;

}


faculty search(faculty temp,int n){

    int i,j;

    for(i=0;i<temp->count;i++){

        if(temp->age[i]==n) return temp ;
    }


if(n<temp->age[0]) {return search(temp->child[0],n);}
else if(n>temp->age[(temp->count-1)]) {return search(temp->child[temp->count],n);}
else {

      for(i=0;i<(temp->count-1);i++){

        


        if(temp->age[i]<n && n<temp->age[i+1]) {

            if(temp->child[i+1]==NULL) return NULL;
            else {return search(temp->child[i+1],n);}
        }


      }
}

return NULL;


}

void lldelete(collection C,faculty temp){

int c = temp->count;

int t;

int pc;

if(temp->parent!=NULL)
{pc=temp->parent->count;}






int k,i,j;

if(c>=N/2 && temp->parent!=NULL) cout<<"wrong code"<<endl;


else if(c<N/2){for(k=0;k<=pc;k++){

    if(temp->parent->child[k]==temp) break;
}

t=k;

if(k==0 && temp->parent->child[1]->count>N/2){
   
    temp->age[temp->count]=temp->parent->age[0];
    temp->parent->age[0]=temp->parent->child[1]->age[0];
    temp->count=temp->count+1;
    temp->child[temp->count]=temp->parent->child[1]->child[0];
if(temp->parent->child[1]->child[0]!=NULL) temp->parent->child[1]->child[0]->parent=temp;


for(i=0;i<temp->parent->child[1]->count-1;i++){
    temp->parent->child[1]->age[i]=temp->parent->child[1]->age[i+1];
    temp->parent->child[1]->child[i]=temp->parent->child[1]->child[i+1];
}
temp->parent->child[1]->child[i]=temp->parent->child[1]->child[i+1];

temp->parent->child[1]->count=temp->parent->child[1]->count-1;






}

else if(0<k && k<(pc) && temp->parent->child[k+1]->count>N/2){



     temp->age[temp->count]=temp->parent->age[k];
    temp->parent->age[k]=temp->parent->child[k+1]->age[0];
    temp->count=temp->count+1;
    temp->child[temp->count]=temp->parent->child[k+1]->child[0];
if(temp->parent->child[k+1]->child[0]!=NULL) temp->parent->child[k+1]->child[0]->parent=temp;


for(i=0;i<temp->parent->child[k+1]->count-1;i++){
    temp->parent->child[k+1]->age[i]=temp->parent->child[k+1]->age[i+1];
    temp->parent->child[k+1]->child[i]=temp->parent->child[k+1]->child[i+1];
}
temp->parent->child[k+1]->child[i]=temp->parent->child[k+1]->child[i+1];

temp->parent->child[k+1]->count=temp->parent->child[k+1]->count-1;


}

else if(0<k && k<(pc) && temp->parent->child[k-1]->count>N/2){

    
for(i=0;i<temp->count;i++){
    temp->age[temp->count-i]=temp->age[temp->count-i-1];
    temp->child[temp->count-i+1]=temp->child[temp->count-i];
}
temp->child[temp->count-i+2]=temp->child[temp->count-i+1];

     temp->age[0]=temp->parent->age[k-1];
    temp->parent->age[k-1]=temp->parent->child[k-1]->age[temp->parent->child[k-1]->count-1];
    temp->count=temp->count+1;
    temp->child[0]=temp->parent->child[k-1]->child[temp->parent->child[k-1]->count];
if(temp->parent->child[k-1]->child[temp->parent->child[k-1]->count]!=NULL) temp->parent->child[k-1]->child[temp->parent->child[k-1]->count]->parent=temp;





temp->parent->child[k-1]->count=temp->parent->child[k-1]->count-1;



    
}

else if(k==(pc) && temp->parent->child[k-1]->count>N/2){


    for(i=0;i<temp->count;i++){
    temp->age[temp->count-i]=temp->age[temp->count-i-1];
    temp->child[temp->count-i+1]=temp->child[temp->count-i];
}
temp->child[temp->count-i+2]=temp->child[temp->count-i+1];

     temp->age[0]=temp->parent->age[k-1];
    temp->parent->age[k-1]=temp->parent->child[k-1]->age[temp->parent->child[k-1]->count-1];
    temp->count=temp->count+1;
    temp->child[0]=temp->parent->child[k-1]->child[temp->parent->child[k-1]->count];
if(temp->parent->child[k-1]->child[temp->parent->child[k-1]->count]!=NULL) temp->parent->child[k-1]->child[temp->parent->child[k-1]->count]->parent=temp;





temp->parent->child[k-1]->count=temp->parent->child[k-1]->count-1;




}



else {    


    
       if(k!=pc){
  

  temp->age[temp->count]= temp->parent->age[k];
  temp->count=temp->count+1;
  
  for(i=temp->count;i<(temp->count+temp->parent->child[t+1]->count);i++){

    temp->age[i]=temp->parent->child[k+1]->age[i-temp->count];
    temp->child[i]=temp->parent->child[k+1]->child[i-temp->count];
    if(temp->child[i]!=NULL) temp->child[i]->parent=temp;


  }
   temp->child[i]=temp->parent->child[k+1]->child[i-temp->count];

   
   if(temp->child[i]!=NULL) temp->child[i]->parent=temp;
   temp->count=temp->count+temp->parent->child[k+1]->count;


   for(i=k;i<temp->parent->count-1;i++){

    temp->parent->age[i]=temp->parent->age[i+1];
   temp->parent->child[i+1]=temp->parent->child[i+2];
   }
temp->parent->count=temp->parent->count-1;

}

       else if(k==pc){

      temp=temp->parent->child[t-1];
      t=t-1;
      k=t;
      temp->age[temp->count]= temp->parent->age[k];
  temp->count=temp->count+1;
  
  for(i=temp->count;i<(temp->count+temp->parent->child[t+1]->count);i++){

    temp->age[i]=temp->parent->child[k+1]->age[i-temp->count];
    temp->child[i]=temp->parent->child[k+1]->child[i-temp->count];
    if(temp->child[i]!=NULL) temp->child[i]->parent=temp;


  }
   temp->child[i]=temp->parent->child[k+1]->child[i-temp->count];

   
   if(temp->child[i]!=NULL) temp->child[i]->parent=temp;
   temp->count=temp->count+temp->parent->child[k+1]->count;


   for(i=k;i<temp->parent->count-1;i++){

    temp->parent->age[i]=temp->parent->age[i+1];
   temp->parent->child[i+1]=temp->parent->child[i+2];
   }
temp->parent->count=temp->parent->count-1;






       }
}

}

if(temp->parent->count<N/2 && temp->parent->parent!=NULL) {lldelete(C,temp->parent);}

else if(temp->parent==C->root && temp->parent->count==0 ) { C->root=temp;temp->parent=NULL;} 


return ;

        }


void deletebt(collection C,int n){

    int i,j,m;

    faculty test = search(C->root,n);
    faculty temp;

    if(test==NULL) {cout<<"number not present"<<endl; return;}

   else  if(test->leaf==1){

        for(i=0;i<test->count;i++){
  
            if(test->age[i]==n){
                for(j=i;j<test->count-1;j++){

                    test->age[j]=test->age[j+1];
                    
                }
                test->count=test->count-1;
                        break;

            }

        }

        if(test->count<N/2) lldelete(C,test);
    }

    
      else if(test->leaf==0){

        for(i=0;i<test->count;i++){

            if(test->age[i]==n) break;
        }

   temp=test->child[i+1];
        while(temp->child[0]!=NULL){
            temp=temp->child[0];

           }
           test->age[i]=temp->age[0];

           for(j=0;j<temp->count-1;temp++){

            temp->age[j]=temp->age[j+1];
           }

           temp->count=temp->count-1;

           if(temp->count<N/2) lldelete(C,temp);

    






}

return ;
}
    







int main(){

    struct collections c;
    c.root=NULL;
    collection pc=&c;

    int i;

    add(pc,1);  //1 12 8 2 25 6 14 28 17 7 52 16 48 68 3 26 29 53 55 45
    add(pc,12);
    add(pc,8);
    add(pc,2);
    add(pc,25);
    add(pc,6);
     add(pc,14);
     add(pc,28);
     add(pc,17);
    add(pc,7);
     add(pc,52);
     add(pc,16);
     add(pc,48);
      add(pc,68);
     add(pc,3);
      add(pc,26);
     add(pc,29);
     add(pc,53);
      add(pc,55);
      add(pc,45);
      
     deletebt(pc,12);
      deletebt(pc,14);
  


printn(c.root);
inorder(c.root);


//faculty test = search(c.root,7);
//cout<<test->age[0]<<endl;



    

    return 0;
}