#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    string key;
    string value;
    Node* left;
    Node* right;
    public:
    Node(){key=" ";value=" ";left=right=NULL;}
    Node(string key,string value){
        this->key=key;
        this->value=value;
        left=right=NULL;
    }

    class Tree{
        Node* root;
        public:
        Node* getRoot(){
            return this->root;
        }
        Tree(){
            root=NULL;
        }
        void add(string k,string m,queue<Node*>&q){
            Node* curr = q.front();
            if(!curr->left && k<curr->key){
                curr->left = new Node(k,m);
                q.push(curr->left);
                cout<<k<<" inserted at left of "<<curr->key<<endl;
            }
            else if(!curr->right && k>curr->key){
                curr->right = new Node(k,m);
                q.push(curr->right);
                cout<<k<<" inserted at right of "<<curr->key<<endl;
            }
            if(curr->left && curr->right){
                q.pop();
            }
        }
        void createBinaryTree(){
            int n;
            cout<<"Enter number of keys you wanna insert :- ";
            cin>>n;
            string k;string m;
            cout<<"Enter keyword :- ";
            cin>>k;
            cout<<"Enter meaning of "<<k<<":- ";
            cin>>m;
            if(!root){
                root = new Node(k,m);
            }
            
            queue<Node*> q;
            q.push(root);
            for(int i=1;i<n;i++){
                cout<<"Enter keyword "<<i<<" :- ";
                cin>>k;
                    cout<<"Enter meaning of "<<k<<" :- ";
                cin>>m;
                add(k,m,q);
            }

        }
        

        void inorder(Node* root){
            if(!root){
                return;
            }
            inorder(root->left);
            cout<<root->key<<" : "<<root->value<<" ";
            inorder(root->right);
        }
    };
};

int main(){
    Node::Tree t1;
    t1.createBinaryTree();
    t1.inorder(t1.getRoot());
}