#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void printlist(struct node* head){
    // passing head as arg is call by value.
    // hence you will get head as a local variable which has same value as what you pass in.
    // so no need to create temp variable, you already have that done.

    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//two ways to insert at begenning.

// 1.
// struct node* insertbegin(struct node* head, int x){
//     // here, if you pass in single * ptr, then at the step where you need to link actual head to temp, u'll be linking the copy of ptr
//     // so you need to return that so that in main, you'll be able to modify the actual head ptr, other wise you'll end up having same linked list.

//     struct node* temp = (struct node*)malloc(sizeof(struct node));
//     temp->data = x;
//     temp->next = head;

//     head = temp;
//     return head;
// }

// 2. better way
void insertbegin(struct node** headptr, int x){
    // this time, instead of a copy of head generateda, you get a variable which points to head. ptr to ptr... :)!
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = *headptr; // actual head.

    *headptr = temp;
}

int main(void){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    // head isn't global anymore.

    int n,x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        // head = insertbegin(head, x);
        insertbegin(&head, x);
        printlist(head);
    }
}
