 

#include <stdio.h> 

#include <stdlib.h> 

 

struct node 

{ 

struct node *next, *prev; 

int data; 

}; 

struct node *head; 

void display() 

{ 

struct node *temp = head; 

if (temp == NULL) 

{ 

printf("List is empty.\n"); 

return; 

} 

while (temp != NULL) 

{ 

printf("%d ", temp->data); 

temp = temp->next; 

} 

printf("\n"); 

} 

void push() 

{ 

struct node *new_node = (struct node *)malloc(sizeof(struct node)); 

int data; 

if(new_node==NULL) 

printf("Overflow\n"); 

else 

{ 

printf("Enter the data: "); 

scanf("%d", &data); 

new_node->data = data; 

if (head == NULL) 

{ 

new_node->next = NULL; 

new_node->prev = NULL; 

head = new_node; 

} 

else 

{ 

head->prev = new_node; 

new_node->next = head; 

new_node->prev = NULL; 

head = new_node; 

} 

} 

} 

 

void delete_specified() 

{ 

int loc=1,val; 

printf("Enter the value to delete: "); 

scanf("%d", &val); 

struct node *temp = head; 

if (temp == NULL) 

{ 

printf("List is empty. Nothing to delete.\n"); 

return; 

} 

while(temp->data!=val) 

{ 

loc++; 

temp=temp->next; 

} 

temp=head; 

if (loc == 1) 

{ 

head = temp->next; 

if (head != NULL) 

head->prev = NULL; 

free(temp); 

printf("Node deleted from the beginning.\n"); 

return; 

} 

for (int i = 1; i < loc; i++) 

{ 

temp = temp->next; 

if (temp == NULL) 

{ 

printf("Specified position does not exist.\n"); 

return; 

} 

} 

if (temp->next == NULL) 

{ 

temp->prev->next = NULL; 

free(temp); 

printf("Node deleted from the end.\n"); 

return; 

} 

temp->prev->next = temp->next; 

temp->next->prev = temp->prev; 

free(temp); 

printf("Node deleted from location %d.\n", loc); 

printf("After Deletion: "); 

display(); 

} 

int main() 

{ 

int ch; 

while (1) 

{ 

printf("Enter your choice:\n1.Insert a new node\n2.Delete a node\n3.Display the list\n4.Exit\n"); 

scanf("%d", &ch); 

switch (ch) 

{ 

case 1:{ 

printf("Enter no. of elements: "); 

int n, i; 

scanf("%d",&n); 

for(i=0; i<n; i++) 

push(); 

printf("After insertion: "); 

display(); 

}break; 

case 2:{ 

printf("Enter no. of elements to delete: "); 

int n,i; 

scanf("%d",&n); 

for(i=0; i<n; i++) 

delete_specified(); 

}break; 

case 3:display(); break; 

case 4:exit(0); 

} 

} 

return 0; 

} 