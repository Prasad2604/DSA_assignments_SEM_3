// ============================================================================
// Name        : Assignment_3.cpp
// Author      : Prasad Gujar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// ============================================================================

#include <iostream>
#include<queue>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;
    bool lThread,rThread;
    public:
    Node(){
        data=0;
        left=right=NULL;
        lThread=rThread=1;
    }
    Node(int data){
        this->data=data;
        left=right=NULL;
        lThread=rThread=1;
    }
    class ThreadedTree{
        Node* root;
        public:
        Node* getRoot(){
            return root;
        }
        ThreadedTree(){root=NULL;}

        Node* insert(Node* root,int key){
            Node* par=NULL;
            Node* ptr=root;
            while(ptr!=NULL){
                if(key==ptr->data){
                    cout<<"No duplicate key allowed !!"<<endl;
                // break;
                    return root;
                }
                par=ptr;
                if(key<ptr->data){
                    if(ptr->lThread==false){
                        ptr=ptr->left;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(ptr->rThread==false){
                        ptr=ptr->right;
                    }
                    else{
                        break;
                    }
                }
            }

            Node* tmp = new Node(key);

            if(par==NULL){
                root=tmp;
                tmp->left=NULL;
                tmp->right=NULL;
                cout<<key<<" inserted as root!!"<<endl;
            }
            else if(key<par->data){
                tmp->left = par->left;
                tmp->right = par;
                par->lThread = false;
                par->left = tmp;
                cout<<key<<" inserted at left of "<<par->data<<endl;
            }
            else{
                tmp->right=par->right;
                tmp->left = par;
                par->rThread = false;
                par->right = tmp;
                cout<<key<<" inserted at right of "<<par->data<<endl;
            }
            return root;
        }

        void levelOrderTravesal(Node* root){
            queue<Node*> q;
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                if(temp==NULL){
                    cout<<endl;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    cout<<temp->data<<" ";
                    if(!temp->lThread){
                        q.push(temp->left);
                    }
                    if(!temp->rThread){
                        q.push(temp->right);
                    }
                }
            }
        }

        Node* getSuccessor(Node* ptr){
            if(ptr->rThread==true){
                return ptr->right;
            }
            ptr=ptr->right;
            while(ptr->lThread==false){
                ptr=ptr->left;
            }
            return ptr;
        }

        void inorder(Node* root){
            if(root==NULL){
                cout<<"Tree is empty \n";
                return;
            }
            Node* ptr=root;
            while(ptr->lThread==false){
                ptr=ptr->left;
            }
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr = getSuccessor(ptr);
            }
        }
    };
};

int main() {
// cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
Node::ThreadedTree t1;
Node* root = NULL;
root = t1.insert(root, 20);
root = t1.insert(root, 10);
root = t1.insert(root, 30);
root = t1.insert(root, 5);
root = t1.insert(root, 16);
root = t1.insert(root, 14);
root = t1.insert(root, 17);
root = t1.insert(root, 13);
t1.levelOrderTravesal(root);
t1.inorder(root);

return 0;
}