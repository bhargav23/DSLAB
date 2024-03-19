#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node* circularList(int data) {
	struct node *temp = (struct node *)malloc(sizeof(struct node *));
	temp->data=data;
	temp->next=temp;
	return temp;
}
void insert_at_beginnig(struct node *tail,int data) {
	struct node *temp = (struct node *)malloc(sizeof(struct node *));
	temp->data=data;
	temp->next=tail->next;
	tail->next=temp;
}
void display(struct node *tail) {
	if(tail==NULL)
	{
		printf("\nList is empty\n");
		return;	
	}	
	struct node *ptr = tail->next;
	do{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=tail->next);
	printf("\n");
	return;
}
void insert_at_end(struct node **tail,int data) {
	struct node *temp = (struct node *)malloc(sizeof(struct node *));
	temp->data=data;
	temp->next=(*tail)->next;
	(*tail)->next=temp;
	*tail=temp; 
}
void insert_at_position(struct node **tail,int data,int pos){
	if(pos==1){
		insert_at_beginnig(*tail,data);
		return;
	} 
	struct node *ptr=(*tail)->next;
	--pos;
	while(pos>1){
		ptr=ptr->next;
		pos--;
	}
	if(ptr==*tail) {
		insert_at_end(tail,data);
		return;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data=data;
	temp->next=NULL;
	temp->next=ptr->next;
	ptr->next=temp;
}
void delete_at_beginnig(struct node **tail) {
	if(*tail==NULL)
		return;
	struct node *ptr = (*tail)->next;
	if(ptr==*tail)
	{
		
		free(ptr);
		(*tail)=NULL;
		return;
	}
	(*tail)->next=ptr->next;
	ptr->next=NULL;
	free(ptr);
	
}

void delete_at_end(struct node **tail) {
	if(*tail==NULL)
	{
		printf("\nList is empty\n");
		return;	
	}	
	struct node *ptr = (*tail)->next;
	if(ptr==*tail) {
		free(ptr);
		(*tail)=NULL;
		return;
	}
	while(ptr->next!=*tail){
		ptr=ptr->next;
	}
	ptr->next=(*tail)->next;
	free(*tail);
	*tail=ptr;
	free(ptr->next);
	

} 
int main() {
	struct node *tail;
	tail = circularList(10);
	insert_at_beginnig(tail,20);
	insert_at_beginnig(tail,30);
	insert_at_beginnig(tail,40);
	insert_at_end(&tail,50);
	display(tail);
	insert_at_position(&tail,60,1);
	display(tail);
	insert_at_position(&tail,70,7);
	display(tail);
	insert_at_position(&tail,80,3);
	display(tail);
	delete_at_beginnig(&tail);
	display(tail);
	delete_at_end(&tail);
	display(tail);
	
}
