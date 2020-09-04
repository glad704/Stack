#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

int array[MAXSIZE];
int f1 = -1;
int f2 = -1;
int r1 = -1;
int r2 = -1;

void enqueue();
void dequeue();
void display();

int main(int argv,char* argc[])
{
	int choice;
	while(1)
	{
		printf("1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Exit.\n");
		printf("Enter the choice you want to do with Stack: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("You have entered a wrong choice!! Please try again....\n");
		}
	}
	return 0;
}

void enqueue()
{
	int data;
	if(f1==-1 || r1==-1)
	{
		printf("Queue 1 is empty!!\n");
		if(f2==-1 || r2==-1)
		{
			printf("Queue 2 is empty!!\n");
			printf("Stack is empty!!\n");
			f1 = 0;
			printf("Enter the data you want to enter in stack: \n");
			scanf("%d",&data);
			r1++;
			array[r1] = data;
		}
		else
		{
			if(r2==MAXSIZE-1)
			{
				printf("Stack is full!!\n");
			}
			else
			{
				f2 = 0;
				printf("Enter the data you want to enter in stack: \n");
				scanf("%d",&data);
				r2++;
				array[r2] = data;
			}
		}
	}
	else
	{
		if(r1==MAXSIZE-1)
		{
			printf("Stack is full!!\n");
		}
		else
		{
			f1 = 0;
			printf("Enter the data you want to enter in stack: \n");
			scanf("%d",&data);
			r1++;
			array[r1] = data;
		}
	}
}

void dequeue()
{
	if(f1==-1 || r1==-1)
	{
		if(f2==-1 || r2==-1)
		{
			printf("Stack is empty!!\n");
		}
		else
		{
			f1 = r1 = 0;
			while(f2!=r2)
			{
				array[r1++] = array[f2];
				f2++;
			}
			printf("%d has been deleted.\n",array[f2]);
			free(array[f2++]);
		}
	}
	else
	{
		f2=r2=0;
		while(f1!=r1)
		{
			array[r2++] = array[f1];
			f1++;
		}
		printf("%d has been deleted.\n",array[f1]);
		free(array[f1++]);
	}
}

void display()
{
	int i = 0;
	int j = 0;
	if(f1==-1 || r1==-1)
	{
		if(f2==-1 || r2==-1)
		{
			printf("Stack is empty!!\n");
		}
		else
		{
			while(i<r2+1)
			{
				printf("%d\n",array[i]);
				i++;
			}
		}
	}
	else
	{
		while(j<r1+1)
		{
			printf("%d\n",array[j]);
			j++;
		}
	}
}
