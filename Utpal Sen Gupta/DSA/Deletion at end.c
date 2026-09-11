#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *temp, *prev;

    head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;

    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 20;

    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}