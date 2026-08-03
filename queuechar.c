#include<stdio.h>
#include<stdlib.h>
#define MAX 10
	char queue[MAX];
	int rear=-1, front=-1,i;
	char element;
	void enque(char element){
			if(rear==MAX-1){
				
				printf("OVERFLOWED!!",element);
				return;
			   }
			  if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = element;
    printf("enque( %c)\n", element);
		}
	void delque(){
			if(front==-1 || front>rear){
				printf("UNDERFLOWED!");
				return;
			}
			char data = queue[front];
			front++;
			if(front>rear){
				front=rear= -1;
			}
			printf("delque() -> %c",data);
			return ;
	}
	void display(){
			if(front==-1 || front>rear){
				printf("queue is empty!");
			}
			else{
				printf("queue is:");
				for(i=front;i<=rear;i++){
					printf("%c\n",queue[i]);
				}
				return;
			}
	}
	
	int main(){
       
		
		int choice;
			while(1){
					printf("\nmenu...\n");
					printf("1 to insert\n");
					printf("2 to delete\n");
					printf("3 to display\n");
					printf("4 to exit\n");
					scanf("%d",&choice);
					
				switch(choice){
					case 1:
							printf("enter element to insert:");
							scanf(" %c",&element);
							enque(element);
							break;
					case 2:
						
							printf("%c element deleted!",element);
							delque();
							break;
					case 3:
							display();
							break;
					case 4:
							printf("exit");
							exit(0);		
				}
			}
			return 0;
	}