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
        Node* add(string k,string m,Node* root){
            if(!root){
                return new Node(k,m);
            }

            if(k<root->key){
                root->left = add(k,m,root->left);
            }

            if(k>root->key){
                root->right = add(k,m,root->right);
            }
            return root;
        }
        void createBinaryTree(){
            int n;
            cout<<"Enter number of keys you wanna insert :- ";
            cin>>n;
            string k;string m;
            for(int i=0;i<n;i++){
                cout<<"Enter keyword "<<i<<" :- ";
                cin>>k;
                cout<<"Enter meaning of "<<k<<" :- ";
                cin>>m;
                root = add(k,m,root);
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

        void levelOrderTraversal(Node* root){
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
                    cout<<temp->key<<":"<<temp->value<<" ";
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
            }
        }

        void update(Node* root,string k,string v,bool flag){
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                if(temp->key==k){
                    temp->value=v;
                    flag=1;
                    cout<<"Value updated!!"<<endl;
                    return;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(!flag){
                root=add(k,v,root);
            }
        }
        void addKeyword() {
            string k, m;
            cout << "Enter keyword: ";
            cin >> k;
            cout << "Enter meaning: ";
            cin >> m;
            root = add(k, m, root);
        }

        Node* deleteKeyword(Node* root, string k) {
            if (!root) {
                return root;
            }

            if (k < root->key) {
                root->left = deleteKeyword(root->left, k);
            } else if (k > root->key) {
                root->right = deleteKeyword(root->right, k);
            } else {
                // Node with only one child or no child
                if (root->left == NULL) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == NULL) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                // Node with two children
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = deleteKeyword(root->right, temp->key);
            }
            return root;
        }

        Node* minValueNode(Node* node) {
            Node* current = node;
            while (current && current->left != NULL) {
                current = current->left;
            }
            return current;
        }
        void displayAscending(Node* root) {
            if (!root) {
                return;
            }
            displayAscending(root->left);
            cout << root->key << " : " << root->value << " ";
            displayAscending(root->right);
        }
        void displayDescending(Node* root) {
            if (!root) {
                return;
            }
            displayDescending(root->right);
            cout << root->key << " : " << root->value << " ";
            displayDescending(root->left);
        }

        int maxComparisons(Node* root, string k) {
            int comparisons = 0;
            while (root) {
                comparisons++;
                if (k == root->key) {
                    return comparisons;
                } else if (k < root->key) {
                    root = root->left;
                } else {
                    root = root->right;
                }
            }
            return comparisons;
        }


    };
};

 int main(){
     Node::Tree t1;
     int ch;
     string k;string v;int a;
     char ans = 'y';
     while(ans=='y'){
    cout<<"Choices :- \n1.Create Tree \n2. Add Keyword\n3. Delete Keyword\n4. Update Value\n5. Display Ascending\n6. Display Descending\n7. Find Maximum Comparisons\n";
    cin>>ch;
    switch(ch){
    case 1:t1.createBinaryTree();
    cout<<"Tree :- "<<endl;
    t1.levelOrderTraversal(t1.getRoot());
    break;
    case 2:t1.addKeyword();
    cout<<"Tree :- "<<endl;
    t1.levelOrderTraversal(t1.getRoot());
    break;
    case 3:
    cout<<"Enter key you wanna delete :- "<<endl;
    cin>>k;
    t1.deleteKeyword(t1.getRoot(),k);
    break;
    case 4:
    cout<<"Enter key whose value is to be updated :- ";
    cin>>k;
    cout<<"Enter value of that key :- ";
    cin>>v;
    t1.update(t1.getRoot(),k,v,0);
    cout<<endl;
    cout<<"Tree :- "<<endl;
    t1.levelOrderTraversal(t1.getRoot());
    break;
    case 5:
    t1.displayAscending(t1.getRoot());
    break;
    case 6:
    t1.displayDescending(t1.getRoot());
    break;
    case 7:
    cout<<"Enter key you wanna find :- "<<endl;
    cin>>k;
    a=t1.maxComparisons(t1.getRoot(),k);
    cout<<a<<endl;
    break;
    default:
    cout<<"Enter valid choice"<<endl;
    break;
    }
    cout<<endl<<"Do you waana continue?? (y/n) :- ";
    cin>>ans;
     }
 }

// 7 E e C c G g B b D d F f H h