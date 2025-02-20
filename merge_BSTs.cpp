#include<iostream>
using namespace std;
#include<vector>

class TreeNode{
    TreeNode* root;
    
}
void inorder(TreeNode* root,vector<int> &in){
    if(root==NULL){
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
/*
TreeNode* inordertoBST(int s,int e,vector<int> &in){
    if(s>e){
        return NULL;
    }
    int mid= s+ (e-s)/2;
    TreeNode* root=new TreeNode(in[mid]);
    root->left=inordertoBST(s, mid-1, in);
    root->right=inordertoBST(mid+1,e,in);
    return root;
}
*/
vector<int>mergearrays(vector<int> &a,vector<int> &b){
    vector<int>ans(a.size()+b.size());
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i++];
        }
        else{
            ans[k++]=b[j++];
        }
    }
    while(i<a.size()){
        ans[k++]=a[i++];
    }
    while(j<b.size()){
        ans[k++]=b[j++];
    }
    return ans;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int>bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int>mergedarray=mergearrays(bst1, bst2);
    //int s=0;
    //int e=mergedarray.size()-1;
    //return inordertoBST(s, e, mergedarray);
    return mergedarray;

}