#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements are:\t");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return -1; // You can choose another value to indicate underflow
    }

    struct Node* temp = *front;
    int dequeuedData = temp->data;

    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL; // If the last element is dequeued, update rear
    }

    free(temp);
    return dequeuedData;
}

int main() {
    int op, n, dequeuedElement;
    struct Node* front = NULL;
    struct Node* rear = NULL;
    printf("Enter 1. Enqueue\n2. Dequeue\n3. -1 to stop\n");
    while (1) {
        printf("Enter operation\n");
        scanf("%d", &op);

        if (op == -1) {
            printf("Execution stopped\n");
            break;
        }

        switch (op) {
            case 1:
                printf("Enter the element to enqueue\n");
                scanf("%d", &n);
                enqueue(&front, &rear, n);
                break;
            case 2:
                dequeuedElement = dequeue(&front, &rear);
                if (dequeuedElement != -1) {
                    printf("Dequeued Element: %d\n", dequeuedElement);
                }
                break;
        }
        display(front);
    }

    return 0;
}
