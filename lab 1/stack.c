#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int arr[5], top=-1;
void push(int value){
if(top==SIZE-1){
    printf("\nStack overflow");
}else{

    top+=1;
    arr[top]=value;
}
   }
void pop(){
    if(top==-1){
    printf("\nStack underflow");
}else{
    printf("\n%d has been deleted from the Stack",arr[top]);
    top=top-1;
   }
}
void display(){
    if(top==-1){
    printf("\nStack underflow ");
}else{
    for(int i=0;i<=top;i++){
    printf("%d\t",arr[i]);}

   }

}
int main(){
    int choice,value;
    while(1){
        printf("\n1.PUSH 2.POP 3.DISPLAY 4.EXIT \n");
        scanf("%d",&choice);
        switch(choice){
        case 1:{printf("Enter a value:");
            scanf("%d",&value);
                push(value);
                break;}
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        break;
        default:printf("Invalid input");
        }
    }
    return 0;
    }