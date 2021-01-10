/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int top=-1;
char stack[100],buffer[100],op[15],production[10][10];
void push(char c) 
{
    stack[++top]=c;
  
}
void pop()       
{
  if(top>=0)
    stack[top--]='\0';
  
} 
int main()
{
  char table[30][30][3];
  int i,j,n,m,k,l,count;
  char line[108][2];
	char fname[20];
    FILE *fptr = NULL; 
    i = 0;
    int tot = 0;
    fptr= fopen ("exp5_input_program.txt", "r");

  if (fptr == NULL)
    {
      printf ("Error while opening the file!\n");
      exit (0);
    }
   
   
    
  printf("\n Assume NULL opertor as #");
  printf("\n Assume Shift opertor as s");
  printf("\n Assume Reduce opertor as r");
  printf("\n Assume Accept opertor as a");
  printf("\nEnter Total Number of Productions:\t");
  scanf("%d", &count);
  for(i = 0; i < count; i++)
      {
            printf("\nValue of Production Number [%d]:\t", i + 1);
            scanf("%s", production[i]);
      }
  printf("\n Enter Total number of states including 0- ");
  scanf("%d",&n);
  printf("\n Enter number of Actions and Goto- ");
  scanf("%d",&m);
  printf("\n Enter Actions and Goto symbols- ");
  scanf("%s",op);
  
    i=0;
  for (k=0;k<n;k++){
      for (j=0;j<m;j++){
      fscanf(fptr, "%s",line[i]);
      strcpy(table[k][j],line[i]);
      //printf("%s\n",table[k][j]);
      i++;
      }
  }
    
  /* for (k=0;k<n;k++){
     for (j=0;j<m;j++){
      printf("%c\n",table[k][j][0]);
         
     }
       
   }
   */
   int count2,count1,pp,kk,len,key=0;;
   //pp=5;
           //len=strlen(production[pp]);
           //printf("\n LEN %d",len);
           //printf("\ns  %c",table[2][1][1]);
          // printf("\nr  %c",table[3][1][1]);
   char temp[22];
   char temp2[22];
   char temp3[22];
   char temp4[22];
   int ch=1;
    int y;
    while(ch){
   printf("\n Enter a string for the grammer and end with $----");
   scanf("%s", buffer);
   push('0');
   if(strlen(buffer)%2==0){
   for(l=0;l<strlen(buffer);l++){
     if(buffer[l]!=buffer[l+1]){
       printf("\n topp %c",stack[top]);
       printf("\n buffer status %c",buffer[l]);
       
       for(k=0;k<strlen(op);k++)
       if(buffer[l]==op[k])
       count2=k;//printf("%c",stack[top]);
       temp[0]=stack[top];
       

       if(isalnum(stack[top]) && key==0)
       count1= atoi(temp) ;

       if(isalnum(stack[top]) && key==1){
          temp3[1]=stack[top];
          temp3[0]=stack[top-1];
          count1= atoi(temp3) ;
          

       }
       printf("\ntable - %c",table[count1][count2][0]);
       if(table[count1][count2][0]=='s'){
           printf("\n push - %c",buffer[l]);
           if(isalnum(table[count1][count2][1])&& table[count1][count2][2]=='#')
           {
            printf("\npushing - %c",table[count1][count2][1]);
           push(buffer[l]);
           push(table[count1][count2][1]);
           }
           if(isalnum(table[count1][count2][1])&& isalnum(table[count1][count2][2]))
           {
              printf("\n sp pushing - %c",table[count1][count2][1]);
           push(buffer[l]);
           push(table[count1][count2][1]);
           push(table[count1][count2][2]);
           key=1;
           }
           
       }
        
       else if(table[count1][count2][0]=='r'){
         if(key==0){
           printf("\n tablll - %c",table[count1][count2][1]);
           
           temp2[0] =table[count1][count2][1];
           pp=atoi(temp2)-1;
           printf("\njj-%d",pp);
           //printf("\n pro - %s",production[5]);

           printf("\n pro - %s",production[pp]);
           len=strlen(production[pp])-1;
           len=len*2;
           printf("\n %s",stack);
           printf("\n LEN %d",len);
            if(key==1){
              printf("\n poping--%c",stack[top]);
              pop();
              key=0;
for(kk=0;kk<len;kk++){
             printf("\n poping--%c",stack[top]);
             pop();
           }
            }
            else{
           for(kk=0;kk<len;kk++){
             printf("\n popinh--%c",stack[top]);
             pop();
           }
         }
           for(kk=0;kk<strlen(stack);kk++){
             if( stack[kk]==stack[top]){
               printf("\n stack top--%c",stack[top]);
               temp4[0]=stack[top];
               count1=atoi(temp4);
               break;
             }
           }
           
           printf("\npushed - %c",production[pp][0]);
           push(production[pp][0]);
           
           for(k=0;k<strlen(op);k++)
           if(production[pp][0]==op[k])
           count2=k;
           
           printf("\n count1 %d",count1);
           printf("\n count2 %d",count2);
           printf("\npusxhed - %c",table[count1][count2][1]);

          if(isalnum(table[count1][count2][1])&& isalnum(table[count1][count2][2])){
            printf("\n sp pushing - %c",table[count1][count2][1]);
          // push(buffer[l]);
           push(table[count1][count2][1]);
           push(table[count1][count2][2]);
           key=1;
          temp3[0]=stack[top];
          temp3[1]=stack[top-1];
          count1= atoi(temp3) ;
          l--;

       }
       else{
           push(table[count1][count2][1]);
           l--;}
         }
         else{
            printf("\n tablll - %c",table[count1][count2][1]);
           
           temp2[0] =table[count1][count2][1];
           pp=atoi(temp2)-1;
           printf("\njj-%d",pp);
           //printf("\n pro - %s",production[5]);

           printf("\n pro - %s",production[pp]);
           len=strlen(production[pp])-1;
           len=len*2;
           printf("\n %s",stack);
           printf("\n LEN %d",len);
           pop();
           for(kk=0;kk<len;kk++){
             printf("\n popinh--%c",stack[top]);
             pop();
           }
           for(kk=0;kk<strlen(stack);kk++){
              printf("\n stack top--%c",stack[top]);
               temp4[0]=stack[top];
               count1=atoi(temp4);
               break;
             
           }
           
           printf("\npushed - %c",production[pp][0]);
           push(production[pp][0]);
           
           for(k=0;k<strlen(op);k++)
           if(production[pp][0]==op[k])
           count2=k;
           
           printf("\n count1 %d",count1);
           printf("\n count2 %d",count2);
           printf("\npusxhed - %c",table[count1][count2][1]);
           push(table[count1][count2][1]);
           l--;
           key=0;

         }
       }
       else if(buffer[l]=='$'){
           printf("\n %s",stack);
           if(table[count1][count2][0]=='a'){
               printf("\n String Accept");
           }
           else
           printf("\n String Reject");
             
       }
   }
   else{
    printf("\n String Reject");
    break;}
     
   }
    }
    else
    printf("\n String Reject");
   printf("\n fo u want to continue 1/0 =");
  scanf("%d",&y);
  if(y==1){
    top=-1;
    ch=1;
  }
  else
  ch=0;
    
    
}
   return 0;
}
/*
Assume NULL opertor as #
 Assume Shift opertor as s
 Assume Reduce opertor as r
 Assume Accept opertor as a
Enter Total Number of Productions:  6

Value of Production Number [1]: EE+T

Value of Production Number [2]: ET

Value of Production Number [3]: TT*F

Value of Production Number [4]: TF

Value of Production Number [5]: F(E)

Value of Production Number [6]: Fl

 Enter Total number of states including 0- 12

 Enter number of Actions and Goto- 9

 Enter Actions and Goto symbols- +*()l$ETF

 Enter a string for the grammer and end with $----l*l+l$

 topp 0
 buffer status l
table - s
 push - l
pushing - 5
 topp 5
 buffer status *
table - r
 tablll - 6
jj-5
 pro - Fl
 0l5
 LEN 2
 popinh--5
 popinh--l
 stack top--0
pushed - F
 count1 0
 count2 8
pusxhed - 3
 topp 3
 buffer status *
table - r
 tablll - 4
jj-3
 pro - TF
 0F3
 LEN 2
 popinh--3
 popinh--F
 stack top--0
pushed - T
 count1 0
 count2 7
pusxhed - 2
 topp 2
 buffer status *
table - s
 push - *
pushing - 7
 topp 7
 buffer status l
table - s
 push - l
pushing - 5
 topp 5
 buffer status +
table - r
 tablll - 6
jj-5
 pro - Fl
 0T2*7l5
 LEN 2
 popinh--5
 popinh--l
 stack top--7
pushed - F
 count1 7
 count2 8
pusxhed - 1
 sp pushing - 1
 topp 0
 buffer status +
table - r
 tablll - 3
jj-2
 pro - TT*F
 0T2*7F10
 LEN 6
 popinh--1
 popinh--F
 popinh--7
 popinh--*
 popinh--2
 popinh--T
 stack top--0
pushed - T
 count1 0
 count2 7
pusxhed - 2
 topp 2
 buffer status +
table - r
 tablll - 2
jj-1
 pro - ET
 0T2
 LEN 2
 popinh--2
 popinh--T
 stack top--0
pushed - E
 count1 0
 count2 6
pusxhed - 1
 topp 1
 buffer status +
table - s
 push - +
pushing - 6
 topp 6
 buffer status l
table - s
 push - l
pushing - 5
 topp 5
 buffer status $
table - r
 tablll - 6
jj-5
 pro - Fl
 0E1+6l5
 LEN 2
 popinh--5
 popinh--l
 stack top--6
pushed - F
 count1 6
 count2 8
pusxhed - 3
 topp 3
 buffer status $
table - r
 tablll - 4
jj-3
 pro - TF
 0E1+6F3
 LEN 2
 popinh--3
 popinh--F
 stack top--6
pushed - T
 count1 6
 count2 7
pusxhed - 9
 topp 9
 buffer status $
table - r
 tablll - 1
jj-0
 pro - EE+T
 0E1+6T9
 LEN 6
 popinh--9
 popinh--T
 popinh--6
 popinh--+
 popinh--1
 popinh--E
 stack top--0
pushed - E
 count1 0
 count2 6
pusxhed - 1
 topp 1
 buffer status $
table - a
 0E1
 String Accept
 fo u want to continue 1/0 =1



*/