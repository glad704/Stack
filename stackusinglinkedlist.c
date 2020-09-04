#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

typedef struct node
{
	int data;
	struct node* next;
}node;

node* top;
int count = 1;

node* push(node* top);
node* pop(node* top);
void Display(node* top);

int main(int argv,char* argc[])
{
	int choice;
	while(1)
	{
		printf("1.Push.\n2.Pop.\n3.Display.\n4.Exit.\n");
		printf("Enter the choice you want to do with stack: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				top = push(top);
				break;
			case 2:
				top = pop(top);
				break;
			case 3:
				Display(top);
				break;
			case 4:
				exit(0);
			default:
				printf("You have entered the wrong choice!! Please try again......!!\n");
		}
	}
	return 0;
}

node* push(node* top)
{
	node* temp;
	node* p;
	temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	printf("Enter the data you want to enter in stack: \n");
	scanf("%d",&(temp->data));
	if(top==NULL)
	{
		top = temp;
	}
	else
	{	
		if(MAXSIZE==count)
		{
			printf("Stack is full!!\n");
		}
		else
		{
			p = top;
			temp->next = p;
			top = temp;
			count++;
		}
	}
	return top;
}

node* pop(node* top)
{
	node* p;
	if(top==NULL || count<=0)
	{
		printf("Stack is empty!!\n");
	}
	else
	{
		printf("Deleted item is %d.\n",top->data);
		p = top;
		top = top->next;
		free(p);
		count--;
	}
	return top;
}

void Display(node* top)
{
	node* p;
	p = top;
	int k = count;
	if(top==NULL)
	{
		printf("Stack is empty!!\n");
	}
	else
	{
		for(int i=0;i<k;k--)
		{
			printf("%d\n",p->data);
			p = p->next;
			
		}
	}
}
