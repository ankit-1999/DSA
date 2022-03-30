#include<bits/stdc++.h>
using namespace std;

class node{                        // class node 
    public:
    int data;
    node* next;
    
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertatend(node* &head,int val)  // to insert at end
{
   node* n=new node(val);


    if(head==NULL)   // if list is empty then its head will be null
    {
        head=n ;
        
        return;
    }

    node* tmp=head;

    while(tmp->next!=NULL)  // to get last node
    {
        tmp=tmp->next;
    }
    
    tmp->next=n;   // last node
    
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

void insertathead(node* &head,int val)  // to insert node at head
{

    node* n=new node(val);
    n->next=head;
    head=n;

}

void searchlist(node* &head,int key)   // to search element in list
{
    node* tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->data==key)
        {
            cout<<"key found "<<endl;;
            return ;
        }
        tmp=tmp->next;
    }
    cout<<"not found"<<endl;
}

void deleteathead(node* &head)  // to delete at head
{
    node* tmp=head;
    head=tmp->next;
    delete tmp;
}

void deletioninlist(node* head,int key)  // to delete node in list
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        deleteathead(head);
        return;
    }

    node* tmp=head;
    while(tmp->next->data!=key)  
    {
        tmp=tmp->next;
    }
    node* todelete=tmp->next;
    tmp->next=tmp->next->next;
    delete todelete;
}

void reverselist(node* &head)
{
    node* previous=NULL;
    node* current=head;
    node* nxt;
    while(current!=NULL)
    {
        nxt=current->next;
        current->next=previous;
        previous=current;
        current=nxt;

    }
    head= previous;
}


void putevenafterodd(node* &head)
{
    node* evenstart;
    node* tmp=head;
    node* odd;
    node* oddstart;
    node* even;int cout=1;int yu=1;
    while(tmp!=NULL)
    {
      if(tmp->data%2==0)
      {
          if(cout==1)
          {
              evenstart=tmp;
              even=tmp;
              cout--;
          }
          else
          {
              even->next=tmp;
              even=tmp;
          }
          
      }  
      else{
          if(yu==1)
          {
              oddstart=tmp;
              odd=tmp;
              yu--;
          }
          else
          {
              odd->next=tmp;
              odd=tmp;
          }
      }
      tmp=tmp->next;
    }
    head=oddstart;
    odd->next=evenstart;
    even->next=NULL;

}





int main()
{
    node* head=NULL;
    int len;
    cin>>len;
    while(len--)
    {
        int val;
        cin>>val;
        insertatend(head,val);
    }
   // searchlist(head,9);
   // searchlist(head,5);
   /* deletioninlist(head,3);
    displaylist(head);
    deleteathead(head);
    displaylist(head);
    reverselist(head);
    displaylist(head);
    putevenafterodd(head);
    */
   reverselist(head);
   displaylist(head);

    return 0;

}



