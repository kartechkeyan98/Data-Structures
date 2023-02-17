#include<stdio.h>
#include<stdlib.h>

struct node
{
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
    // delete node at nth position.
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

int main(void){
    struct node* head = NULL;
    insert(&head,5,1);
    insert(&head,6,2);
    insert(&head,8,3);
    insert(&head,7,2);
    insert(&head,4,4);
    printlist(head);
    delete(&head,1);
    printlist(head);
}
