#include<stdio.h>
#define maxq 5
typedef struct que{
	int data[maxq];
	int front,rear;
}que;
void addq(que *,int);
int delq(que *);
void display(que);
int main()
{
	int item,ch;
	que q1;
	q1.front=q1.rear=-1;
	do{
		printf("1. ADD\n2. DELETE\n3. DISPLAY\n$. EXIT\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter item you want to add\n");
				scanf("%d",&item);
				addq(&q1,item);
				break;
			case 2:
				item=delq(&q1);
				if(item!=0)
					printf("The deleted item is %d\n",item);
				break;
			case 3:
				display(q1);
				break;
		}
	}while(ch!=4);
	return 0;
}
void addq(que *q1,int item)
{
	if(q1->rear==maxq-1)
	{
		printf("Overflow\n");
		return;
	}
	if(q1->front==-1)
	{
		q1->front=q1->rear=0;
	}
	else
	{
		q1->rear++;	
	}
	q1->data[q1->rear]=item;
}
int delq(que *q1)
{
	int item;
	if(q1->front==-1)
	{
		printf("Underfloe\n");
		return 0;
	}
	item=q1->data[q1->front];
	if(q1->front==q1->rear)
	{
		q1->rear=q1->front=-1;
	}
	else
	{
		q1->front++;	
	}
	return item;
}
void display(que q1)
{
	int i;
	if(q1.front==-1)
	{
		printf("The queue is empty");
		return;
	}
	printf("Queue is\n");
	for(i=q1.front;i<=q1.rear;i++)
	{
		printf("%d\t",q1.data[i]);
	}
	printf("\n");
		
}
