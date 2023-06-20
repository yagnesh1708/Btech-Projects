//AKKASANI YAGNESH REDDY
//CS21BTECH11003

#include <cstdlib>
#include <iostream>
using namespace std;
const int N = 100;
struct Heap {
  int count = 0;
  int heap[N];
  int size;
};

struct Edge{
    
    int value;
    int row;
    int column;
};


struct nodes {

  int *Set = (int *)malloc(sizeof(int) * 20);
  int count;
};

int intersection(struct nodes *temp1,struct nodes *temp2)
{
 int i,j;
 
 for(i=0;i<temp1->count;i++){
     
     for(j=0;j<temp2->count;j++){
         
         if(temp1->Set[i]==temp2->Set[j]){
             return 1;
         }
       }
 }
 return 0;}
 
 struct nodes Union(struct nodes *temp1,struct nodes *temp2)

{
    int i,j;
    struct nodes temp;
    
    for(i=0;i<temp1->count;i++){
        
        temp.Set[i]=temp1->Set[i];
    }
    
    temp.count=temp1->count;
    
    int k=0;
    
    for(i=temp.count;i<(temp1->count+temp2->count);i++){
        
        temp.Set[i]=temp2->Set[k];
        k=k+1;
        
    }
    
    temp.count=temp.count+temp2->count;
    
    return temp;
    
}    


int main() {

  int i, j, k, l, n;
  cin >> n;
  struct nodes node[n];
  struct Edge edges[(n*n-n)/2];

  for (i = 0; i < n; i++) {
    node[i].count = 1;
    node[i].Set[0] = i;
  }

  int **edge = new int *[n];
  int **edge1 = new int *[n];

  for (i = 0; i < n; i++) {

    edge[i] = new int[n];
    edge1[i] = new int[n];

    for (j = 0; j < n; j++) {
      edge[i][j] = 0;
      edge1[i][j] = 0;
    };
  };
  
for(i=0;i<n;i++){
    
    for(j=0;j<n;j++){
        
        cin>>edge[i][j];
    }
    
};

int s=0;

for(i=0;i<(n-1);i++){
    
    for(j=i+1;j<n;j++)
    {
        edges[s].value=edge[i][j];
        edges[s].row=i;
        edges[s].column=j;
        s=s+1;
        }
}

struct Edge temp;

for(i=0;i<((n*n-n)/2);i++){
    
    for(j=i+1;j<(n*n-n)/2;j++)
    {
       if(edges[i].value>edges[j].value){
           temp=edges[i];
           edges[i]=edges[j];
           edges[j]=temp;
           
           
       }
        }
}



int v=0;
int e=0;

while(edges[e].value==0){
    
    e=e+1;
}
struct nodes m;

// for(i=0;i<(n*n-n)/2;i++){

//   cout<<edges[i].value<<endl;
// }

while(v<(n-1) ){
    
if(  intersection(&node[edges[e].row],&node[edges[e].column])==0 ){
    
   
    m=Union(&node[edges[e].row],&node[edges[e].column]);
     node[edges[e].row]=m;
    node[edges[e].column]=m;
    v=v+1;
    
    cout<<"Row:"<<edges[e].row<<" "<<"column:"<<edges[e].column<<" "<<"Edge weight:"<<edges[e].value<<endl;
    
    
}

e=e+1;
    
    
    
}





 

  return 0;
    
    
    
}
