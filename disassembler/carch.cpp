#include<iostream>
#include<cstdlib>
#include<vector>
#include<fstream>
#include <string>
#include <sstream>
#include<bits/stdc++.h>
#include<math.h>
#include<stdio.h>
using namespace std;



int main(){

    vector<string> input;
    string line;
    ifstream inp("input.txt");

   
    while(!inp.eof()){

      getline(inp,line);
      input.push_back(line);

    }

int ins[32];
int rd;
int rs1;
int rs2;
int imm;
int p,q;
int r=0;
int z[20];
int is[20];
int b=0;
p=0;
q=-1;
for(auto i=input.begin();i!=input.end();i++){
line=(*i);
p=p+1;
r=r+1;


for(int j=0;j<8;j++){

if(line[j]=='0') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=0;
}
else if(line[j]=='1') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=1;
}
else if(line[j]=='2') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=0;
}
else if(line[j]=='3') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=1;
}
else if(line[j]=='4') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=0;
}
else if(line[j]=='5') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=1;
}
else if(line[j]=='6') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=0;
}
else if(line[j]=='7') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=1;
}
else if(line[j]=='8') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=0;
}
else if(line[j]=='9') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=1;
}
else if(line[j]=='a') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=0;
}
else if(line[j]=='b') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=1;
}
else if(line[j]=='c') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=0;
}
else if(line[j]=='d') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=1;
}
else if(line[j]=='e') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=0;
}
else if(line[j]=='f') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=1;
}


}

//  if(ins[31-6]==0 && ins[31-5]==1 && ins[31-2]==0 && ins[31-4]==1){

//     rd=0;
//     for(int k=7;k<12;k++){
//      rd=rd+ins[31-k]*pow(2,k-7); 
//     }

//     rs1=0;
//     for(int k=15;k<20;k++){
//      rs1=rs1+ins[31-k]*pow(2,k-15); 
//     }
    
//     rs2=0;
//     for(int k=20;k<=24;k++){
//      rs2=rs2+ins[31-k]*pow(2,k-20); 
//     }

//   if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 &&ins[31-30]==0 )
//     {}

//      if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 &&ins[31-30]==1 )
//     {}
     
//      if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==1 &&ins[31-30]==0 )
//     {}

//  if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 &&ins[31-30]==0 )
//     {}

//      if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==0 &&ins[31-30]==0 )
//     {}

//      if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==0 &&ins[31-30]==0 )
//     {}

//      if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 &&ins[31-30]==0 )
//     {}
     
//      if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 &&ins[31-30]==1 )
//     {}


// }
// else if(ins[31-6]==0 && ins[31-5]==0 && ins[31-2]==0 && ins[31-4]==1){

//     rd=0;
//     for(int k=7;k<12;k++){
//      rd=rd+ins[31-k]*pow(2,k-7); 
//     }

//     rs1=0;
//     for(int k=15;k<20;k++){
//      rs1=rs1+ins[31-k]*pow(2,k-15); 
//     }
    
//     imm=0;
//     for(int k=20;k<=31;k++){
//      imm=imm+ins[31-k]*pow(2,k-20); 
//     }
//     if(ins[0]==1) imm=imm-pow(2,12);

//   if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
//     {}

// if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==1  )
//     {}

//  if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 )
//     {}

//      if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==0 )
//     {}

//      if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==0  )
//     {}

//      if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 && ins[6]==0  )
//     {}
     
//      if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 && ins[6]==1 )
//     {}


// }
// else if(ins[31-6]==0 && ins[31-5]==0 && ins[31-2]==0 && ins[31-4]==0){

//     rd=0;
//     for(int k=7;k<12;k++){
//      rd=rd+ins[31-k]*pow(2,k-7); 
//     }

//     rs1=0;
//     for(int k=15;k<20;k++){
//      rs1=rs1+ins[31-k]*pow(2,k-15); 
//     }
    
//     imm=0;
//     for(int k=20;k<=31;k++){
//      imm=imm+ins[31-k]*pow(2,k-20); 
//     }
//     int imm1;
//     if(ins[0]==1) { imm1=imm;imm=imm-pow(2,12);}


//   if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
//     {}

//  if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 )
//     {cout<<"lh x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;}

//      if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==0 )
//     {cout<<"lbu x"<<rd<<","<<imm1<<"(x"<<rs1<<")"<<endl;}

//      if(ins[31-14]==0 && ins[31-13]==1 && ins[31-12]==0  )
//     {cout<<"lw x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;}

//      if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1   )
//     {cout<<"lhu x"<<rd<<","<<imm1<<"(x"<<rs1<<")"<<endl;}
     
//      if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==0 )
//     {cout<<"lwu x"<<rd<<","<<imm1<<"(x"<<rs1<<")"<<endl;}
    
//     if(ins[31-14]==0 && ins[31-13]==1 && ins[31-12]==1  )
//     {cout<<"ld x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;


// }
// }
//  else if(ins[31-6]==0 && ins[31-5]==1 && ins[31-2]==0 && ins[31-4]==0){

//     imm=0;
//     for(int k=7;k<12;k++){
//      imm=imm+ins[31-k]*pow(2,k-7); 
//     }

//     rs1=0;
//     for(int k=15;k<20;k++){
//      rs1=rs1+ins[31-k]*pow(2,k-15); 
//     }

//      rs2=0;
//     for(int k=20;k<=24;k++){
//      rs2=rs2+ins[31-k]*pow(2,k-20); 
//     }
     
//      for(int k=25;k<32;k++){
//      imm=imm+ins[31-k]*pow(2,k-20); 
//     }

//     if(ins[0]==1) {imm=imm-pow(2,12);}

//     if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
//     {cout<<"sb x"<<rs1<<","<<imm<<"(x"<<rs2<<")"<<endl;}

// if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 )
//     {cout<<"sh x"<<rs1<<","<<imm<<"(x"<<rs2<<")"<<endl;}

//    if(ins[31-14]==0 && ins[31-13]==1 && ins[31-12]==0 )
//     {cout<<"sw x"<<rs1<<","<<imm<<"(x"<<rs2<<")"<<endl;}

//  if(ins[31-14]==0 && ins[31-13]==1 && ins[31-12]==1 )
//     {cout<<"sd x"<<rs1<<","<<imm<<"(x"<<rs2<<")"<<endl;}

//  }
 if(ins[31-6]==1 && ins[31-5]==1 && ins[31-4]==0 &&ins[31-3]==0 && ins[31-2]==0 && ins[31-1]==1 && ins[31-0]==1){

  

    rs1=0;
    for(int k=15;k<20;k++){
     rs1=rs1+ins[31-k]*pow(2,k-15); 
    }

     rs2=0;
    for(int k=20;k<=24;k++){
     rs2=rs2+ins[31-k]*pow(2,k-20); 
    }

      imm=0;
      
    for(int k=8;k<12;k++){
     imm=imm+ins[31-k]*pow(2,k-7); 
    }
     
     for(int k=25;k<31;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }

    imm=imm+ins[31-31]*pow(2,12);
    imm=imm+ins[31-7]*pow(2,11);

    if(ins[0]==1) {imm=imm-pow(2,13);}


for(int a=0;a<=q;a++){
if(p+imm/4==z[a])   {b=1;break;}
}
if(b==0 && imm/4+r>=0) {q=q+1;
    z[q]=p+imm/4;
    is[q]=p;}
    b=0;


//     if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
//     {cout<<"beq"<<" x"<<rs1<<",x"<<rs2<<","<<imm<<endl;}

// if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 )
//     {cout<<"bne"<<" x"<<rs1<<",x"<<rs2<<","<<imm<<endl;}

//    if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==0 )
//     {cout<<"blt"<<" x"<<rs1<<",x"<<rs2<<","<<imm<<endl;}

//  if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 )
//     {cout<<"bge"<<" x"<<rs1<<",x"<<rs2<<","<<imm<<endl;}
    
//  if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==0 )
//     {cout<<"bltu"<<" x"<<rs1<<",x"<<rs2<<","<<imm<<endl;}
//     if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==1 )
//     {cout<<"bgeu"<<" x"<<rs1<<",x"<<rs2<<","<<imm<<endl;}

 }
else if(ins[31-6]==1 && ins[31-5]==1 && ins[31-4]==0 &&ins[31-3]==1 && ins[31-2]==1 && ins[31-1]==1 && ins[31-0]==1){

  

    rd=0;
    for(int k=7;k<12;k++){
     rd=rd+ins[31-k]*pow(2,k-7); 
    }

  

      imm=0;
      
    for(int k=12;k<20;k++){
     imm=imm+ins[31-k]*pow(2,k); 
    }
     imm=imm+ins[31-20]*pow(2,11);

     for(int k=21;k<31;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }
     imm=imm+ins[31-31]*pow(2,20);
     
   if(ins[0]==1) {imm=imm-pow(2,12);}  
 
   
for(int a=0;a<=q;a++){

    if(p+imm/4==z[a])   {b=1;}

    }
if(b==0) {q=q+1;
    z[q]=p+imm/4;
    is[q]=p;}
    b=0;
//     if(ins[31-14]==0 && ins[31-13]==0 && ins[31-14]==0 )
//     {cout<<"jal "<<"x"<<rd<<","<<imm<<endl;}
}
// else if(ins[31-6]==1 && ins[31-3]==0 && ins[31-5]==1 && ins[31-2]==1 && ins[31-4]==0){

//       rd=0;
//     for(int k=7;k<12;k++){
//      rd=rd+ins[31-k]*pow(2,k-7); 
//     }

//     rs1=0;
//     for(int k=15;k<20;k++){
//      rs1=rs1+ins[31-k]*pow(2,k-15); 
//     }
    
//     imm=0;
//     for(int k=20;k<=31;k++){
//      imm=imm+ins[31-k]*pow(2,k-20); 
//     }
//      if(ins[0]==1) {imm=imm-pow(2,12);}

     


//     // if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
//     // {cout<<"jalr x"<<rd<<",x"<<rs1<<","<<imm<<endl;}
// }
// else if(ins[31-6]==0 && ins[31-3]==0 && ins[31-5]==1 && ins[31-2]==1 && ins[31-4]==1){

  

//     rd=0;
//     for(int k=7;k<12;k++){
//      rd=rd+ins[31-k]*pow(2,k-7); 
//     }
// imm=0;
      
//     for(int k=12;k<=31;k++){
//      imm=imm+ins[31-k]*pow(2,k); 
//     }
//     if(ins[0]==1) {imm=imm-pow(2,12);}
 

    // if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
    // {cout<<"lui "<<"x"<<rd<<",0x";
    // printf("%X\n",imm);}
//}

}




p=1;
r=0;
int m=0;
for(auto i=input.begin();i!=input.end();i++){
   
   line=(*i);

   
    r=r+1;

    for(int p=0;p<=q;p++){
        if(r==z[p])
        { 
            cout<<"L"<<p<<":"<<endl;
            break;
        }
    }



for(int j=0;j<8;j++){

if(line[j]=='0') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=0;
}
else if(line[j]=='1') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=1;
}
else if(line[j]=='2') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=0;
}
else if(line[j]=='3') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=1;
}
else if(line[j]=='4') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=0;
}
else if(line[j]=='5') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=1;
}
else if(line[j]=='6') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=0;
}
else if(line[j]=='7') {
    
    ins[0+(j*4)]=0;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=1;
}
else if(line[j]=='8') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=0;
}
else if(line[j]=='9') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=1;
}
else if(line[j]=='a') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=0;
}
else if(line[j]=='b') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=0;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=1;
}
else if(line[j]=='c') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=0;
}
else if(line[j]=='d') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=0;
    ins[3+(j*4)]=1;
}
else if(line[j]=='e') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=0;
}
else if(line[j]=='f') {
    
    ins[0+(j*4)]=1;
    ins[1+(j*4)]=1;
    ins[2+(j*4)]=1;
    ins[3+(j*4)]=1;
}


}

 if(ins[31-6]==0 && ins[31-5]==1 && ins[31-4]==1 &&ins[31-3]==0 && ins[31-2]==0 && ins[31-1]==1 && ins[31-0]==1){

    rd=0;
    for(int k=7;k<12;k++){
     rd=rd+ins[31-k]*pow(2,k-7); 
    }

    rs1=0;
    for(int k=15;k<20;k++){
     rs1=rs1+ins[31-k]*pow(2,k-15); 
    }
    
    rs2=0;
    for(int k=20;k<=24;k++){
     rs2=rs2+ins[31-k]*pow(2,k-20); 
    }

  if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 &&ins[31-30]==0 )
    {cout<<"add x"<<rd<<",x"<<rs1<<",x"<<rs2<<endl;}

     if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 &&ins[31-30]==1 )
    {cout<<"sub x"<<rd<<",x"<<rs1<<",x"<<rs2<<endl;}
     
     if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==1 &&ins[31-30]==0 )
    {cout<<"and x"<<rd<<",x"<<rs1<<",x"<<rs2<<endl;}

 if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 &&ins[31-30]==0 )
    {cout<<"sll x"<<rd<<",x"<<rs1<<",x"<<rs2<<endl;}

     if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==0 &&ins[31-30]==0 )
    {cout<<"xor x"<<rd<<",x"<<rs1<<",x"<<rs2<<endl;}

     if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==0 &&ins[31-30]==0 )
    {cout<<"or x"<<rd<<",x"<<rs1<<",x"<<rs2<<endl;}

     if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 &&ins[31-30]==0 )
    {cout<<"srl x"<<rd<<",x"<<rs1<<",x"<<rs2<<endl;}
     
     if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 &&ins[31-30]==1 )
    {cout<<"sra x"<<rd<<",x"<<rs1<<",x"<<rs2<<endl;}


}
else if(ins[31-6]==0 && ins[31-5]==0 && ins[31-4]==1 &&ins[31-3]==0 && ins[31-2]==0 && ins[31-1]==1 && ins[31-0]==1){

    rd=0;
    for(int k=7;k<12;k++){
     rd=rd+ins[31-k]*pow(2,k-7); 
    }

    rs1=0;
    for(int k=15;k<20;k++){
     rs1=rs1+ins[31-k]*pow(2,k-15); 
    }
    
    imm=0;
    for(int k=20;k<=31;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }
    if(ins[0]==1) imm=imm-pow(2,12);

  if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"addi x"<<rd<<",x"<<rs1<<","<<imm<<endl;}

if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==1  )
    {cout<<"andi x"<<rd<<",x"<<rs1<<","<<imm<<endl;}

 if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"xori x"<<rd<<",x"<<rs1<<","<<imm<<endl;}

     if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==0  )
    {cout<<"ori x"<<rd<<",x"<<rs1<<","<<imm<<endl;}

    imm=0;
    for(int k=20;k<=25;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }
    

     if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 )
    {cout<<"slli x"<<rd<<",x"<<rs1<<","<<imm<<endl;}

     if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 && ins[1]==0  )
    {cout<<"srli x"<<rd<<",x"<<rs1<<","<<imm<<endl;}
     
     if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 && ins[1]==1 )
    {cout<<"srai x"<<rd<<",x"<<rs1<<","<<imm<<endl;}


}
else if(ins[31-6]==0 && ins[31-5]==0 && ins[31-4]==0 &&ins[31-3]==0 && ins[31-2]==0 && ins[31-1]==1 && ins[31-0]==1){

    rd=0;
    for(int k=7;k<12;k++){
     rd=rd+ins[31-k]*pow(2,k-7); 
    }

    rs1=0;
    for(int k=15;k<20;k++){
     rs1=rs1+ins[31-k]*pow(2,k-15); 
    }
    
    imm=0;
    for(int k=20;k<=31;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }
    int imm1=imm;
    if(ins[0]==1) { imm=imm-pow(2,12);}


  if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"lb x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;}

 if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 )
    {cout<<"lh x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;}

     if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"lbu x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;}

     if(ins[31-14]==0 && ins[31-13]==1 && ins[31-12]==0  )
    {cout<<"lw x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;}

     if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1   )
    {cout<<"lhu x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;}
     
     if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==0 )
    {cout<<"lwu x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;}
    
    if(ins[31-14]==0 && ins[31-13]==1 && ins[31-12]==1  )
    {cout<<"ld x"<<rd<<","<<imm<<"(x"<<rs1<<")"<<endl;


}
}
 else if(ins[31-6]==0 && ins[31-5]==1 && ins[31-4]==0 &&ins[31-3]==0 && ins[31-2]==0 && ins[31-1]==1 && ins[31-0]==1){

    imm=0;
    for(int k=7;k<12;k++){
     imm=imm+ins[31-k]*pow(2,k-7); 
    }

    rs1=0;
    for(int k=15;k<20;k++){
     rs1=rs1+ins[31-k]*pow(2,k-15); 
    }

     rs2=0;
    for(int k=20;k<=24;k++){
     rs2=rs2+ins[31-k]*pow(2,k-20); 
    }
     
     for(int k=25;k<32;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }

    if(ins[0]==1) {imm=imm-pow(2,12);}

    if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"sb x"<<rs2<<","<<imm<<"(x"<<rs1<<")"<<endl;}

if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 )
    {cout<<"sh x"<<rs2<<","<<imm<<"(x"<<rs1<<")"<<endl;}

   if(ins[31-14]==0 && ins[31-13]==1 && ins[31-12]==0 )
    {cout<<"sw x"<<rs2<<","<<imm<<"(x"<<rs1<<")"<<endl;}

 if(ins[31-14]==0 && ins[31-13]==1 && ins[31-12]==1 )
    {cout<<"sd x"<<rs2<<","<<imm<<"(x"<<rs1<<")"<<endl;}

 }
 else if(ins[31-6]==1 && ins[31-5]==1 && ins[31-4]==0 &&ins[31-3]==0 && ins[31-2]==0 && ins[31-1]==1 && ins[31-0]==1){

  

    rs1=0;
    for(int k=15;k<20;k++){
     rs1=rs1+ins[31-k]*pow(2,k-15); 
    }

     rs2=0;
    for(int k=20;k<=24;k++){
     rs2=rs2+ins[31-k]*pow(2,k-20); 
    }

      imm=0;
      
    for(int k=8;k<12;k++){
     imm=imm+ins[31-k]*pow(2,k-7); 
    }
     
     for(int k=25;k<31;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }

    imm=imm+ins[31-31]*pow(2,12);
    imm=imm+ins[31-7]*pow(2,11);

    if(ins[0]==1) {imm=imm-pow(2,13);}

    for( p=0;p<=q;p++){
        if((r+(imm/4))==z[p]){break;}
    }


    if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"beq"<<" x"<<rs1<<",x"<<rs2<<","<<"L"<<p<<endl;}

if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==1 )
    {cout<<"bne"<<" x"<<rs1<<",x"<<rs2<<","<<"L"<<p<<endl;}

   if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"blt"<<" x"<<rs1<<",x"<<rs2<<","<<"L"<<p<<endl;}

 if(ins[31-14]==1 && ins[31-13]==0 && ins[31-12]==1 )
    {cout<<"bge"<<" x"<<rs1<<",x"<<rs2<<","<<"L"<<p<<endl;}
    
 if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==0 )
    {cout<<"bltu"<<" x"<<rs1<<",x"<<rs2<<","<<"L"<<p<<endl;}
    if(ins[31-14]==1 && ins[31-13]==1 && ins[31-12]==1 )
    {cout<<"bgeu"<<" x"<<rs1<<",x"<<rs2<<","<<"L"<<p<<endl;}

 }
else if(ins[31-6]==1 && ins[31-5]==1 && ins[31-4]==0 &&ins[31-3]==1 && ins[31-2]==1 && ins[31-1]==1 && ins[31-0]==1){

  

    rd=0;
    for(int k=7;k<12;k++){
     rd=rd+ins[31-k]*pow(2,k-7); 
    }

  

      imm=0;
      
    for(int k=12;k<20;k++){
     imm=imm+ins[31-k]*pow(2,k); 
    }
     imm=imm+ins[31-20]*pow(2,11);

     for(int k=21;k<31;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }
     imm=imm+ins[31-31]*pow(2,20);

     if(ins[0]==1) {imm=imm-pow(2,12);}

      for( p=0;p<=q;p++){
        if((r+(imm/4))==z[p]){break;};
    }


    if(ins[31-14]==0 && ins[31-13]==0 && ins[31-14]==0 )
    {cout<<"jal "<<"x"<<rd<<","<<"L"<<p<<endl;}
}
else  if(ins[31-6]==1 && ins[31-5]==1 && ins[31-4]==0 &&ins[31-3]==0 && ins[31-2]==1 && ins[31-1]==1 && ins[31-0]==1){

      rd=0;
    for(int k=7;k<12;k++){
     rd=rd+ins[31-k]*pow(2,k-7); 
    }

    rs1=0;
    for(int k=15;k<20;k++){
     rs1=rs1+ins[31-k]*pow(2,k-15); 
    }
    
    imm=0;
    for(int k=20;k<=31;k++){
     imm=imm+ins[31-k]*pow(2,k-20); 
    }
     if(ins[0]==1) {imm=imm-pow(2,12);}

         for( p=0;p<=q;p++){
        if((r+imm/4)==z[p]){break;};
    }

    if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"jalr x"<<rd<<",x"<<rs1<<","<<imm<<endl;}
}
else  if(ins[31-6]==0 && ins[31-5]==1 && ins[31-4]==1 &&ins[31-3]==0 && ins[31-2]==1 && ins[31-1]==1 && ins[31-0]==1){

  

    rd=0;
    for(int k=7;k<12;k++){
     rd=rd+ins[31-k]*pow(2,k-7); 
    }
imm=0;
      
    for(int k=12;k<=31;k++){
     imm=imm+ins[31-k]*pow(2,k-12); 
    }
    if(ins[0]==1) {imm=imm-pow(2,12);}
    

    if(ins[31-14]==0 && ins[31-13]==0 && ins[31-12]==0 )
    {cout<<"lui "<<"x"<<rd<<",0x";
    cout<<line[0]<<line[1]<<line[2]<<line[3]<<line[4]<<endl;}
}

}
        return 0;
}