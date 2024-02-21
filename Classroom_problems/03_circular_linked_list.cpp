#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};

int size(node *head){
    if(!head) return 0;
    int cnt=0;
    node *tmp=head->next;
    cnt++; //age ekta count korte hobe
    while(tmp!=head){
        tmp=tmp->next;
        cnt++;
    }
    return cnt;
}

void insert_head(node *&head,int x){
    node *newNode=new node(x);
    if(!head){
        newNode->next=newNode;
        head=newNode;
        return;
    }
    newNode->next=head->next; 
    head->next=newNode;
    int temp=head->data;
    head->data=newNode->data;
    newNode->data=temp;
}

void insert_tail(node *&head,int x){
    insert_head(head,x);
    head=head->next;
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
    tmp->next=newNode;
}

void delete_pos(node *&head,int pos){
    if(!head) return;
    if(pos<0 || pos>=size(head)){
        cout<<"Invalid position!"<<endl;
        return;
    }
    node* tmp=head;
    if(pos==0){
        head=head->next;
        delete tmp;
        return;
    }
    for(int i=1;i<pos;i++){
        tmp=tmp->next;
    }
    node* deleteNode=tmp->next;
    tmp->next=tmp->next->next;
    delete deleteNode;
}

void print(node *head){
    if(!head){
        cout<<"List is emplty!"<<endl;
        return;
    }
    cout<<"List: ";
    node *tmp=head->next;
    cout<<head->data<<" ";
    while(tmp!=head){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

int main(){
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
            cout<<"Enter insert position: ";
            int pos; cin>>pos;
            insert_pos(head,pos,val);
        }
        else if(choice==2){
            cout<<"Enter delete position: ";
            int pos; cin>>pos;
            delete_pos(head,pos);
        }
        else if(choice==3) print(head);
        else if(choice==4) break;
        else cout<<"Invalid choice!"<<endl;
    }
}