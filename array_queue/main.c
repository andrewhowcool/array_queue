//
//  main.c
//  array_queue
//
//  Created by 楊博名 on 2016/11/15.
//  Copyright © 2016年 楊博名. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front, rear;

int isFull();
int isEmpty();
void add();
void del();
void display();

int main(void)
{
    int choice;
    
    
    while(1)
    {
        printf("enter option (-1 to quit)\n");
        printf("(1) add \n(2)delete \n(3) display\n");
        scanf("%d",&choice);
        
        if(choice==-1)
            break;
        
        switch(choice)
        {
            case 1:		add();	break;
            case 2:		del();	break;
            case 3:		display();	break;
            default:	printf("WRONG option !\n");	break;
        }
    }
    
    
    return 0;
}


//fuction
int isFull()
{
    if((rear+1)%MAX == front)//if rear+1 ==front: full
    {
        printf("queue is full\n");
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if(front%MAX == rear%MAX)//if rear ==front: empty
    {
        printf("queue is empty\n");
        return 1;
    }
    return 0;
}

void add()
{
    int data;
    
    if(isFull()==0)
    {
        printf("enter the data\n ");
        scanf("%d",&data);
        rear++;
        rear%=MAX;//rear=rear%MAX
        printf("enter data %d\n\n",data);
        queue[rear] = data;
    }
}


void del()
{
    if(isEmpty()==0)
    {
        front++;
        front%=MAX;
        printf("delete data %d\n\n",queue[front]);
    }
}

void display()
{
    for(int i = (front+1)%MAX; i <= (rear%MAX);i++)
    {
        printf("%d ",queue[i]);
        i%=MAX;
    }
    printf("\n");
}



