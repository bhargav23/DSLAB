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

struct node* insert_at_end(struct node *tail,int d){
	if(tail == NULL) {
		printf("List is empty");
		return;
	} 
	struct node *t;
	t = (struct node *)malloc(sizeof(struct node *));
	t->data=d;
	t->next=NULL;
	
	tail->next=t;
	return t;
}
int main(){
	struct node *head=NULL,*tail=NULL;
	head = (struct node *)malloc(sizeof(struct node *));
	
	head->data = 10;
	head->next = NULL;
	tail=head;
	
	display(tail);
	printf("\nNo of elements = %d ", count_of_nodes(tail));
	
	tail = insert_at_end(tail,40);
	tail = insert_at_end(tail,50);
	tail = insert_at_end(tail,60);
	tail = head; 
	display(head);
	printf("\nNo of elements = %d ", count_of_nodes(head));
	
	
	
}
