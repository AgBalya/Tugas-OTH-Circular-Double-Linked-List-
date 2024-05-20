#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void insertNode(Node** head, Node** tail, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Address: %p, Data: %d\n", (void*) current, current->data);
        current = current->next;
    }
    printf("\n");
}

void sortList(Node** head) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
    Node *temp = NULL;

    if (*head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                if (ptr1 == *head) {
                    *head = ptr1->next;
                }
                if (ptr1->next == lptr) {
                    lptr = ptr1;
                }

                temp = ptr1->next->next;
                ptr1->next->prev = ptr1->prev;
                if (ptr1->prev != NULL) {
                    ptr1->prev->next = ptr1->next;
                }
                ptr1->prev = ptr1->next;
                ptr1->next = temp;
                if (temp != NULL) {
                    temp->prev = ptr1;
                }
                ptr1->prev->next = ptr1;
                
                swapped = 1;
            }
            else {
                ptr1 = ptr1->next;
            }
        }
    } while (swapped);
}

int main() {
    int N;
    Node* head = NULL;
    Node* tail = NULL;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&head, &tail, data);
    }

    printf("sebelum diurutkan:\n");
    printList(head);

    sortList(&head);

    printf("sesudah diurutkan:\n");
    printList(head);

    return 0;
}
