#include<stdio.h> 

#include<stdlib.h> 

struct node { 

int data; 

struct node *next; 

}; 

void display(struct node *head) 

{ 

struct node *ptr = head; 

while (ptr != NULL) 

{ 

printf("%d\t", ptr->data); 

ptr = ptr->next; 

} 

printf("\n"); 

} 

void sort(struct node **head) 

{ 

if (*head == NULL) 

return; 

struct node *current, *next; 

int temp; 

current = *head; 

while (current->next != NULL) 

{ 

next = current->next; 

while (next != NULL) 

{ 

if (current->data > next->data) 

	{ 

temp = current->data; 

current->data = next->data; 

next->data = temp; 

} 

next = next->next; 

} 

current = current->next; 

} 

} 

void reverse(struct node **head) 

{ 

struct node *cur=*head, *prev=NULL, *next=NULL; 

while(cur!=NULL) 

{ 

next=cur->next; 

cur->next=prev; 

prev=cur; 

cur=next; 

} 

*head=prev; 

} 

struct node *concatenate(struct node **head1, struct node **head2) 

{ 

if (*head1 == NULL) 

{ 

*head1 = *head2; 

return *head1; 

} 

if (*head2 == NULL) 

return *head1; 

struct node *temp = *head1; 

while (temp->next != NULL) 

temp = temp->next; 

temp->next = *head2; 

return *head1; 

} 

void PUSH(struct node **head) 

{ 

struct node *node = (struct node*)malloc(sizeof(struct node)); 

if (node == NULL) 

{ 

printf("Overflow\n"); 

exit(1); 

} 

int n; 

printf("Enter value: "); 

scanf("%d", &n); 

node->data = n; 

node->next = *head; 

*head = node; 

} 

int main() 

{ 

struct node *head1 = NULL, *head2 = NULL; 

int ch; 

printf("Creating list 1\nEnter no. of elements: "); 

int n, i; 

scanf("%d", &n); 

for (i = 0; i < n; i++) 

PUSH(&head1); 

printf("List 1: "); 

display(head1); 

sort(&head1); 

printf("Sorted list: "); 

display(head1); 

reverse(&head1); 

printf("Reversed list: "); 

display(head1); 

printf("Creating list 2\nEnter no. of elements: "); 

int n1, i1; 

scanf("%d", &n1); 

for (i1 = 0; i1 < n1; i1++) 

PUSH(&head2); 

printf("List 2: "); 

display(head2); 

sort(&head2); 

printf("Sorted list: "); 

display(head2); 

reverse(&head2); 

printf("Reversed list: "); 

display(head2); 

printf("Concatenating the 2 lists \n"); 

struct node *h = concatenate(&head1, &head2); 

display(h); 

return 0; 

} 