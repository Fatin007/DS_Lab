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

void insert(node *&head,int v){
   node *newNode=new node(v);
   if(!head){
      head=newNode;
      return;
   }
   node *tmp=head;
   while(tmp->next){
      tmp=tmp->next;
   }
   tmp->next=newNode;
}

int count(node *head){
   node *tmp=head;
   int cnt=0;
   while(tmp!=NULL){
      tmp=tmp->next;
      cnt++;
   }
   return cnt;
}

int main(){
   int x;
   node* head=NULL;
   while(69){
      cin>>x;
      if(x==-1) break;
      insert(head,x);
   }
   cout<<count(head);
}