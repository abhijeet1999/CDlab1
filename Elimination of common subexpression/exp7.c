#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <math.h>
char production[10][10],new[10][10];

int main(){
  int l=0;
  int count,i,j=0,k;
  char t1,t2,flag=0;
  //
  printf("\nEnter Total Number of statment:\t");
  scanf("%d", &count);
  for(i = 1; i <= count; i++)
      {
            printf("\nValue of statment Number [%d]:\t", i );
            scanf("%s", production[i]);
      }
  //
    
char temp;
//printf("\n lm =%c",production[lm][0]);
for(i=1;i<=count;i++){
  if(strlen(production[i])==3){
    temp=production[i][2];
    for(k=i+1;k<=count;k++){
      if(production[k][2]==production[i][0]){
        production[k][2]=temp;

      }
     else  if(production[k][4]==production[i][0]){
        production[k][4]=temp;

      }

    }

  }
  
}
int num1,num2,num3;
char number[4];
char cho;
//int nam[4];
for(i=1;i<=count;i++){
  if(strlen(production[i])>3){
  if(isdigit(production[i][2])&& isdigit(production[i][4])){
    number[0]=production[i][2];
    num1=atoi(number);
    number[0]=production[i][4];
    num2=atoi(number);
    cho=production[i][3];
    switch(cho){
      case '+':num3=num1+num2; break;
      case '*':num3=num1*num2; break;
      case '-':num3=num1-num2; break;
      case '/': if(num2!=0){
        num3=num1/num2;} break;
      default: break;

    }

    
    //nam[0]=num3;
    //itoa(num3,number,10);

    production[i][2]=num3 +'0';
    //printf("\n pp =%c",production[i][2]);
    production[i][3]='\0';
    production[i][4]='\0';

  }
}

}
for(i=1;i<=count;i++){
  if(strlen(production[i])==3){
    temp=production[i][2];
    for(k=i+1;k<=count;k++){
      if(production[k][2]==production[i][0]){
        production[k][2]=temp;

      }
     else  if(production[k][4]==production[i][0]){
        production[k][4]=temp;

      }

    }

  }
  
}
int value=0,lm;
      for(i=1;i<=count;i++){
        //printf("\n flag- %d",flag);
      // printf("\n i[] =%c",production[i][0]);
        for(j=i+1;j<=count;j++){
         // printf("\n j[] =%c",production[j][0]);
         if(strlen(production[i])>3){
          for(k=2;k<5;k++){
            if(production[i][k]==production[j][k] && flag==0){
              value++;
             // printf("\n v =%d",value);
              if(value==3){
                lm=i;
                
                flag=1;;

              }
            }
          
            
          }
        }
          
        
          value=0;
          //break;

        }
      }
      flag=0;

j=0;
int o;
//printf("\n lm- %d",lm);
 for(i=1;i<=count;i++){
   if(lm==i && lm!=0){
   if(strlen(production[i])==5){
     //printf("\n j=%d",j);
     t1=production[i][2];
     t2=production[i][4];
     o=j;
     new[j][0]='t' +l;
          new[j][1]='=';
          new[j][2]=t1;
          new[j][3]=production[i][3];
          new[j++][4]=t2;
          for(k=i;k<=count;k++){
           // printf("\n j=%d",j);
          // printf("\n pp =%c",production[k][0]);
            if(t1!=production[k][0] && t2!=production[k][0]){
              // printf("\n ppj=%c",production[k][0]);
               if(strlen(production[k])==5){
                 if(t1==production[k][2]&& t2==production[k][4] && production[k][3]==production[i][3] && flag==0){
                  // printf("\n pph=%c",production[k][0]);
                  // printf("\n h=%c",new[j][0]);
                  // printf("\n j=%d",j);
                   new[j][0]=production[k][0];
                 new[j][1]='=';
                // j=j-1;
                 new[j][2]=new[o][0];
                 //j++;
                 j++;
                 }
                 else{
                //printf("\n pggh=%c",production[k][0]);
            strcpy(new[j++],production[k]);

               }

               }
            }
            else if((t1==production[k][0] || t2==production[k][0] )&& k==count){
           // printf("\n pph=%c",production[k][0]);
                 new[j][0]=production[k][0];
                 new[j][1]='=';
                 new[j++][2]=new[0][0];
          }
            else{
           //printf("\n prrh=%c",production[k][0]);
           flag=1;

            strcpy(new[j++],production[k]);

          }
          }
         
  // 
   }
   i=k;
   // break;
 }
 else if( lm==0){
     //printf("\n j=%d",j);
   //strcpy(new[j++],production[i]);
    strcpy(new[j++],production[i]);
   }
 else if(strlen(production[i])==3){
   strcpy(new[j++],production[i]);
 }
 else{
  // printf("\n pggh=%c",production[i][0]);
            strcpy(new[j++],production[i]);
 }

 }

/*
      for(i=0;i<count;i++){
        if(strlen(production[i])==5){
          t1=production[i][2];
          t2=production[i][4];
          new[j][0]='t' +l;
          new[j][1]='=';
          new[j][2]=t1;
          new[j][3]=production[i][3];
          new[j++][4]=t2;
          for(k=0;k<count;k++){
          //  printf("\n pp =%c",production[k][0]);
             if(t1!=production[k][0] && t2!=production[k][0]){
                printf("\n ppj=%c",production[k][0]);

             if(strlen(production[k])==5){
              
               if(t1==production[k][2]&& t2==production[k][4] && production[k][3]==production[i][3] && flag==0){
                 printf("\n pph=%c",production[k][0]);
                 new[j][0]=production[k][0];
                 new[j][1]='=';
                 new[j++][2]=new[0][0];
               }
               else{
                printf("\n pggh=%c",production[k][0]);
            strcpy(new[j++],production[k]);

               }
               



             }
          }
          else if((t1==production[k][0] || t2==production[k][0] )&& k==count-1){
            printf("\n pph=%c",production[k][0]);
                 new[j][0]=production[k][0];
                 new[j][1]='=';
                 new[j++][2]=new[0][0];
          }
          else{
           printf("\n prrh=%c",production[k][0]);
           flag=1;

            strcpy(new[j++],production[k]);

          }

          }
          break;
         //l++;
          

        }
        
      }*/
      for(i=0;i<=j;i++){
  if(strlen(new[i])>3){
  if(isdigit(new[i][2])&& isdigit(new[i][4])){
    number[0]=new[i][2];
    num1=atoi(number);
    number[0]=new[i][4];
    num2=atoi(number);
     cho=production[i][3];
    switch(cho){
      case '+':num3=num1+num2; break;
      case '*':num3=num1*num2; break;
      case '-':num3=num1-num2; break;
      case '/': if(num2!=0){
        num3=num1/num2;} break;
      default: break;

    }
    //nam[0]=num3;
    //itoa(num3,number,10);

    new[i][2]=num3 +'0';
    //printf("\n pp =%c",production[i][2]);
    new[i][3]='\0';
    new[i][4]='\0';

  }
}

}
      for(i = 0; i <= j; i++)
      {
          //  printf("\nValue of statment Number [%d]:\t", i + 1);
            printf("\n %s",new[i]);
      }
  return 0;
}
