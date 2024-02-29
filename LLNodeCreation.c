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
	
	struct node *current1=NULL;
	current1 = (struct node *)malloc(sizeof(struct node *));
	
	current1->data = 30;
	current1->next = NULL;
	
	//current->next = current1;
	head->next->next = current1;
	struct node *temp = head;
	while(temp!=NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	display(head);
	printf("\nNo of elements = %d ", count_of_nodes(head));
	
}
