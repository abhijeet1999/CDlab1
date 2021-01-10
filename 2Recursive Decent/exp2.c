/*
E -> TB 
B -> +TB |ε
T -> aC | ε
C -> [M | ε
M -> ] | P |  ε
P -> X] |  ε
X -> EN
N -> ,E | ε 


Valid string: a + a [a, a]
Invalid string: [ ]a + a


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void E();
void T();
void B();
void C();
void M();
void P();
void X();
void N();
char *input;
int i=0,flag=0,counter=0;
void N(){
    printf("\n inside N ");
    if(input[i]==','){
        printf("\t\t ,");
        i++;
        E();
    }
    //else if(input[i]!=','){
     //   flag=1;
     //   return;
    ///}
    else
    return;
}

void C(){
    if(input[i]=='['){
        printf("\t\t [");
        i++;
        M();
    }
    
    else
    return;

}

void M(){
    printf("\n inside M ");
    if(input[i]==']'){
        printf("\t\t ]");
        i++;
        
    }
    
    else
    {
        X();
    if(input[i]==']'){
        printf("\t\t ]");
        i++;
        //return;
    }
    else{
    flag=1; }
    }
}

void B(){
    //printf("\t\t counter %d ",counter);
    printf("\n inside B ");
    if(input[i]=='+'){
        printf("\t\t +");
        i++;
        T();
        B();
        
    }
   
    
    else
    return;
}

void T(){
    printf("\n inside T ");
    if(isalpha(input[i])){
        printf("\t\t %c",input[i]);
     i++;
     C();
     
    }
    else {
        flag=1;
        //return;
    }
   
}

void E(){
    printf("\n inside E ");
    T();
   
    B();
}
void X(){
    printf("\n inside X ");
    E();
    N();
   
}

void main(){
    printf("\n Enter string- ");
    
    size_t bufsize = 32;
    size_t characters;

    input = (char *)malloc(bufsize * sizeof(char));
    
     getline(&input,&bufsize,stdin);
    //gets(input);
    E();
    //printf("\n\t\t\t%d=%dflag %d",i,strlen(input),flag);
    if(flag==0 && strlen(input)==i+1){
             printf("\n\n Valid ");
    }
    else
    printf("\n\n InValid ");
    
    
}


/*
OUTPUT


 Enter string- a+a[a,a]

 inside E 
 inside T 		 a
 inside B 		 +
 inside T 		 a		 [
 inside M 
 inside P 
 inside X 
 inside E 
 inside T 		 a
 inside B 
 inside N 		 ,
 inside E 
 inside T 		 a
 inside B 		 ]
 inside B 

 Valid 



 Enter string- []a+a

 inside E 
 inside T		flag 1
 inside B 

 InValid 

*/