#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int value)
    {
        data=value;
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
    tmp->next=n;
    return;

}

int len(node* head)
{
    int k=0;
    while(head!=NULL)
    {
        head=head->next;
        k++;
    }
    return k;
}

node* reverse(node* head)
{
    node* prev=NULL;
    node* cur=head;
    node* nxt;
    while(cur!=NULL)
    {
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}

bool palin(node* head)
{
    if(head->next==NULL)
    {
        return true;
    }
    int l=len(head);
    node* tmp=head;
    node* nw;
    node* last;
    if(l%2==0)
    {
        int y=l/2;
        while (y!=1)
        {
            tmp=tmp->next;
            y--;
        }
        nw=tmp->next;
        tmp->next=NULL;
        last=reverse(nw);
    }
    else
    {
        int y=l/2;
          while (y!=1)
        {
            tmp=tmp->next;
            y--;
        }
        nw=tmp->next->next;
        tmp->next=NULL;
        last=reverse(nw);
    }
    while(head!=NULL && last!=NULL)
    {
        if(head->data!=last->data)
        {
            return false;
        }
        head=head->next;
        last=last->next;
    }
    return true;
}


        




        



int main()
{
    node* head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        insertnode(head,y);
    }
    cout<<palin(head);

    return 0;
}
