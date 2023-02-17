#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(struct node** headptr, int dat, int pos){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = dat;
    temp->next = NULL;
    if(*headptr == NULL){
        *headptr = temp;
        return;
    }
    if(pos <= 1){
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

void delete(struct node** headptr, int n){
    struct node* temp1 = *headptr;
    if(*headptr == NULL || n < 1){
        return;
    }
    if(n == 1){
        *headptr = temp1->next;
        free(temp1);
        return;
    }
    for(int i = 1; i < n-1; i++){
        temp1 = temp1->next;
    }
    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void reverse(struct node** head){
    struct node *current,*prev,*next;
    current = *head;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void printlist(struct node* head){
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main(void){
    struct node* head = NULL;
    insert(&head,8,1);
    // insert(&head,6,2);
    // insert(&head,2,3);
    // insert(&head,7,2);
    // insert(&head,4,1);
    // insert(&head,12,2);
    printlist(head);
    reverse(&head);
    printlist(head);
}