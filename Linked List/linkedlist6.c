#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void Print(struct node* p){
    if(p == NULL){
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    Print(p->next);
}
void revPrint(struct node* p){
    if(p == NULL){
        return;
    }
    revPrint(p->next);
    printf("%d ", p->data);
}

void insert(struct node** headptr,int dat, int pos){
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

void delete(struct node** head, int n){
    struct node* temp = *head;
    if(n <= 1){
        *head = temp->next;
        free(temp);
        return;
    }
    for(int i = 1; i < n-1 && (temp->next)->next != NULL; i++){
        temp = temp->next;
    }
    struct node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    return;
}

int main(void){
    struct node* head = NULL;
    insert(&head,6,1);
    insert(&head,2,1);
    insert(&head,8,3);
    insert(&head,5,1);
    Print(head);
    revPrint(head);
}