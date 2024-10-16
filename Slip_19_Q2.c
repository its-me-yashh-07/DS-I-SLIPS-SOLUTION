/*Slip_19_Q2. There are lists where insertion should ensure the ordering of data elements.
Since the elements are in ascending order the search can terminate once equal
or greater element is found. Implement a doubly linked list of ordered integers
(ascending/descending) with insert, search and display operations. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int ascending;
} DoublyLinkedList;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(DoublyLinkedList *list, int data) {
    Node *newNode = createNode(data);
    
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node *current = list->head;
    while (current != NULL) {
        if (list->ascending) {
            if (data < current->data) {
                break;
            }
        } else {
            if (data > current->data) {
                break;
            }
        }
        current = current->next;
    }

    if (current == list->head) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    } else if (current == NULL) {
        Node *tail = list->head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
    } else {
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}

Node* search(DoublyLinkedList *list, int data) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        if (list->ascending && data < current->data) {
            break;
        } else if (!list->ascending && data > current->data) {
            break;
        }
        current = current->next;
    }
    return NULL;
}

void display(DoublyLinkedList *list) {
    Node *current = list->head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    DoublyLinkedList list;
    list.head = NULL;

    int orderChoice;
    printf("Enter 1 for ascending order or 0 for descending order: ");
    scanf("%d", &orderChoice);
    list.ascending = orderChoice;

    insert(&list, 20);
    insert(&list, 10);
    insert(&list, 30);
    insert(&list, 25);

    display(&list);

    int searchVal;
    printf("Enter value to search: ");
    scanf("%d", &searchVal);
    Node *foundNode = search(&list, searchVal);
    if (foundNode) {
        printf("Element %d found in the list.\n", searchVal);
    } else {
        printf("Element %d not found in the list.\n", searchVal);
    }

    return 0;
}
