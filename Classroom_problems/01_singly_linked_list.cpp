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
    newNode->next=head; // notun node er next e head connect korlam 
    head=newNode; // notun node ta head banmai dilam
}

void insert_tail(node *&head, int x){
    node *newNode=new node(x);
    node *tmp=head;
    while(tmp->next){
        tmp=tmp->next; // head theke loop chalai last e gelam
    }
    tmp->next=newNode; // last e new node connect kore dilam
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
        tmp=tmp->next; // head theke loop chalai position e gelam
    }
    newNode->next=tmp->next; // age new tar shathe next ta connect
    tmp->next=newNode; // tarpor new ta main tai connect
}

void delete_pos(node *&head,int pos){
    if(!(size(head))) return; // size zero hoile delete korbo na
    if(pos<0 || pos>=size(head)){ // position 0 er choto ba size er boro dile invalid position
        cout<<"Invalid position!"<<endl;
        return;
    }
    node* tmp=head;
    if(pos==0){ 
        head=head->next; // head er next head hobe
        delete tmp; 
        return;
    }
    for(int i=1;i<pos;i++){
        tmp=tmp->next; // loop chalai deleting node er ager position e jabo
    }
    node* deleteNode=tmp->next; // position er porerta delete korar jonno nibo 
    tmp->next=tmp->next->next; // deleting node er porer tar shathe deleting node er ager tar connection korbo
    delete deleteNode; // delete
}

void print(node *head){
    cout<<"List: "<<endl;
    node *tmp=head;
    while(tmp!=NULL){
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