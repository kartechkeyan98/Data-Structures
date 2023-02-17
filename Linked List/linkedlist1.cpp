#include<iostream>
using namespace std;

struct node
{
    int data; // 4B
    node* next; // 8B
};

void print_list(node* a){
    node* temp = a; // never modify the head node, otherwise ur screwed bigtime.
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int main(void){
    // create a new list
    node* a;
    a = NULL;

    node* temp = new node();
    temp->data = 2;
    temp->next = NULL;

    a = temp;


    // C way of doing things
    // node* temp = (node*)malloc(sizeof(node));
    // (*temp).data = 2;
    // (*temp).next = NULL;


    // inserting a new node at the end.
    temp = new node();
    temp->data = 4;
    temp->next = NULL;

    node* temp1 = a;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;

    temp = new node();
    temp->data = 5;
    temp->next = NULL;

    temp1 = a;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    
    print_list(a);
}
