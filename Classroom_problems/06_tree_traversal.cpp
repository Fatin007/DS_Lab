#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *right;
        Node *left;
    Node(int x){
        val=x;
        right=NULL;
        left=NULL;
    }
};

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    Node* root=new Node(10);
    Node* a=new Node(20);
    Node* b=new Node(30);
    Node* c=new Node(40);
    Node* d=new Node(50);
    Node* e=new Node(60);
    Node* f=new Node(70);
    Node* g=new Node(80);
    Node* h=new Node(90);
    Node* i=new Node(100);
    // Conection 
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=h;
    c->right=e;
    b->right=d;
    d->left=f;
    d->right=g;
    h->left=i;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}
    //        10
    //       /  \
    //     20    30
    //    /  \    \
    //   40  90    50
    //       /    /  \
    //     100   70  80