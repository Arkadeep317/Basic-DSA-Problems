#include<stdio.h>
#define MAX 5
int queue[MAX];
int front =-1,rear=-1;
void CENQUE(int element){
	if((front==0&&rear==MAX-1)||(rear==(front-1+MAX)%MAX)){
		printf("Queue overflow ! \n");
		return;
	}
	if(front==-1){
		front=rear=0;
	}else if (rear==MAX-1 && front!=0){
		rear=0;
		
	}else{
		rear=(rear+1)%MAX;
	}
	queue[rear]=element;
	printf("inserted %d\n",element);
	
}
int CDELQUE(){
	int data,a;
		 data=queue[front];
	if(front==rear){
		front=rear=-1;
		
	}
	else{
		front=(front+1)%MAX;
	}
	return data;
	
}

void CDISPLAY(){
	if(front==-1){
		printf("QUEUE IS EMPTY.\n");
		return;
	}
	printf("CIRCULAR QUEUE: ");
	int i=front;
	while(1){
		printf(" %d",queue[i]);
		if(i==rear)
		break;
		i=(i+1)%MAX ;
	}
	printf("\n");
}
int main (){
	int choice,element,data;
	while(1){
		printf("\n...Circular Queue Menu...\n");
		printf("1. Insert (CENQUE)\n");
		printf("2. Delete (CDELQUE)\n");
		printf("3. Display (CDISPLAY)\n");
		printf("4. Exit \n");
		printf("Enter your choice : ");
		scanf(" %d",&choice);
		switch(choice){
			case 1:
				printf("Enter element to insert: ");
				scanf(" %d",& element);
				CENQUE(element);
				break;
			case 2:
				data=CDELQUE();
				if(front==-1){
				printf("QUEUE UNDERFLOW!\n");}
				else{
				printf("DELETED %d \n",data);
				}
				
				break;
			case 3:
				CDISPLAY();
				break;
			case 4:
				printf("Exiting...\n");
				return 0;
			default:
				printf("INVALID CHOICE! TRY AGAIN :) \n");
		}
	}
	return 0;
}
