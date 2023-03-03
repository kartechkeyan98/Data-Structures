#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class stack{
    private:
        struct node{
            int data;
            node *next;
        };
        node *tp;

        //private utils
        node *getnewnode(int x){
            node *newnode=(node*)malloc(sizeof(node));
            newnode->data=x;
            newnode->next=NULL;
            return newnode;
        }
    public:
        stack(){
            tp=NULL;
        }

        //operations/methods
        void push(int x){
            node *newnode=getnewnode(x);
            newnode->next=tp;
            tp=newnode;
            return;
        }

        int pop(){
            if(tp==NULL){
                return -1;
            }
            node *t=tp;
            tp=t->next;
            int x=t->data;
            free(t);
            return x;
        }

        int top_show(){
            return tp->data;
        }

        bool isEmpty(){
            return (tp==NULL);
        }

        void print(){
            printf("top -> ");
            node *t=tp;
            while (t!=NULL)
            {
                printf("%d ", t->data);
                t=t->next;
            }
            printf("\n");
        }

        // utils required here
        void clear(){
            while(tp!=NULL){
                int y=pop();
            }
        }
};


int main(void){
    printf("\nWelcome to STACK (Linked List Version)\n");
    stack s;
    while(1){
        int fn;
        printf("\nEnter Function: ");
        scanf("%d",&fn);
        if(fn==1){
            printf("\nInstruction Manual\n");
            printf("1. Opens instruction manual\n");
            printf("2. Push Element\n");
            printf("3. Pop Element\n");
            printf("4. Show Top Element\n");
            printf("5. Show if stack is Empty\n");
            printf("6. Show Stack elements\n");
            printf("7. Clear Stack\n");
            printf("8. Exit\n");
        }
        else if(fn==2){
            int x;
            printf("\nEnter new element: ");
            scanf("%d",&x);
            s.push(x);
            printf("Successfully Pushed element!\n");
        }
        else if(fn==3){
            int p=s.pop();
            printf("\n%d popped!\n",p);
        }
        else if(fn==4){
            int t=s.top_show();
            printf("\n%d\n",t);
        }
        else if(fn==5){
            int e=s.isEmpty();
            if(e){
                printf("\nStack is Empty!\n");
            }
            else{
                printf("\nStack NOT Empty!\n");
            }
        }
        else if(fn==6){
            printf("\n");
            s.print();
        }
        else if(fn==7){
            s.clear();
            printf("Stack Cleared!\n");
        }
        else if(fn==8){
            printf("Thank You for using STACK!\n");
            s.clear();
            break;
        }
    }
}