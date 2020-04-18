
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100
typedef  struct queue
{
  int data[MAXSIZE];
  int size;
}Queue;

Queue* CreateQueue()
{
  Queue*q=(Queue*)malloc(sizeof(Queue));
  q->size=0;
  return q;
}
bool QueueIsEmpty(Queue*q)
{
 return(q->size==0);
}
int QueueLemgth(Queue*q)
{
  if(q==NULL)
{
  return 0;
}
  return q->size;
}
void pushQueue(Queue*q,int x)
{
  if(q->size==MAXSIZE)
  {
    return;
  }
  if(q==NULL)
  {
    return;
  }
  q->data[q->size++]=x;

}
void popQueue(Queue*q)
{
  if(q==NULL)
  {
    return;
  }
  if(q->size==0)
  {
    return;
  }
  for(int i=0;i<q->size-1;i++)
  {
    q->data[i]=q->data[i+1];
  }
  q->size--;

}
int ProQueue(Queue*q)
{
  if(q==NULL)
  {
    return 0;
  }
  if(q->size==0)
  {
    return 0;
  }
  else{
    return q->data[0];
  }
}
int BackQueue(Queue*q)
{
  if(q==NULL)
  {
    return 0;
  }
  if(q->size==0)
  {
    return 0;
  }
  else
  {
    return q->data[q->size-1];
  }
}
void ClearQueue(Queue*q)
{
  if(q==NULL)
  {
    return;
  }
  q->size=0;

}
void DestroyQueue(Queue*q)
{
  if(q==NULL)
  {
    return;
  }
  free(q);
}
void Println(Queue*q)
{
  for(int i=0;i<q->size;i++)
  {
    printf("%d ",q->data[i]);
  }
  printf("\n");
}
void test()
{
  Queue*q=CreateQueue();
  int b=QueueIsEmpty(q);
  printf("%d\n",b);
  pushQueue(q,1);
  pushQueue(q,2);
  pushQueue(q,3);
  pushQueue(q,4);
  Println(q);
  popQueue(q);
  Println(q);
  printf("%d\n",QueueLemgth(q));
  int c=ProQueue(q);
  printf("%d\n",c);
  int a=QueueIsEmpty(q);
  printf("%d\n",a);
  DestroyQueue(q);


}
int main(void) {
  test();
  
  return 0;
}
