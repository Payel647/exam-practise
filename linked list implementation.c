//implementation of linked list
#include<stdio.h>
#include<stdlib.h>//need to include it for malloc function

int main(){
    struct node{
    int data;
    struct node* next;
};
    struct node* head,*newnode,*temp;
    head=0;
    int choice;
    while(choice){
    newnode=(struct node*)malloc(sizeof(struct node));//malloc return a void pointer why we need to type casting
    printf("enter data : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    printf("do you want to continue(for yes type 1 or no type 0): ");
    scanf("%d",&choice);
    }
    temp = head;
    while(temp!=0){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    return 0;
}