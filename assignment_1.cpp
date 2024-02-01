//============================================================================
// Name        : Assignment_1.cpp
// Author      : Prasad Gujar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include<vector>
using namespace std;

class BNode{
int data;
BNode* lptr;
BNode* rptr;
public:
BNode(){
data=0;
lptr=NULL;
rptr=NULL;
}
BNode(int data){
this->data=data;
lptr=NULL;
rptr=NULL;
}

class Tree{

public:
BNode* root;

Tree(){
root=NULL;
}
void add_node(int y,queue<BNode*>& q){
BNode* curr = q.front();
if(curr->lptr && curr->rptr){
// cout<<curr->lptr->data<<" "<<curr->rptr->data<<endl;
q.pop();
curr = q.front();
}

BNode* p = new BNode(y);

if(!curr->lptr){
curr->lptr = p;
q.push(curr->lptr);
cout<<"data inserted to the left of "<<curr->data<<endl;
// return;
}
else if(!curr->rptr){
curr->rptr=p;
q.push(curr->rptr);
cout<<"data inserted to the right of "<<curr->data<<endl;
// return;
}


}
void create_tree(int n){
// int n;
// cout<<"Enter number of nodes you wanna insert :- ";
// cin>>n;
int x;
cout<<"Enter data for root node :- ";
cin>>x;
queue<BNode*> q;
if(!root){
root = new BNode(x);
q.push(root);
}

for(int i=0;i<n-1;i++){
int y;
cout<<"Enter data for "<<i+2<<"th node :- ";
cin>>y;
// bool flag=0;
add_node(y,q);
}
}


void preorder(BNode* root){
if(!root){
return;
}
cout<<root->data<<" ";
preorder(root->lptr);
preorder(root->rptr);
}

void inorder(BNode* root){
if(!root){
return;
}

inorder(root->lptr);
cout<<root->data<<" ";
inorder(root->rptr);
}

void postorder(BNode* root){
if(!root){
return;
}

postorder(root->lptr);
postorder(root->rptr);
cout<<root->data<<" ";
}
void find_leaf(BNode* curr,vector<int>& leaf){
if(!curr->lptr && !curr->rptr){
leaf.push_back(curr->data);
return;
}
find_leaf(curr->lptr,leaf);
find_leaf(curr->rptr,leaf);
}
void swapAllNodes(BNode* curr){
if(!curr){
return;
}
if(curr->lptr || curr->rptr){
BNode* temp = curr->lptr;
curr->lptr = curr->rptr;
curr->rptr = temp;
}
swapAllNodes(curr->lptr);
swapAllNodes(curr->rptr);

}

// void deleteBTree(BNode* node){
//
// }
 int height(BNode *node) {
       if(node == nullptr)
           return 0;

       int l = height(node->lptr);
       int r = height(node->rptr);

       return max(l,r)+1;
   }

 ~Tree(){
 cout<<"Tree object destroyed.."<<endl;
 }
 Tree(Tree &t1){
 this->root=t1.root;
 cout<<"Tree object copied"<<endl;
 }
 void deleteNode(BNode* &root){
 if(!root){
return;
 }
 deleteNode(root->lptr);
 deleteNode(root->rptr);
 delete root;
 root=NULL;
 }

};

};
void Copy(BNode::Tree t1){
BNode::Tree t2(t1);
}

int main() {
BNode::Tree t1;
BNode::Tree t2;

int ch;

char ans='y';
int h;int n;
vector<int> leaf;
while(ans=='y'){

cout<<endl<<"Choices :- \n 1.Create a tree.\n 2.Preorder Traversal.\n 3.Inorder Traversal\n 4.Postorder Traversal.\n 5.Find Leaf Nodes.\n 6.Find Height of the tree. \n 7.Delete Tree. \n 8.Copy Tree.\n 9.Swap left and right nodes. \n "<<endl;
cout<<endl;
cout<<"Enter choice :- ";
cin>>ch;
switch(ch){
case 1:
cout<<endl;

cout<<"Enter number of nodes you wanna insert :- ";
cin>>n;
t1.create_tree(n);
break;

case 2:
cout<<endl;
if(!t1.root){
cout<<"Tree is Empty!!"<<endl;
break;
}
cout<<"Preorder Traversal :- ";
t1.preorder(t1.root);
break;
case 3:
cout<<endl;
if(!t1.root){
cout<<"Tree is Empty!!"<<endl;
break;
}
cout<<endl<<"Inorder Traversal :- ";
t1.inorder(t1.root);
break;
case 4:
cout<<endl;
if(!t1.root){
cout<<"Tree is Empty!!"<<endl;
break;
}

cout<<endl<<"Postorder Traversal :- ";
t1.postorder(t1.root);
break;
case 5:
cout<<endl;
t1.find_leaf(t1.root,leaf);
cout<<"leaf nodes :- "<<endl;
for(int i=0;i<leaf.size();i++){
cout<<leaf[i]<<" ";
}
cout<<endl<<"Number of leaf nodes :- "<<leaf.size()<<endl;
cout<<"Number of intermediate nodes :- "<<n-1-leaf.size()<<endl;
cout<<endl;
break;
case 6:
cout<<endl;
h=t1.height(t1.root);
cout<<"Height is :- "<<h<<endl;
cout<<endl;
break;
case 7:
// ans='n';
t1.deleteNode(t1.root);
break;
case 8:
t2=t1;
cout<<"Inorder of t1 :- "<<endl;
t1.inorder(t1.root);
cout<<endl;
cout<<"Inorder of t2 :- "<<endl;
t2.inorder(t2.root);
cout<<endl<<"Tree object Copied"<<endl;
// Copy(t1);
break;
case 9:
t1.swapAllNodes(t1.root);
cout<<"Inorder of t1 :- "<<endl;
t1.inorder(t1.root);
cout<<endl;
break;



default:
cout<<"Invalid choice!!"<<endl;

}
if(ans=='n'){
break;
}
cout<<endl;
cout<<"Do you want to continue?? (y/n) :- ";
cin>>ans;



}



return 0;
}