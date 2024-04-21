#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int d){
	if(isFull()){
		printf("Queue overflow\n");
		exit(0);
	}
	if(front==-1) front = 0;
	rear++;
	queue[rear]=d;
}
void display(){
	int i;
	if(isEmpty()){
		printf("Queue underflow\n");
		exit(0);
	}
	printf("\n");
	for(i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
}
int dequeue(){
	int t;
	if(isEmpty()){
		printf("\nQueue underflow\n");
		exit(0);
	}
	t=queue[front];
	front++;
	return t;
}
int isFull(){
	if(rear==MAX-1)
		return 1;
	else 
		return 0;
}
int isEmpty(){
	if(front>rear||front==-1)
		return 1;
	else 
		return 0;
}
int main(){
	enqueue(10);
	enqueue(20);
	display();
	printf("\nDeleted element = %d \n",dequeue());
	printf("\nDeleted element = %d \n",dequeue());
	printf("\nDeleted element = %d \n",dequeue());
	display();
}
