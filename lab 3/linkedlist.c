#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*head=NULL;

void insert_first(struct node *p,int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node *));
  
    t->next=head;
    t->data=x;
    head=t;
}
void insert_last(struct node *p,int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node *));
    t->data=x;
  while(p->next!=NULL){
    p=p->next;
  } 
  p->next=t;
  t->next=NULL;
}

void insert_pos(struct node *p,int x,int pos){
    struct node *t,*q;
    t=(struct node *)malloc(sizeof(struct node *));
    t->data=x;
    for (int i = 1; i < pos; i++)
    {
        q=p;
        p=p->next;
    }
  t->next=p;
  q->next=t;
}

void delete_first(struct node *p){
    if(head->next==NULL){
        free(head);
        return;
    }
    head=head->next;
    free(p);
}


void delete_last(struct node *p){

    struct node * q;
    while (p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    q->next=NULL;
    free(p);
}
void delete_pos(struct node *p,int pos){

    struct node * q;
    for (int i = 1; i < pos; i++)
     {
        q=p;
        p=p->next;
    }
    
   
    q->next=p->next;
    free(p);
}

void display(struct node *p){
    while(p){
        int x= p->data;
        int y=p->next;
        printf("%d(%d)->",x,y);
        p=p->next;
    }
    printf("NULL \n");
}


int main(){

    insert_first(head,5);
    insert_first(head,7);
    insert_last(head,9);
    insert_pos(head,2,2);
    display(head);
    delete_first(head);
    display(head);
    delete_last(head);
    display(head);
    insert_last(head,9);
    display(head);
    delete_pos(head,2);
    display(head);


return 0;
}