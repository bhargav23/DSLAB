struct node{
	int data;
	struct node *next;
};
int mani(){
	struct node *head,*tail;
	int ch,d;
	printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit");
	scanf("%d",&ch);
	while(1) {
		switch(ch){
			case 1: printf("Enter the elment");
					scanf("%d",&d);
					insert(5);
					break;
		}
	}
	
}
