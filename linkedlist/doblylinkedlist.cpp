#include<bits/stdc++.h>
using namespace std;

class doublenode
{
    public:
    doublenode* prev;
    int data;
    doublenode* next;
    doublenode (int val)
    {
        prev=NULL;
        data=val;
        next=NULL;
    }
};

void insertdoublelist(doublenode* &head,int val)
{
    doublenode* n=new doublenode(val);
    if(head==NULL)
    {
        head=n;
        return;
    }

    doublenode* tmp=head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=n;
    n->prev=tmp;
    return;
}

void displaylist(doublenode* head)
{
    doublenode* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    }
    cout<<"NULL"<<endl;
}


void deleteathead(doublenode* &head)
{
    doublenode* tmp=head;
    tmp->next->prev=NULL;
    head=tmp->next;
    delete tmp;
}


void deletionlist(doublenode* &head,int key)
{
    doublenode* previous=NULL;
    doublenode* current=head;
    if(key==1)
    {
        deleteathead(head);
        return;
    }
    while(current->data!=key)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
    current->next->prev=previous;

    delete current;
}

void appendlastknodes(doublenode* &head,int k)
{
    doublenode* start;
    doublenode* tail;
    doublenode* tmp=head;
    int l=0;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
        l++;
    }
    l++;
    
    tail=tmp;
    tmp=head;
    
    int t=l-k;
    
    while(tmp!=NULL && t!=0)
    {
        tmp=tmp->next;
        t--;
    }
    tmp->prev->next=NULL;
    start=tmp;
    start->prev=NULL;
    tail->next=head;
    head->prev=tail;
    
    head=start;

}

    


   




int main()
{
    doublenode* head=NULL;
    insertdoublelist(head,1);
    insertdoublelist(head,2);
    insertdoublelist(head,3);
    insertdoublelist(head,4);
    insertdoublelist(head,5);
    insertdoublelist(head,6);
   // displaylist(head);
   // deletionlist(head,3);
   // displaylist(head);
   // deletionlist(head,1);
    displaylist(head);
    appendlastknodes(head,3);
    displaylist(head);

    return 0;
};