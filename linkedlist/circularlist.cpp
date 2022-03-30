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

void insertathead(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }

    node* tmp=head;
    while(tmp->next!=head)
    {
        tmp=tmp->next;
    }
    tmp->next=n;
    n->next=head;
    head = n;



}


void insert(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        insertathead(head,val);
        return;
    }
    node* tmp=head;
    while(tmp->next!=head)
    {
        tmp=tmp->next;
    }
    tmp->next=n;
    n->next=head;
}

void displaylist(node* &head)  // to display link list
{
    node* tmp=head;
    do
    {
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    } while (tmp!=head);
    
        
    cout<<"NULL"<<endl;
}

void deleteathead(node* &head)
{
    node* tmp=head;
    while(tmp->next!=head)
    {
        tmp=tmp->next;
    }
    tmp->next=head->next;
    node* newhead=head->next;
    delete head;
    head=newhead;
}

void deletelist(node* &head,int pos)
{
    if(pos==1)
    {
        deleteathead(head);
        return;
    }
    node* tmp=head;node* prev=NULL;
    while( pos!=1)
    {
        prev=tmp;
        tmp=tmp->next;
        pos--;
    }
    prev->next=tmp->next;
    delete tmp;


}



int main()
{
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    displaylist(head);
    // deletelist(head,1);
    // displaylist(head);


    return 0;
}