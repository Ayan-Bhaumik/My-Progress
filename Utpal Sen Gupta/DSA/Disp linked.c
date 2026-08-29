#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
 int main(){
    struct node *head= malloc(sizeof(struct node));
    struct node *second= malloc(sizeof(struct node));
    struct node *third= malloc(sizeof(struct node));
    
    head->data=20;
    second->data=40;
    third->data=60;

    head->next=second;
    second->next=third;
    third->next=NULL;

    struct node*temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    free(head);
    free(second);
    free(third);
    
   return 0; 
}