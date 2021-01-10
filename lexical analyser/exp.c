/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main ()
{
  char ch;
  char buffer[100],buffer2[100],dig[10],op[10];
  char inden[10][100];
  int id=0,n=0;
  int inString = 0;
  int state = 1;
  int p;
  int instring2=0,counter=0;
  int instring3=0;
  int k=0,j=0,m=0,opc=0,fin=0;
  FILE *fp;
  fp = fopen ("exp1_input_program.txt", "r");

  if (fp == NULL)
    {
      printf ("Error while opening the file!\n");
      exit (0);
    }
  while ((ch = fgetc (fp)) != EOF)
    {
     //printf("\nstate=%d",state);
      //printf("\n %c",ch);
    
      switch (state)
	{
	case 1: if(ch=='{'){state=2;break;}
	        else if(ch=='}'){ printf("\n< Delimter,} >"); state=1; break;}
	        else if(ch==','){ printf("\n< Delimter, ',' >"); state=1; break;}
	        else if(ch=='('){ state=3; break;}
	        else if (isalpha(ch)){
	            instring2 = 1;
	             counter=0;
	            k=j;
	            buffer2[j++] = ch;
	            if(ch=='i') { state=7;
	            j = 0;
	           // buffer2[j++] = ch;
	            instring2 = 0;
                
                k=0;
                break;}
                else if(ch=='c') { state=11;
	            instring2 = 0;
                j = 0;
                k=0;
                break;}
                else if(ch=='f') { state=15;
	            instring2 = 0;
                j = 0;
                k=0;
                break;}
                else if(ch=='e') { state=17;
	            instring2 = 0;
                j = 0;
                k=0;
                break;}
                else if(ch=='t') { state=23;
	            instring2 = 0;
                j = 0;
                k=0;
                break;}
                state=10;
                break;
	        }
	        else if (ch=='+'|| ch=='-' || ch=='*'|| ch=='/'|| ch=='='|| ch== '>' || ch == '<' ){
	            state=22;
	            op[m++] = ch;
	            opc=1;
	            break;
	        }
	      
	        else if(isdigit(ch)){
	            instring3 = 1;
	            dig[n++] = ch;
	            state=20;
	            break;
	        }
	  
	        else{ state=1;break;}
	case 2: if (ch==' ') {
	        printf("\n< Delimiter ,{ >");
	        state=1;
	        break;}
	case 3: if (ch==' ' || ch==')' || ch=='"') {
	        printf("\n< Delimiter,( >");
	        if(ch==')'){ 
	            printf("\n< Delimiter ,) >");
	            state=1;
	            break;
	            
	        }
	        else if(ch=='"'&&inString==0){
	             printf("\n< Delimiter, '' > ");
	             state=4;
	             break;
	        }
	        state=1;
	        }
	        break;
	 case 4:if(isalnum(ch)){
	            inString = 1;
	            buffer[k++] = ch;
	            state=4;
	            break;
	        }
	        else if(ch=='"'&& inString ==1){
	            inString = 0;
                buffer[k] = '\0';
                printf("\n< literals,%s >", buffer);
                printf("\n< Delimiter, '' >");
                k = 0;
                state=5;
                break;
	        }
	        else {
	            state=1;
	            break;
	            
	        }
	  case 5:if(ch==')'){
	      printf("\n< Delimiter ,) >");
	      state=6;
	      break;
	      }
	      
	  case 6:   printf("\n< Delimiter , ; >"); 
	            state=1;
	            break;
	  case 7: if(ch=='f'){
	             state=1; 
	             printf("\n< Keyword , if >"); 
	             break;}
	             else if (ch=='n'){state=8; break;}
	           else{
	                   /* if(isalnum(ch)||ch==' ')
	                    {
	                        if(ch==' ')
	                        {
	                            //printf("id %d",id);
	                            buffer2[j] = '\0';
	                            if(id==0)
	                            {
                                    printf("\n< identifier , %d >",id);
                                    strcpy(inden[id++],buffer2);
                                    j=0;
                                    state=1;
                                    break;
                                }
                                for(p=0;p<id;p++)
                                {
                                //printf("\n buffer=");
                                    if(strcmp((inden + p),buffer2)==0){
                                    printf("\n< identifier , %d >",p);
                                //printf("\n< identifier , %s >",buffer2);
                                    j=0;
                                    state = 1;
                                    counter=1;
                                    break;
                                        }
    
                                }
                                if(counter==0)
                                {
                                
                                    printf("\n< identifier , %d >",id);
                                    strcpy(inden[id++],buffer2);
                                    state=1;
                                    j=0;
                                    break;
                                }
                           
	                        }
	                  // buffer2[j++] = ch;
	  
	               }*/
	               //j=0;
	           state=1;
	           break;}
	 case 8: if(ch=='t'){state=9; break;}
	 case 9: if(ch==' '){state=1; printf("\n< type , int >"); break; }
	 case 10: if(isalnum(ch) || ch==';' || ch==' ')
	           {
	 
	                //inden[id][k++]=ch;
	                buffer2[j++] = ch;
	                if(ch==';' || ch==' ')
	                {

                        if(ch==' '&& instring2==1)
                        {
                            instring2 = 0;
                            buffer2[j++] = ch;
                            buffer2[j] = '\0';
                            j = 0;
                            k=0;
                            if(id==0){
                                printf("\n< identifier , %d >",id);
                                strcpy(inden[id++],buffer2);
                                
                                state=1;
                                break;
                            }
        
                            for(p=0;p<id;p++)
                            {
                                //printf("\n buffer=");
                                if(strcmp((inden + p),buffer2)==0){
                                printf("\n< identifier , %d >",p);
                                //printf("\n< identifier , %s >",buffer2);
                                state = 1;
                                counter=1;
                                break;
                                }
    
                            }
                            if(counter==0){
                                
                            printf("\n< identifier , %d >",id);
                             strcpy(inden[id++],buffer2);
                                state=1;
                                break;
                            }
                
                        }
                    if(ch==';' && instring2==1)
                    {
                        instring2 = 0;
                            buffer2[j++] = ch;
                            buffer2[j] = '\0';
                            j = 0;
                            k=0;
                            if(id==0){
                                printf("\n< identifier , %d >",id);
                                strcpy(inden[id++],buffer2);
                                
                                state=1;
                                break;
                            }
        
                            for(p=0;p<id;p++)
                            {
                                //printf("\n buffer=");
                                if(strcmp((inden + p),buffer2)==0){
                                printf("\n< identifier , %d >",p);
                                //printf("\n< identifier , %s >",buffer2);
                                state = 1;
                                counter=1;
                                break;
                                }
    
                            }
                            if(counter==0){
                                
                            printf("\n< identifier , %d >",id);
                             strcpy(inden[id++],buffer2);
                                state=1;
                                break;
                            }
                
                
                    }
	           }
	           //state=10;
	           break;
	          }
	         case 11: if(ch=='h'){state=12; break;}
	         case 12: if(ch=='a'){state=13; break;}
	         case 13: if(ch=='r'){state=14; break;}
	         case 14: if(ch==' '){state=1; printf("\n< type , char >"); break; }
	         case 15: if(ch=='o'){state=16; break;}
	         case 16: if(ch=='r'){
	             state=1; 
	             printf("\n< Keyword , for >"); 
	             break;}
	        case 17: if(ch=='l'){state=18; break;}
	         case 18: if(ch=='s'){state=19; break;}
	         case 19: if(ch=='e'){state=1; 
	                       printf("\n< Keyword , else >"); 
	                        break;}
	         case 20: if(isdigit(ch)&&instring3==1){
	                    instring3 = 0;
                        dig[n++] = ch;
                        dig[n] = '\0';
	                    //printf("%c",ch);
	                    // printf("\n< Numbers,%s >",dig);
	                    // n=0;
	                    state=20;
	                    break;
	                    }
	                  else if(ch==' '|| ch==';'&&instring3 ==1){
	                    instring3 = 0;
	                   // n--;
	                   // dig[n] = '\0';
	                    printf("\n< Numbers,%s >",dig);
	                    state=6;
	                    for(int i=0;i<n;i++){
	                        dig[i]=' ';
	                    }
	                    n=0;
	                     break;
	             
	                    }
	                    else if(isalpha(ch)){
	                        state=21;
	                        break;
	                    }
	        case 21:if(isalnum(ch)|| ch==' '|| ch==';'){
	                 // printf("\nLexical")
	                 if(ch==' '){
	                     printf("\nLexical Error");
	                     state=1;
	                     break;
	                 }
	                 if(ch==';'){
	                     printf("\nLexical Error");
	                     state=6;
	                     break;
	                 }
	                 n=0;
	                 state=21;
	                 break;
	              }
	              
	     case 22:if(ch==' '){
	                 opc=0;
	                     op[m] = '\0';
	                     printf("\n< Operators,%s >",op);
	                     m=0;
	                     state=1;
	                     break;
	             }
	             else if(ch=='+'){
	                 m=0;
	                 printf("\n< Operators, ++ > ");
	                 state=1;
	                     break;
	                 
	             }
	             else if(ch=='='){
	                 m=0;
	                 printf("\n< Operators, == > ");
	                 state=1;
	                     break;
	                 
	             }
	      case 23: if(ch=='h'){state=24; break;}
	         case 24: if(ch=='e'){state=25; break;}
	         case 25: if(ch=='n'){state=26; break;}
	         case 26: if(ch==' '){state=1; printf("\n< Keyword , then >"); break; }
	        
	 

	}
    }
    
    printf("\n*************************\n");
    printf("id  \t lexeme\n");
    for(p=0;p<id;p++){
        printf("id=%d  ** string=%s\n",p,(inden+p));
    }
    printf("****************************");

  return 0;
}



/*

< identifier , 0 >
< identifier , 1 >
< Delimiter,( >
< Delimiter ,) >
< Delimiter ,{ >
< type , int >
< identifier , 2 >
< Operators,= >
< Numbers,10 >
< Delimiter , ; >
< type , char >
Lexical Error
< Delimter, ',' >
< identifier , 3 >
< Delimiter , ; >
< type , int >
< identifier , 4 >
< Delimiter , ; >
< Keyword , if >
< Delimiter,( >
< identifier , 2 >
< Operators,> >
< Numbers,5  >
< Delimiter , ; >
< Keyword , then >
< identifier , 5 >
< Delimiter,( >
< Delimiter, '' > 
< literals,hhhfhh >
< Delimiter, '' >
< Delimiter ,) >
< Delimiter , ; >
< Keyword , else >
< identifier , 5 >
< Delimiter,( >
< Delimiter, '' > 
< literals,fnfjjf >
< Delimiter, '' >
< Delimiter ,) >
< Delimiter , ; >
< Keyword , for >
< Delimiter,( >
< identifier , 4 >
< Operators,= >
< Numbers,0  >
< Delimiter , ; >
< identifier , 4 >
< Operators,< >
< Numbers,9  >
< Delimiter , ; >
< identifier , 4 >
< Operators, ++ > 
< Delimiter ,{ >
< Delimter,} >
< Delimter,} >
*************************
id  	 lexeme
id=0  ** string=void  
id=1  ** string=main  
id=2  ** string=num  
id=3  ** string=nam8e  
id=4  ** string=j  
id=5  ** string=printf  
****************************

*/
