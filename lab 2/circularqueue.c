#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int front=-1, rear=-1, q[SIZE];
void insert(int value){
    if(front==-1 && rear ==-1){
        front=0;
        rear=0;
        q[rear]=value;
    }else if((rear+1)%SIZE==front){
        printf("Queue Overflow");}
    else{
        rear=(rear+1)%SIZE;
        q[rear]=value;
    }
    }
void delete(){
if(front==-1){
    printf("Queue Underflow");

}else{
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
    printf("%d deleted",q[front]);
    front=(front+1)%SIZE;}
    }
    }
void display(){
if(front==-1){
    printf("Queue Underflow");
}else{
    int i=front;
while((i != (rear + 1))){
    printf("%d \t",q[i]);
    i=(i+1)%SIZE;
}

}}

int main(){
    int choice,value;
    while(1){
        printf("\n1.insert 2.delete 3.DISPLAY 4.EXIT:\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:{printf("Enter a value:");
            scanf("%d",&value);
                insert(value);
                break;}
        case 2:delete();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        break;
        default:printf("Invalid Input");
        }
    }
    return 0;
    }