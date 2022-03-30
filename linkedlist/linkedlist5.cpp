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

void insertlist(node* &head,int val)
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
    tmp->next=n;
}

void displaylist(node* head)  // to display link list
{
    node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    }
    cout<<"NULL"<<endl;
}

void mergelist(node* &head,node* &head2,node* &head3)
{
    node* tmp=head;
    node* tmp2=head2;
    while(tmp!=NULL && tmp2!=NULL)
    {
        if(tmp->data>tmp2->data)
        {
            insertlist(head3,tmp2->data);
            tmp2=tmp2->next;
        } 
        else
        {
            insertlist(head3,tmp->data);
            tmp=tmp->next;
        }
        
    }
    while(tmp!=NULL)
    {
        insertlist(head3,tmp->data);
        tmp=tmp->next;
    }
    while(tmp2!=NULL)
    {
        insertlist(head3,tmp2->data);
        tmp2=tmp2->next;
    }
}

int main()
{
    node* head=NULL;
    node* head2=NULL;
    node* head3=NULL;
    insertlist(head,1);
    insertlist(head,2);
    insertlist(head,4);
    insertlist(head,6);
    insertlist(head,8);
    insertlist(head,10);
    insertlist(head,12);
    insertlist(head,14);
    insertlist(head2,3);
    insertlist(head2,5);
    insertlist(head2,7);
    insertlist(head2,9);
    insertlist(head2,11);
    insertlist(head2,126);
    insertlist(head2,140);
    mergelist(head,head2,head3);
    displaylist(head3);
    return 0;

}
    
