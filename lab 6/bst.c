#include<stdio.h> 

#include<stdlib.h> 

typedef struct BST 

{ 

int data; 

struct BST *left; 

struct BST *right; 

}node; 

node *create() 

{ 

node *t; 

printf("Enter data: "); 

t=(node*)malloc(sizeof(node)); 

scanf("%d",&t->data); 

t->left=t->right=NULL; 

return t; 

} 

void insert(node *root,node*t) 

{ 

if(t->data<root->data) 

{ 

if(root->left!=NULL) 

insert(root->left,t); 

else 

root->left=t; 

} 

if(t->data>root->data) 

{ 

if(root->right!=NULL) 

insert(root->right,t); 

else 

root->right=t; 

} 

} 

void preorder(node *root) 

{ 

if(root!=NULL) 

{ 

printf("%d ",root->data); 

preorder(root->left); 

preorder(root->right); 

} 

} 

void inorder(node *root) 

{ 

if(root!=NULL) 

{ 

inorder(root->left); 

printf("%d ",root->data); 

inorder(root->right); 

} 

} 

void postorder(node *root) 

{ 

if(root!=NULL) 

{ 

postorder(root->left); 

postorder(root->right); 

printf("%d ",root->data); 

} 

} 

int main() 

{ 

char ch; 

node *root=NULL,*t; 

do{ 

t=create(); 

if(root==NULL) 

root=t; 

else 

insert(root,t); 

printf("Do you want to enter more?(y/n) "); 

getchar(); 

scanf("%c",&ch); 

}while(ch=='y'||ch=='Y'); 

int c; 

while(1) 

{ 

printf("\nEnter your choice:\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit\n"); 

scanf("%d",&c); 

switch(c) 

{ 

case 1:{preorder(root);}break; 

case 2:{inorder(root);}break; 

case 3:{postorder(root);}break; 

case 4:exit(0); 

} 

} 

return 0; 

} 