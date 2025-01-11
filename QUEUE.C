#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void insert();
void delete();
void display();
int front=-1,rear=-1;
int queue[maxsize];
void main(){
int choice;
clrscr();
while(1)
{
printf("\n1.insert an element\n2.delete an element\n3.display\n4.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:insert();
break;
case 2:delete();
break;
case 3:display();
break;
case 4:exit(0);
break;
default:printf("enter the valid choice!\n");
   }
  }
}
void insert() {
int item;
if(rear==maxsize-1)
{
printf("queue overflow\n");
return;
}
printf("enter the element:");
scanf("%d",&item);
if(front==-1&&rear==-1)
{
front=0;
rear=0;
}
else{
rear=rear+1;
}
queue[rear]=item;
printf("%d value inserted \n");
}

void delete(){
if(front==-1||front>rear)
{
printf("queue underflow");
return;
}
printf("value deleted:%d \n",queue[front]);
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=front+1;
}
}
void display(){
int i;
if(rear==-1)
{
printf("queue is empty\n");
}
else
{
printf("queue element are:\n");
for(i=front;i<=rear;i++)
{
printf("%d",queue[i]);
}
printf("/n");
}
}