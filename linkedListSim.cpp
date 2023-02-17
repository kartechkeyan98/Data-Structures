#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    node *next;
};

// basic utils:

//1. creating new node
node *getnewnode(int x){
    node *newnode=(node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
//2. inserting node at n-th position
void insert(node **hd,int x,int n){
    node *newnode=getnewnode(x);
    if(*hd==NULL||n<=1){
        newnode->next=*hd;
        *hd=newnode;
        return;
    }
    node *t=*hd;
    for(int i=0;i<n-2&&t->next!=NULL;i++){
        t=t->next;
    }
    newnode->next=t->next;
    t->next=newnode;
    return;
}
//3. delete node at n-th position
void erase(node **hd,int n){
    if(*hd==NULL){
        return;
    }
    if(n<=1){
        node *t=*hd;
        *hd=t->next;
        free(t);
        return;
    }
    node *t=*hd;
    for(int i=0;i<n-2&&t->next->next!=NULL;i++){
        t=t->next;
    }
    node *p=t->next;
    t->next=p->next;
    free(p);
    return;
}

// printing methods:-

//1. iterative fwd print
void Iprint(node *hd){
    while(hd!=NULL){
        printf("%d ",hd->data);
        hd=hd->next;
    }
    printf("\n");
}
//2. recursive fwd print
void Rprint(node *hd){
    if(hd==NULL){
        printf("\n");
        return;
    }
    printf("%d ",hd->data);
    Rprint(hd->next);
    return;
}
//3. recursive bwd print
void revPrint(node *hd){
    if(hd==NULL){
        return;
    }
    revPrint(hd->next);
    printf("%d ",hd->data);
    return;
}

// complex utils

//1. iteratively reverse list
void Irev(node **hd){
    if(*hd==NULL||(*hd)->next==NULL){
        return;
    }
    node *prv=NULL,*cur=*hd,*nxt;
    while(cur!=NULL){
        nxt=cur->next;
        cur->next=prv;
        prv=cur;
        cur=nxt;
    }
    *hd=prv;
    return;
}
//2. recursively reverse list
node *Rrev(node *hd){
    if(hd->next==NULL){
        return hd;
    }
    node *newhd=Rrev(hd->next);
    node *t=hd->next;
    t->next=hd;
    hd->next=NULL;
    return newhd;
}


int main(void){
    node *head=NULL;

    char name[100];
    printf("\nEnter Name: ");
    scanf("%[^\n]%*c",name);

    printf("\nWELCOME TO LINK'D LIST!\n");
    printf("Credits: %s! ;)\n",name);

    while(true){
        char opmode='i';
        int fn;
        printf("\nEnter Function: ");
        scanf("%d",&fn);
        if(fn==1){
            printf("\nInstruction Manual\n");
            printf("1. Open Instruction Manual\n");
            printf("2. Print List\n");
            printf("3. Insert node\n");
            printf("4. Delete node\n");
            printf("5. Reverse the list\n");
            printf("6. Manage Operation mode\n");
            printf("7. Exit\n");
        }
        else if(fn==2){
            char rev;

            printf("\nPrint Menu\n");
            printf("Print in reverse?[y/n] ");
            while(scanf(" %c",&rev)==1){
                if(rev=='y'||rev=='Y'){
                    printf("\n> ");
                    revPrint(head);
                    printf("\n");
                    break;
                }
                else if(rev=='n'||rev=='N'){
                    printf("\n> ");
                    if(opmode=='i'||opmode=='I'){
                        Iprint(head);
                    }
                    else{
                        Rprint(head);
                    }
                    break;
                }
                else{
                    printf("Print in reverse?[y/n] ");
                }
            }
        }
        else if(fn==3){
            int x,n;
            printf("\nInsertion Menu\n");
            printf("Enter new data: ");
            scanf("%d",&x);
            printf("Enter location of data (1-indexed): ");
            scanf("%d",&n);

            insert(&head,x,n);
            printf("\nInsertion Successful!\n");
        }
        else if(fn==4){
            int n;
            printf("\nDeletion Menu\n");
            printf("Enter node to be deleted (1-indexed): ");
            scanf("%d",&n);
            erase(&head,n);
            printf("\nDelete Successful\n");
        }
        else if(fn==5){
            if(opmode=='i'||opmode=='I'){
                Irev(&head);
            }
            else{
                head=Rrev(head);
            }
            printf("\nSuccessfully reversed!\n");
        }
        else if(fn==6){
            printf("Current mode of Operation of 2 and 5: ");
            if(opmode=='r'||opmode=='R'){
                printf("Recursive(r)\n");
            }
            else{
                printf("Iterative(i)\n");
            }

            char c;
            printf("Change the mode of operation?[y/n] ");
            while(scanf(" %c",&c)==1){
                if(c=='y'||c=='Y'){
                    printf("Operations 2 and 5 iterative or recursive?[i/r] ");
                    while(scanf(" %c",&opmode)==1){
                        if(opmode=='i'||opmode=='I'||opmode=='r'||opmode=='R'){
                            break;
                        }
                        else{
                            printf("Operations 2 and 5 iterative or recursive?[i/r] ");
                        }
                    }
                    break;
                }
                else if(c=='n'||c=='N'){
                    break;
                }
                else{
                    printf("Change the mode of operation?[y/n] ");
                }
            }
        }
        else if(fn==7){
            printf("Thank you for using LINK'D LIST :)\n");
            break;
        }
    }
}