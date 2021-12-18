#include<stdio.h>
#include<string.h>
#define SIZE 5
#define MSIZE 100
struct Queue{
char CQueue[SIZE][MSIZE];
int front,rear;
};
char ins[MSIZE];
struct Queue q;
void Enqueue(char a[]);
void Dequeue();
void display();
void getstring();
int main()
{
	q.front =-1;
	q.rear=-1;
	char ch[10]="6";
	while(ch[0]!='4')
	{
		printf("\n\nWhat would you like to do\n1.Send Message(Enqueue)\n2.Recieve Message(Dequeue)\n3.Display Message\n4.Quit\n");
		scanf("%s",ch);
		switch(ch[0]){
			case '1':printf("Enter Message: ");
			getstring();
			Enqueue(ins);
			break;
			case '2':Dequeue();	
			break;		
			case '3':display();
			break;
			case '4': break;
			default: printf("Wrong Input TRY!! Again.");
			break;
		}
	}
	printf("\nQuit Successfully!!\n");
}
void Enqueue(char a[])
{
	if(q.front==(q.rear+1)%SIZE)
		printf("\nQueue is Full!!!Insertion Not Possible\n");
	else {
		if(q.front==-1)
			q.front=0;
			q.rear=(q.rear+1)%SIZE;
			strcpy(q.CQueue[q.rear],a);
			printf("\nMessage is in the Queue");
	}
}
void Dequeue(){
	if(q.front==-1)
		printf("\nQueue is EMPTY!!!Deletion Not Possible\n");
	else{
		printf("The Message Recieved is %s",q.CQueue[q.front]);
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		q.front=(q.front+1)%SIZE;
	}
}
void display(){
	if(q.front==-1)
printf("\nQueue is Empty!!!");
	else{
		printf("\nThe Messages in the Queue are\n");
		int i;
		/*if(q.front<=q.rear)
		{
			for (i=q.front;i<=q.rear;i++)
				printf("\n%s",q.CQueue[i]);
		}
		else{
			for (i=q.front;i<SIZE;i++)
				printf("\n%s",q.CQueue[i]);
			for (i=0;i<=q.rear;i++)
				printf("\n%s",q.CQueue[i]);
		}*/
		for(i=q.front;i!=(q.rear)%SIZE;i=(i+1)%SIZE)
		printf("\n%s",q.CQueue[i]);
		printf("\n%s",q.CQueue[i]);
	}
		
}
void getstring(){
	char garb;
scanf("%c",&garb);
strcpy(ins,"");
int i=0;
char ch;
while(scanf("%c",&ch))
{ 
	if(ch=='\n')
	break;
	else
	{
		ins[i]=ch;
		i++;
	}
}
ins[i]='\0';
}
