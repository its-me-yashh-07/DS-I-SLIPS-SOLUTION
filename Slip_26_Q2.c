/*Slip_26_Q2. There are lists where insertion should ensure the ordering of data elements.
Since the elements are in ascending order the search can terminate once equal
or greater element is found. Implement a singly linked list of ordered integers
(ascending/descending) with insert, search, and display operations. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAscending(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertDescending(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data <= value) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL && current->next->data > value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

struct Node* search(int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        if (current->data > value) {
            return NULL;
        }
        current = current->next;
    }
    return NULL;
}

void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, order;

    printf("Choose order for linked list:\n1. Ascending\n2. Descending\n");
    scanf("%d", &order);

    while (1) {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (order == 1) {
                    insertAscending(value);
                } else {
                    insertDescending(value);
                }
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* result = search(value);
                if (result) {
                    printf("Value %d found in the list.\n", result->data);
                } else {
                    printf("Value %d not found in the list.\n", value);
                }
                break;
            case 3:
                printf("Linked List: ");
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


