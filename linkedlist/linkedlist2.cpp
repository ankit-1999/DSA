#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertnode(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }

    node* tmp=head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=n ;
}

void displaylist(node* head)
{
    node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverseknodes(node* &head,int k)
{
    node* previous=NULL;
    node* current=head;
    node* nxt;
    int count=0;
    while(current!=NULL && count<k)
    {
        nxt=current->next;
        current->next=previous;
        previous=current;
        current=nxt;
        count++;
    }
    if(nxt!=NULL)
    {
        head->next=reverseknodes(nxt,k);
    }
    return previous;
}

void rever(node* head,node* tail)
{
    if(head==NULL)
    {
        return ;
    }
    rever(head->next,tail);
    if(head==tail)
    {
        return ;
    }
    else
    {
        head->next->next=head;
    }
}

node* gettail(node* head)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    return head;
}

 int main()
 {
     node* head=NULL;
     insertnode(head,3);
     insertnode(head,6);
     insertnode(head,9);
     insertnode(head,10);
     insertnode(head,11);
     insertnode(head,12);
     insertnode(head,13);
     insertnode(head,14);
     
    /* insertnode(head,4);
     insertnode(head,5);
     insertnode(head,9);
     insertnode(head,9);
     insertnode(head,9);
     insertnode(head,9);
     insertnode(head,9);
     insertnode(head,9);
     
     // displaylist(head);
      // int k=2;
     //  node* newhead= reverseknodes(head,k);
     // displaylist(newhead);
     node* tail=gettail(head);
     rever(head,tail);
     head->next=NULL;
     node* hed=tail;int car=0;
     while(hed!=NULL)
     {
         if(hed==tail)
         {
             if(hed->data==9)
             {
                 hed->data=0;
                 car=1;
             }
             else
             {
                 hed->data=hed->data+1;
                 break;
             }
         }
         else
         {
             if(car==1)
             {
                 if(hed->data==9)
                 {
                     hed->data=0;
                     car=1;

                 }
                 else
                 {
                     hed->data=hed->data+car;
                     break;
                 }
             }
             else
             {
                 break;
             }
         }
         hed=hed->next;

        

     }
     rever(tail,head);
     tail->next=NULL;

     displaylist(head);

     */
    
    node* tmp=reverseknodes(head,2);
    displaylist(tmp);
    


     return 0;
 }







