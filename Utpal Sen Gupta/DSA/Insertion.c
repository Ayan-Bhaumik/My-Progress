#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
int main(){
    struct node *head=NULL,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert:");
    scanf("%d",newnode->data);
    newnode->next=head;
    head=newnode;
    return 0;
}