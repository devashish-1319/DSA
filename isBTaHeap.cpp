// Structure of node

#include<iostream>
using namespace std;
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int countnodes(Node* tree){
        if(tree==NULL){
            return 0;
        }
        int ans=1 + countnodes(tree->left)+ countnodes(tree->right);
        return ans;
    }
    bool isCBT(Node* tree,int index,int count){
        if(tree==NULL){
            return true;
        }
        if(index>=count){
            return false;
        }
        else{
            bool left=isCBT(tree->left,2*index+1,count);
            bool right=isCBT(tree->right,2*index+2,count);
            return (left && right);
        }
    }
    bool ismaxorder(Node* tree){
        if(tree->left==NULL && tree->right==NULL){
            return true;
        }
        if(tree->right==NULL){
            return (tree->data>tree->left->data);
        }
        else{
            bool left=ismaxorder(tree->left);
            bool right=ismaxorder(tree->right);
            return (left && right && tree->data > tree->left->data 
                    && tree->data > tree->right->data);
        }
    }
    bool isHeap(Node* tree) {
        // code here
        int index=0;
        int totalcount=countnodes(tree);
        if(isCBT(tree,index,totalcount) && ismaxorder(tree)){
            return true;
        }
        return false;
        
    }
};

