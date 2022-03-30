#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* previous;
    node* next;
    node(int value)
    {
        data=value;
        next=NULL;
        previous=NULL;
    }

};

void insert(node* &head,int value)
{
    node* n=new node(value);
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
    n->previous=tmp;
    return;

}

void sumpair(node* head,int key)
{
    node* first=head;
    node* last=head;
    bool found=false;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    
    while(last!=first && last->next!=first)
    {
        int sm=last->data+first->data;
        if(sm==key)
        {
            cout<<last->data<<" "<<first->data<<endl;
            first=first->next;
            last=last->previous;
            found=true;
        }
        else
        {
            if(sm<key)
          {
            first=first->next;

          }
            else
          {
            last=last->previous;
          } 
        }
        

            
    }
    if(found==false)
    {
        cout<<"no pair found"<<endl;
    }

}

void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}

void reverseknode(node* &head,int k)
{
    node* tmp=head;
    node* last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    while(k!=1)
    {
        tmp=tmp->next;
        k--;
    }
    node* newhead=tmp->next;
    newhead->previous=NULL;
    tmp->next=NULL;
    last->next=head;
    head->previous=last;
    head=newhead;
}

node* reverse(node* head)
{
    node* prev=NULL;
    node* current=head;
    node* nxt;
    while(current->next!=NULL)
    {
        nxt=current->next;
        current->next=prev;
        
        current->previous=nxt;
        prev=current;
        current=nxt;
    }
    
    current->next=prev;
    current->previous=NULL;
    return current;
}

node* reversegroups(node* head,int km)
{
    node* prev=NULL;
    node* current=head;
    node* nxt;
    int k=0;
    while(current!=NULL&& k<km)
    {
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
        k++;
    }
    if(nxt!=NULL)
    {
        head->next=reversegroups(nxt,km);

    }
    
    
    return prev;
    
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
    insert(head,7);
    insert(head,8);
    int key=3;
    
   
    
    // sumpair(head,key);
    
    node* tmp=reversegroups(head,3);
    display(tmp);
    return 0;
}