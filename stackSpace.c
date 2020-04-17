#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct 
{
  int data[100];
  int min[100];
  int size;
}Stack;
Stack *BuildStack()
{
  Stack*s=(Stack*)malloc(sizeof(Stack));
  s->size=0;
  return s;
}

void push(Stack*s,int x)
{
  s->data[s->size]=x;
  if(s->size==0||s->data[s->size-1]>x)
  {
    s->min[s->size]=x;
  }
  else{
    s->min[s->size]=s->min[s->size-1];
  }
  s->size++;

}
void pop(Stack *s)
{
  s->size--;
}
void  Println(Stack*s)
{
 for(int i=0;i<s->size;i++)
 {
   printf("%d ",s->data[i]);

 }
 printf("\n");
}
int minStack(Stack*s)
{
 
  return s->min[s->size-1];
}
void test()
{
  Stack* s;
  s=BuildStack();
  push(s,10);
  push(s,20);
  Println(s);
  push(s,30);
  push(s,40);
  Println(s);
  pop(s);
  Println(s);
  push(s,1);
  push(s,2);
  Println(s);
  push(s,100);
  Println(s);
  push(s,200);
  Println(s);
  int c=minStack(s);
  printf("%d\n",c);

}


int main() {
  clock_t start,finish;
  double Total_Time;
  start=clock();
  test();
  finish=clock();
  Total_Time=(double)(finish-start)/CLOCKS_PER_SEC;
  printf("%lf",Total_Time);
  return 0;
}
