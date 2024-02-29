#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

void display(struct node *);
void display(struct node *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
}
int main(){
	struct node *n1=NULL,*n2=NULL,*n3=NULL,*head;
	head = (struct node*)malloc(sizeof(struct node *));
	n1= (struct node *)malloc(sizeof(struct node *));
	n2= (struct node *)malloc(sizeof(struct node *));
	n3= (struct node *)malloc(sizeof(struct node *));
	
	n1->data = 10;
	n2->data = 20;
	n3->data = 30;
	
	head=n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	printf("%d ",head->data);
	printf("%d ",n1->next->data);
	printf("%d \n",n2->next->data);
	
	struct node *current = head;
	while(current!=NULL) {
		printf("%d ",current->data);
		current=current->next;
	}
	struct node *n=NULL;
	n= (struct node *)malloc(sizeof(struct node *));
	n->data = 40;
	n->next = head;
	n = head;
	printf("\n");
	display(head);
	
}


