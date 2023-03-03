#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define MAX_SIZE 101

class stack{
    private:
        int st[MAX_SIZE];
        int top;
    public:
        stack(){
            top=-1;
        }

        // push
        void push(int x){
            if(top==MAX_SIZE-1){
                printf("Stack Overflow!\n");
                return;
            }
            top++;
            st[top]=x;
            return;
        }

        //pop
        int pop(){
            int y=top;
            if(y==-1){
                return -1;
            }
            top--;
            return st[y];
        }

        // top
        int top_show(){
            int y=top;
            if(y==-1){
                return -1;
            }
            int t=st[top];
            return t;
        }

        // isEmpty
        int isEmpty(){
            if(top==-1){
                return 1;
            }
            return 0;
        }

        //clear
        void clear(){
            top=-1;
            return;
        }

        //print stack
        void print(){
            int n=top;
            for(int i=0;i<=n;i++){
                printf("%d ",st[i]);
            }
            printf("<- top\n");
            return;
        }
};

int main(void){
    printf("\nWelcome to STACK (Array Version)\n");
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