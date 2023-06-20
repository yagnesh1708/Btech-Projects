//AKKASANI YAGNESH REDDY
//CS21BTECH11003

#include<iostream>
#include<cstdlib>
using namespace std;
const int N=20;
struct Heap{
    int count =0;
    int heap[N]; 

};


int insert(struct Heap *collection,int n){

    int index;
    int parent;
    int temp;

if(collection->count==(N)) {
    cout<<"heap is full"<<endl;
    return 0;
}

else{
      collection->count=collection->count+1;
      index=collection->count;
      parent=index/2;
    collection->heap[index]=n;
    while(parent>0){
        
        if(collection->heap[parent]>collection->heap[index]){
            temp=collection->heap[parent];
            collection->heap[parent]=collection->heap[index];
            collection->heap[index]=temp;
            index=parent;
            parent=index/2;
              }
           else{
            break;
           }   
    }
}

return 1;
}

int Delete(struct Heap *collection){
  
    collection->heap[1]=collection->heap[collection->count];
    collection->count=(collection->count)-1;
      int index=1;
    int right_child=(2*index)+1;
    int left_child=(2*index);
    int temp;

    while(index<=collection->count){

       if(right_child>collection->count && left_child>collection->count) return 0;
       if(collection->heap[index]==collection->heap[left_child] && collection->heap[index]==collection->heap[right_child] )
            {
                return 0;
            }

       if(right_child>collection->count && left_child<=collection->count) {
         
         if(collection->heap[left_child]<collection->heap[index])
         { temp=collection->heap[left_child];
            collection->heap[left_child]=collection->heap[index];
            collection->heap[index]=temp;          
            return 0;
         }
         else {return 0;}
  }
            if(right_child<=collection->count && left_child<=collection->count){

            if(collection->heap[index]<collection->heap[left_child] && collection->heap[index]<collection->heap[right_child] )
            {
                return 0;
            }
            if(collection->heap[index]>collection->heap[left_child] && collection->heap[index]<=collection->heap[right_child] )
            {temp=collection->heap[left_child];
            collection->heap[left_child]=collection->heap[index];
            collection->heap[index]=temp; 
            index=left_child;
             right_child=(2*index)+1;
             left_child=(2*index);
              }
              if(collection->heap[index]<=collection->heap[left_child] && collection->heap[index]>collection->heap[right_child] )
            {temp=collection->heap[right_child];
            collection->heap[right_child]=collection->heap[index];
            collection->heap[index]=temp; 
            index=right_child;
             right_child=(2*index)+1;
             left_child=(2*index);
              }
              if(collection->heap[index]>collection->heap[left_child] && collection->heap[index]>collection->heap[right_child] )
            {
                if(collection->heap[left_child]<=collection->heap[right_child]) {
                    temp=collection->heap[left_child];
            collection->heap[left_child]=collection->heap[index];
            collection->heap[index]=temp; 
            index=left_child;
             right_child=(2*index)+1;
             left_child=(2*index);

                }
                else if(collection->heap[left_child]>collection->heap[right_child]) {
                    temp=collection->heap[right_child];
            collection->heap[right_child]=collection->heap[index];
            collection->heap[index]=temp; 
            index=right_child;
             right_child=(2*index)+1;
             left_child=(2*index);

                }
              }

           }


      
       

    }




return 0;}

int findmin(struct Heap *collection){
    return collection->heap[1];
}






int main(){


struct Heap test;
insert(&test,6);
 insert(&test,6);
insert(&test,14);
insert(&test,14);
insert(&test,18);
//  insert(&test,47);
//  insert(&test,45);
//  insert(&test,83);
//  insert(&test,91);
//  insert(&test,81);
//  insert(&test,77);
//  insert(&test,84);
//  insert(&test,99);
//  insert(&test,64);
//  insert(&test,53);
//  Delete(&test);
//  Delete(&test);
 Delete(&test);
 Delete(&test);
int i=0;
for(i=1;i<=test.count;i++)
cout<<test.heap[i]<<endl;








return 0;
}