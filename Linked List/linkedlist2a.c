#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;
void insertbegin(int x){
    // O(1) time
    
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL; 
    // syntax for (*temp).next ... so ur working with what's inside temp and not tampering with the ptr.

    // if(head != NULL){
    //     temp->next = head;
    // }
    temp->next=head;
    head = temp;
}
void print_list(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(void){
    head = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        insertbegin(x);
        print_list();
    }
    return 0;
}