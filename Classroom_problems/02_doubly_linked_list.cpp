#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *prev;
    node *next;
    node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};

int size(node *&head){
    int cnt=0;
    node *tmp=head;
    while(tmp){
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
}

void insert_head(node *&head, int x){
    node *newNode=new node(x);
    if(!head){
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void insert_tail(node *&head,int x){
    node *newNode=new node(x);
    if(!head){
        head=newNode;
        return;
    }
    node *tmp=head;
    while(tmp->next){
        tmp=tmp->next;
    }
    tmp->next=newNode;
    newNode->prev=tmp;
}

void insert_pos(node *&head,int pos,int x){
    if(pos<=0){
        insert_head(head,x);
        return;
    }
    if(pos>=size(head)){
        insert_tail(head,x);
        return;
    }
    node *newNode=new node(x);
    node *tmp=head;
    for(int i=1;i<pos;i++){
        tmp=tmp->next;
    }
    newNode->next=tmp->next;
    newNode->prev=tmp;
    tmp->next->prev=newNode;
    tmp->next=newNode;
}

void delete_pos(node *&head,int pos){
    if(!size(head)){
        cout<<"List is empty!"<<endl;
        return;
    }
    if(pos<0 || pos>=size(head)){
        cout<<"Invalid position!"<<endl;
        return;
    }
    node* tmp=head;
    if(pos==0){
        head=head->next;
        delete tmp;
        if(head) head->prev=NULL;
        return;
    }
    for(int i=0;i<pos;i++){
        tmp=tmp->next;
    }
    tmp->prev->next=tmp->next;
    if(tmp->next) tmp->next->prev=tmp->prev;
    delete tmp;
}

void print(node *head){
    cout<<"List: ";
    node *tmp=head;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

int main() {
    node* head=NULL;
    while(69){
        cout<<"1: Insert"<<endl;
        cout<<"2: Delete"<<endl;
        cout<<"3: Print list"<<endl;
        cout<<"4: Exit program"<<endl;
        int choice; cin>>choice;
        if(choice==1){
            cout<<"Enter value: ";
            int val; cin>>val;
            cout<<"Enter position: ";
            int pos; cin>>pos;
            insert_pos(head,pos,val);
        }
        else if(choice==2){
            cout<<"Enter position to delete: ";
            int pos; cin>>pos;
            delete_pos(head,pos);
        }
        else if(choice==3) print(head);
        else if(choice==4) break;
        else cout<<"Invalid choice!"<<endl;
    }
}
