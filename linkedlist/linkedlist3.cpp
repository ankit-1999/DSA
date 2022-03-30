#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insert(node* &head,int val) // insert in list
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

void makecycle(node* head,int cylenode)  // to make cycle at node cylenode
{
    int k=0;
    node* tmp=head;
    node* strnode;
    while(tmp->next!=NULL)
    {
        if(k==cylenode)
        {
            strnode=tmp;
        }tmp=tmp->next;
        k++;

    }
    tmp->next=strnode;
}

void checkcycle(node* &head)   // two pointers slow and fast slow will move in liner i.e pointer->next and fast will move wit gap of 2      pointer->next->next  if these two met eachother then there is cycel else no cycle;   
{
    node* slow=head;
    node* fast=head;
    while(fast!=NULL   && fast->next!=NULL )
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            cout<<"cycle detected"<<endl;
            return ;
        }
    }
   cout<<"no cycle detected"<<endl;
    return ; 
}

void removecycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast); // when slow and fast will become equal we will set fast as head and again iterate till both become equal.now increment pointer by 1 in both fast and slow:
    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL; // set slow->next = null:
    
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
    checkcycle(head);
    makecycle(head,3);
    checkcycle(head);
    removecycle(head);
    checkcycle(head);
    displaylist(head);
     
    
    return 0;
}