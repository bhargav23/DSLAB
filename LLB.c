#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Current size of Linked List
int size = 0;

// Method to insert at the beginning of the list
void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    size++;
}

// Method to insert at a given position
void insertPosition(int pos, int data, struct Node** head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    // Invalid positions
    if (pos < 1 || pos > size + 1)
        printf("Invalid position\n");
    // Inserting at the first node
    else if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        size++;
    } else {
        struct Node* temp = *head;
        // Traverse till the current (pos-1)th node
        while (--pos > 1) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        size++;
    }
}

// Method to display the linked list
void display(struct Node* node) {
    printf("Linked List: ");
    // Linked list ends when the node is NULL
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 70);
    insert(&head, 60);
    insert(&head, 40);
    insert(&head, 30);
    insert(&head, 10);

    display(head);

    // Inserts data: 20 at 2nd position
    insertPosition(1, 20, &head);
    // Inserts data: 50 at 5th position
    //insertPosition(5, 50, &head);
    // Inserts data: 80 at 8th position
    //insertPosition(8, 80, &head);

    display(head);

    return 0;
}

