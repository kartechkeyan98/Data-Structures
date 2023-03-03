#include<iostream>
#include<stdlib.h>
using namespace std;

class linkedList{
    private:
        struct node{
            int data;
            node *next;
        };
        node *head;

        node *getnewnode(int x){
            node *newnode=(node*)malloc(sizeof(struct node));
            newnode->data=x;
            newnode->next=NULL;
            return newnode;
        }
    public:
        // constructor
        linkedList(){
            head=NULL;
        }

        //1. insertion
        void insert(int x,int n){
            node *newnode=getnewnode(x);
            if(head==NULL||n<=1){
                newnode->next=head;
                head=newnode;
                return;
            }
            node *t=head;
            for(int i=0;i<n-2&&t->next!=NULL;i++){
                t=t->next;
            }
            newnode->next=t->next;
            t->next=newnode;
            return;
        }
        //2. delete
        void erase(int n){
            if(head==NULL){
                return;
            }
            if(n<=1){
                node *t=head;
                head=t->next;
                free(t);
                return;
            }
            node *t=head;
            for(int i=0;i<n-2&&t->next->next!=NULL;i++){
                t=t->next;
            }
            node *p=t->next;
            t->next=p->next;
            free(p);
            return;
        }

        //3. iterative fwd print
        void iprint(){
            cout<<"> ";
            node *t=head;
            while(t!=NULL){
                cout<<t->data<<" ";
                t=t->next;
            }
            cout<<endl;
        }
        //4. recursive fwd print
        void rprint_aux(node *hd){
            if(hd==NULL){
                cout<<endl;
                return;
            }
            cout<<hd->data<<" ";
            rprint_aux(hd->next);
            return;
        }
        void rprint(){
            cout<<"> ";
            rprint_aux(head);
        }
        //5. recursive reverse print
        void revprint_aux(node *hd){
            if(hd==NULL){
                return;
            }
            revprint_aux(hd->next);
            cout<<hd->data<<" ";
        }
        void revprint(){
            cout<<"> ";
            revprint_aux(head);
            cout<<endl;
        }

        //6. iterative reverse of list
        void irev(){
            if(head==NULL||head->next==NULL){
                return;
            }
            node *prv=NULL,*cur=head,*nxt;
            while(cur!=NULL){
                nxt=cur->next;
                cur->next=prv;
                prv=cur;
                cur=nxt;
            }
            head=prv;
            return;
        }
        //7. recursive reverse of list
        node *rrev_aux(node *hd){
            if(hd->next){
                return hd;
            }
            node *newhd=rrev_aux(hd->next);
            node *p=hd->next;
            p->next=hd;
            hd->next=NULL;
            return newhd;
        }
        void rrev(){
            head=rrev_aux(head);
        }
};

int main(void){
    linkedList l1;
    l1.insert(4,1);
    l1.insert(6,1);
    l1.iprint();
    l1.irev();
    l1.iprint();
}