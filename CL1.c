#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void display(struct node *tail){
	if(tail==NULL){
		printf("\nList is empty");
		return;
	}
	printf("\n");
	struct node *ptr=tail->next;
	do{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=tail->next);
}
void create_node(struct node **tail,int d){
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data=d;
	temp->next=temp;
	*tail=temp;
}
void insert_at_beginning(struct node **tail,int d){
	if(*tail==NULL){
		printf("\nList is empty");
		return;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data=d;
	temp->next=(*tail)->next;
	(*tail)->next=temp;
}
void insert_at_end(struct node **tail,int d){
	if(*tail==NULL){
		printf("\nList is empty");
		return;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data=d;
	temp->next=(*tail)->next;
	(*tail)->next=temp;
	(*tail)=temp;
}
void insert_at_position(struct node **tail,int d,int pos){
	if(*tail==NULL){
		printf("\nList is empty");
		return;
	}
	if(pos==1){
		insert_at_beginning(tail,d);
		return;
	}
	pos--;
	struct node *ptr=(*tail)->next;
	while(pos>1){
		ptr=ptr->next;
		pos--;
		if(ptr==(*tail)->next)
		{
			printf("Invalid Position\n");
			return;	
		}
	}
	if(ptr==(*tail)){
		insert_at_end(tail,d);
		return;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data=d;
	temp->next=ptr->next;
	ptr->next=temp;
}
void delete_at_beginning(struct node **tail){
	if(*tail==NULL){
		printf("\nList is empty");
		return;
	}
	struct node *ptr=(*tail)->next;
	if(ptr->next==ptr){
		free(ptr);
		*tail=NULL;
		return;
	}
	(*tail)->next=ptr->next;
	free(ptr);
}

void delete_at_end(struct node **tail){
	if(*tail==NULL){
		printf("\nList is empty");
		return;
	}
	struct node *ptr=*tail;
	if(ptr->next==ptr){
		free(ptr);
		*tail=NULL;
		return;
	}
	
	while(ptr->next!=*tail) {
		ptr=ptr->next;
	}
	struct node *temp=*tail;
	ptr->next=(*tail)->next;
	*tail=ptr;
	free(temp);
}

void delete_at_position(struct node **tail,int pos){
	if(*tail==NULL){
		printf("\nList is empty");
		return;
	}
	struct node *ptr=(*tail)->next;
	if(ptr->next==ptr){
		free(ptr);
		*tail=NULL;
		return;
	}
	pos--;
	while(pos>1){
		ptr=ptr->next;
		pos--;
		if(ptr->next==(*tail)->next){
			printf("\nInvalid Position");
			return;
		}
	}
	struct node *ptr1=ptr->next;
	ptr->next=ptr1->next;
	if(ptr1==*tail){
		(*tail)=ptr;
		free(ptr1);
		return;
	}
}


int main(){
	struct node *tail=NULL;
	create_node(&tail,10);
	display(tail);


	
	insert_at_beginning(&tail,20);
	display(tail);
	insert_at_end(&tail,30);
	display(tail);
	insert_at_position(&tail,40,1);
	display(tail);
	insert_at_position(&tail,50,5);
	display(tail);
	insert_at_position(&tail,60,2);
	display(tail);
	delete_at_beginning(&tail);
	display(tail);

	delete_at_end(&tail);
	display(tail);
	
	delete_at_position(&tail,5);
	display(tail);
	
	
}
