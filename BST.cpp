#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};

node* insertinBST(node* root,int d){
    //base case
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertinBST(root->right, d);
    }
    else{
        root->left=insertinBST(root->left, d);
    }
    return root;
}

void takeinput(node* root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertinBST(root,data);
        cin>>data;
    }
}

//Printing the Binary search tree


void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}


void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

int main(){
    node* root=NULL;
    cout<<"enter data to create"<<endl;
    takeinput(root);

    
    cout<<"level order traversal is"<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"inorder traversal is: "<<endl;
    inorder(root);

    cout<<endl<<"preorder traversal is: "<<endl;
    preorder(root);

    cout<<endl<<"postorder traversal is: "<<endl;
    postorder(root);
    

    return 0;

}