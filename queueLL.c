#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void enqueue(int d,struct node **front,struct node **rear){
	struct node *temp=(struct node *)malloc(sizeof(struct node*));
	temp->data=d;
	temp->next=NULL;
	if(*rear!=NULL)
		(*rear)->next=temp;
	if(*front==NULL)
		*front=temp;
	*rear=temp;
	return;
}
void display(struct node *front){
	struct node *ptr=front;
	if(front==NULL){
		printf("\nQueue is empty");
		return;
	}
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	return;
}
int dequeue(struct node **front,struct node **rear){
	int d;
	struct node *ptr=*front;
	if(*front==NULL){
		printf("\nQueue is empty");
		exit(1);
	}
	if(*front!=*rear){
		*front=(*front)->next;
	} else {
		*front=NULL;
	}
	d=ptr->data;
	free(ptr);
	return d;
}


int main(){
	struct node *front,*rear;
	front=rear=NULL;
	enqueue(10,&front,&rear);
	enqueue(20,&front,&rear);
	enqueue(30,&front,&rear);
	display(front);
	printf("\nDeleted element = %d \n",dequeue(&front,&rear));
	printf("\nDeleted element = %d \n",dequeue(&front,&rear));
	printf("\nDeleted element = %d \n",dequeue(&front,&rear));
	display(front);
}
