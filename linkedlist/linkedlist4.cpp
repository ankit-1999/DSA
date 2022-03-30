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
    tmp->next=n;
}

int lengthlist(node* head)
{
    int l=0;
    node* tmp=head;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        l++;
    }
    return l;
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
 int intersectionpoint(node* head,node* head2)
 {
     int lenght1=lengthlist(head);
     int lenght2=lengthlist(head2);
     int fln=abs(lenght2-lenght1);
     node* tmp=head;
     node* tmp2=head2;
     if(lenght1>lenght2)
     {
         while(tmp!=NULL && fln!=0)
         {
             tmp=tmp->next;
             fln--;

         }
     }
     else if(lenght2>lenght1)
     {
         while (tmp2!=NULL && fln!=0)
         {
            tmp2=tmp2->next;
            fln--;
         }
         
     }
     while(tmp!=NULL && tmp2!=NULL)
     {
         if(tmp->data==tmp2->data)
         {
             return tmp->data;
         }
         tmp=tmp->next;
         tmp2=tmp2->next;
     }
     return -1;
    



 }


int main()
{
    node* head=NULL;
    node* head2=NULL;
    insertnode(head,1);
    insertnode(head,2);
    insertnode(head,3);
    insertnode(head,4);
    insertnode(head,5);
    insertnode(head,6);
    insertnode(head2,9);
    insertnode(head2,8);
    insertnode(head2,5);
    insertnode(head2,6);
    displaylist(head);
    displaylist(head2);
    cout<<intersectionpoint(head,head2);

    return 0;
}