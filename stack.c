#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

int top = -1;
int stack[MAXSIZE];

void push();
int pop();
void traverse(int);

int main(int argv, char** argc)
{
	int choice;
	while(1)
	{
		printf("1.PUSH.\n2.POP.\n3.TRAVERSE.\n4.EXIT\n");
		printf("Enter the choice what you want to do with stack: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				traverse(top);
				break;
			case 4:
				exit(-1);
			default:
				printf("You have entered a wrong choice!! Please choose correct one.......\n");
		}
	}
	return 0;
}

void push()
{
	int data;
	if(top==(MAXSIZE-1))
	{
		printf("STACK is full!!\n");
	}
	else
	{
		printf("Enter the data you want to enter: \n");
		scanf("%d",&data);
		top++;
		stack[top] = data;
	}
}

int pop()
{
	int data;
	if(top==(-1))
	{
		printf("STACK is empty!!\n");
	}
	else
	{
		data = stack[top];
		top--;
	}
	return (data);
}

void traverse(int top)
{
	if(top==(-1))
	{
		printf("STACK is empty!!\n");
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
