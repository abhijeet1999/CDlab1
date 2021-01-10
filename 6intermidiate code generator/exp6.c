#include <stdio.h>
char tree[100]; char key;
int counter=0;
char get_right_child(int index)
{
    if(tree[index]!='\0' && ((2*index)+2)<=counter)
        return tree[(index * 2) + 2];
    return '-';
}
char get_left_child(int index)
{
    if(tree[index]!='\0' && ((index * 2) + 1)<=counter)
        return tree[(index * 2) + 1];
    return '-';
}
void root(){
 
  printf("Enter the root node -");
  scanf(" %c",&key);
  if(tree[0] != '\0')
        printf("\n Tree already had root");
    else{
        tree[0] = key;
      }
   
}
void left(){
  int parent;
  char key;
   printf("\n enter the nodes immdiate parent postion-");
   scanf(" %d",&parent);
    printf("\n Enter the left node char-");
    scanf(" %c",&key);
    if(tree[parent] == '\0'){
       printf("\n No such parent");
    }
    else{
    tree[(parent * 2) + 1] = key;
    counter=(parent * 2) + 1;}
}
void right(){
    int parent;
  char key;
   printf("\n enter the nodes immdiate parent postion-");
   scanf(" %d",&parent);
    printf("\n Enter the right node char-");
    scanf(" %c",&key);
    if(tree[parent] == '\0'){
       printf("\n No such parent");
    }
    else{
    tree[(parent * 2) + 2] = key;
    counter=(parent * 2) + 2;
    }
}

int main(void) {
  int i=1,j;
  int ch;
  int n;
  printf("\nEnter the tree ");
  printf("\n 1. Enter main root");
  root();
  printf("\n 1. Enter left node with parent");
  printf("\n 2. Enter right node with parent");
  printf("\n 3. Exit");
  while(i){ 
    printf("\n Enter choice==");
    scanf("%d",&ch);
    switch(ch){
      case 1: left(); break;
      case 2: right();break;
      default: i=0;break; 


    }
  }
char op,temp;

for( j = 0; j <= counter; j++)
    {
        if(tree[j] != '\0')
            printf("%c",tree[j]);
        else
            printf( "!");
    }
  char l;
  printf("\n");
   printf("\n");
   l='A';
    printf("Intermidiate code generator\n");
  for(j=counter;j>=0;j--){
    if(tree[j]!='\0'){
    op=tree[j];
    switch(op){
      case '=': printf("%c =",get_left_child(j));
                printf("%c",get_right_child(j));
                break;
      case '+': 
                printf("%c =",l);
                printf("%c + ",get_left_child(j));
                printf("%c\n",get_right_child(j));
                tree[j]=l;
                l++;
                break;
     case '*':   //l='H';
                printf("%c =",l);
                printf("%c * ",get_left_child(j));
                printf("%c\n",get_right_child(j));
                tree[j]=l;
                l=l+5;
                break;
       case '/': 
                printf("%c =",l);;
                printf("%c / ",get_left_child(j));
                printf("%c\n",get_right_child(j));
                tree[j]=l;
                l=l+5;
                break;
        case '-': printf("%c =",l);;
                printf("%c - ",get_left_child(j));
                printf("%c\n",get_right_child(j));
                tree[j]=l;
                l=l+5;

                break;
        default: break;
    }
  }
  
  }
    
  return 0;
}
/*
                          0,=
                        /    \
                      1,x     2,+
                      /        \
                    5,a        6,/   
                              /   \
                            13,*   14,d
                           /   \
                         27,b   28,c



Enter the tree 
 1. Enter main rootEnter the root node -=

 1. Enter left node with parent
 2. Enter right node with parent
 3. Exit
 Enter choice==1

 enter the nodes immdiate parent postion-0

 Enter the left node char-x

 Enter choice==2

 enter the nodes immdiate parent postion-0

 Enter the right node char-+

 Enter choice==1

 enter the nodes immdiate parent postion-2

 Enter the left node char-a

 Enter choice==2

 enter the nodes immdiate parent postion-2

 Enter the right node char-/

 Enter choice==1

 enter the nodes immdiate parent postion-6

 Enter the left node char-*

 Enter choice==2

 enter the nodes immdiate parent postion-6

 Enter the right node char-d

 Enter choice==1

 enter the nodes immdiate parent postion-13

 Enter the left node char-b

 Enter choice==2

 enter the nodes immdiate parent postion-13

 Enter the right node char-c

 Enter choice==3
=x+--a/------*d------------bc

Intermidiate code generator
2 =b + c
3 =2 + d
1 =a + 3
*/