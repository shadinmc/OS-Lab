
#include<stdio.h>
#define SIZE 5
char array[SIZE];
int top=-1;
int producer(char data)
{
	if(top==SIZE)
	{
		printf("Consumer is full\n");
		return 0;
	}
	else
	{
		top++;
		array[top]=data;
		printf("%d more Data's can be stored\n",(SIZE-top));
		printf("\n%d\n",top);
	}
}
int consumer()
{
	if(top==-1)
	{
		printf("Consumer is empty\n");
		return;
	}
	else
	{
		int dec=top;
		printf("The data in producer is:\n");
		while(dec!=-1)
		{	
			dec--;
			printf("%c ",array[dec]);
		}
		printf("Data at top deleted\n");
		top--;
		printf("\n");
	}
}

int print()
{
	int dec=top;
	while(dec!=-1)
	{
		printf("%c ",array[dec]);
		dec--;
 	}
 }	
int main()
{
	int flag=0;
	while(flag==0)
	{
		printf("\n1)produce Data\n2)Consume Data\n3)print\n4)Exit\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				char data;
				printf("Enter Data\n");
				scanf("%s",&data);
				producer(data);
				break;
			case 2:
				consumer();
				break;
			case 4:
				flag=1;
				break;
			case 3:
				print();
				break;
			default:
				printf("Enter valid choice\n");
				break;
		}
	}
}				
