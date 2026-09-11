#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
int main(){
struct node *head, *temp;

head=(struct node *)malloc(sizeof(struct node));
head->data=10;

head->next=(struct node *)malloc(sizeof(struct node));
head->next->data=20;
head->next->next=NULL;
printf("Before Deletion:%d->%d\n",head->data, head->next->data);

temp=head;
head=head->next;
free(temp);
printf("After Deletion:%d\n",head->data);
return 0;
}