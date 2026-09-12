#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *newnode, *temp;

    head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;

    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 20;

    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 25;

    temp = head;

    while (temp->data != 20)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}