#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void Print(struct node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert(struct node** head, int dat, int pos){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = dat;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
        return;
    }
    if(pos <= 1){
        temp->next = *head;
        *head = temp;
        return;
    }
    struct node* temp1 = *head;
    for(int i = 0; i < pos-1 && temp->next != NULL; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    return;
}

void delete(struct node** head, int n){
    struct node* temp = *head;
    if(*head == NULL || n <= 0){
        return;
    }
    if(n == 1){
        *head = temp->next;
        free(temp);
        return;
    }
    for(int i = 0; i < n-1 && (temp->next)->next != NULL; i++){
        temp = temp->next;
    }
    struct node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    return;
}

struct node* reverse(struct node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    struct node *newhead = reverse(head->next);
    struct node* q = head->next;
    q->next = head;
    head->next = NULL;
    return newhead; // to pass to the prev recursion call
}


int main(void){
    struct node* head = NULL;
    insert(&head,5,1);
    insert(&head,8,1);
    delete(&head,1);
    insert(&head,7,2);
    insert(&head,3,3);
    Print(head);
    head = reverse(head);
    Print(head);
}