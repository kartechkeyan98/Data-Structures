#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void printlist(struct node* head){
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    
}

void insert(struct node** headptr, int x, int pos){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(*headptr == NULL){
        *headptr = temp;
        return;
    }
    if(pos <= 1){
        // insert at begenning
        temp->next = *headptr;
        *headptr = temp;
        return;
    }
    
    struct node* temp1 = *headptr;
    for(int i = 1; i < pos-1 && temp1->next != NULL; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    return;
}

int main(void){
    struct node* head = NULL;
    insert(&head,5,7); // 5
    insert(&head,1,6); // 5 1
    insert(&head,2,1); // 2 5 1
    insert(&head,6,2); // 2 6 5 1
    printlist(head);
}