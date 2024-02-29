#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void display(struct node *head){
	if(head == NULL) {
		printf("List is empty");
		return;
	} 
	printf("\nElements in the List are: \n");
	struct node *ptr = head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	return;	
}
int count_of_nodes(struct node *head){
	int count=0;
	if(head == NULL) {
		return 0;
	} 
	struct node *ptr = head;
	while(ptr!=NULL){
		count++;
		ptr = ptr->next;
	}
	return count;	
}

void insert_at_end(struct node *head,int d){
	if(head == NULL) {
		printf("List is empty");
		return;
	} 
	struct node *t;
	t = (struct node *)malloc(sizeof(struct node *));
	t->data=d;
	t->next=NULL;
	
	struct node *ptr = head;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next=t;
}
int main(){
	struct node *head=NULL;
	head = (struct node *)malloc(sizeof(struct node *));
	
	head->data = 10;
	head->next = NULL;
	
	struct node *current=NULL;
	current = (struct node *)malloc(sizeof(struct node *));
	
	current->data = 20;
	current->next = NULL;
	
	head->next = current;
	
	current = (struct node *)malloc(sizeof(struct node *));
	
	current->data = 30;
	current->next = NULL;
	
	//current->next = current1;
	head->next->next = current;
	
	struct node *temp = head;
	while(temp!=NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	display(head);
	printf("\nNo of elements = %d ", count_of_nodes(head));
	
	insert_at_end(head,40);
	insert_at_end(head,50);
	insert_at_end(head,60);
	display(head);
	printf("\nNo of elements = %d ", count_of_nodes(head));
	
}
