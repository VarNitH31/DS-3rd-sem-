#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void display(struct Node *top) {
  if (top != NULL) {
    printf("Stack elements are:\t");
    while (top != NULL) {
      printf("%d\t", top->data);
      top = top->next;
    }
    printf("\n");
  } else {
    printf("Stack is empty\n");
  }
}

struct Node *push(struct Node *top, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Stack Overflow\n");
    return top;
  }

  newNode->data = data;
  newNode->next = top;
  top = newNode;

  return top;
}

struct Node *pop(struct Node *top, int *poppedData) {
  if (top == NULL) {
    printf("Stack Underflow\n");
    *poppedData = -1; // You can choose another value to indicate underflow
    return NULL;
  }

  struct Node *temp = top;
  *poppedData = temp->data;
  top = top->next;
  free(temp);

  return top;
}

int main() {
  int op, n, poppedElement;
  struct Node *top = NULL;
  printf("Enter 1. Push\n2. Pop\n3. -1 to stop\n");
  while (1) {
    printf("Enter operation:\n");
    scanf("%d", &op);

    if (op == -1) {
      printf("Execution stopped\n");
      break;
    }

    switch (op) {
    case 1:
      printf("Enter the element to push\n");
      scanf("%d", &n);
      top = push(top, n);
      break;
    case 2:
      top = pop(top, &poppedElement);
      if (poppedElement != -1) {
        printf("Popped Element: %d\n", poppedElement);
      }
    }
    display(top);
  }

  return 0;
}
