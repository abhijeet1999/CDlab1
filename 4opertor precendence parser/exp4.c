#include<stdio.h>
#include <stdlib.h> 
#include<string.h>
char op[15],stack[100],buffer[100];
char table[10][20];
int top=-1;
void push(char c) 
{
    stack[++top]=c;
  
}
void pop()       
{
  if(top>=0)
    stack[top--]='\0';
  
} 

int main(){
    int n,i,j,flag=0;
    
    printf("\n Enter number of  operators including $  --  ");
    scanf("%d",&n);
    printf("\n Enter   operators including $---");
    scanf("%s",op);
    //printf("\n%s\n",op);
    //printf("%d",strlen(op));
    printf("\n Note add # for null");
    int k=0,count=0,count2;
    char temp;
   // char *ch ;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the value for %c and ",op[i]);
        for(j=0;j<n;j++)
        printf(" %c,\t",op[j]);
        scanf("%s",table[i]);
        
    }
    printf("\n");
    printf("  ");
    for(j=0;j<n;j++)
    printf("%c",op[j]);
    for(i=0;i<n;i++)
    {
        printf("\n%c %s",op[i],table[i]);
    
    }
    int ch=1,tem1;
    int count3,count4;
    int y;
    while(ch){
    printf("\n Enter a string for the grammer and end with $----");
    scanf("%s", buffer);
    push('$');
       if(strlen(buffer)%2==0){
        for(j=0;j<strlen(buffer);j++){
           if(buffer[j]!=buffer[j+1]){
           
            if((stack[top]=='$')&&(buffer[j]=='$')){
                printf("\n -----String accepted-----");
                flag=1;
            }
            else if(stack[top]=='\0' && buffer[j]!='\0'){
              flag=0;
              break;
            }
          //  else if((stack[top]!='$')&&(buffer[j]=='$')){
              //printf("\n -----String accepted-----");
          //      flag=0;

           // }
            else{
                printf("\nstack--%c and buffer--%c",stack[top],buffer[j]);
            //if(stack[top]!=buffer[j]){
                //printf("\nif-");
                for(k=0;k<n;k++)
                if(stack[top]==op[k])
                count=k;
                for(k=0;k<n;k++)
                if(buffer[j]==op[k])
                count2=k;
                printf("\ntable--%c",table[count][count2]);
                if(table[count][count2]=='<'){
                    push('<');
                    push(buffer[j]);
                }
                else if(table[count][count2]=='='){
                  push(buffer[j]);

                }
                else if(table[count][count2]=='>'){
                  printf("\nstack--%s",stack); 
                  tem1=stack[top];
                  do{
                     
                    pop();

                  }while(stack[top]!='<');

                   pop();
                   
                   for(k=0;k<n;k++)
                   if(tem1==op[k])
                   count3=k;
                   printf("\npop--%c",stack[top]);
                    for(k=0;k<n;k++)
                   if(stack[top]==op[k])
                   count4=k;
                   if(table[count4][count3]=='>'  ){
                     
                   if(stack[top]!='$'){
                       pop();
                     pop();
                     }
                  

                   }
                  
printf("\nstack--%s",stack); 
                   
                   

                   j--;
                }
                else if(table[count][count2]=='#'){

                   //printf("\n -----String accepted-----");
                flag=0;
                    break;;
                }
                else
                {
                    printf("\n -----String not accepted----");
                    flag=1;
                    break;
                }
                
                
          //  }
           /* else{
                printf("\n -----String not accepted----");
                    flag=1;
                    break;
            }*/
            }
        }
        else{
        flag=0;
        break;}
        }
    }
    else
    flag=0;
  if(flag==0)
   printf("\n -----String not accepted----");
   printf("\n\n");

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
output


 Enter number of  operators including $  --  6

 Enter   operators including $---+*()i$

 Note add # for null
Enter the value for + and  +,	 *,	 (,	 ),	 i,	 $,	>> <<><>

Enter the value for * and  +,	 *,	 (,	 ),	 i,	 $,	>><><>

Enter the value for ( and  +,	 *,	 (,	 ),	 i,	 $,	<<<=<#

Enter the value for ) and  +,	 *,	 (,	 ),	 i,	 $,	>>#>#>

Enter the value for i and  +,	 *,	 (,	 ),	 i,	 $,	>>#>#>

Enter the value for $ and  +,	 *,	 (,	 ),	 i,	 $,	<<<#<#

  +*()i$
+ ><<><>
* >><><>
( <<<=<#
) >>#>#>
i >>#>#>
$ <<<#<#
 Enter a string for the grammer and end with $----i+i*i$

 -----String accepted-----



*/