#include<iostream>
using namespace std;
class TrieNode{
public:
     TrieNode *child[26];
     bool isWord;
     TrieNode(){
        isWord=false;
        for(auto &a : child){
            a=NULL;
        }
     }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p=root;
        for(auto &a : word){
            int i=a-'a';
            if(!p->child[i]){
                p->child[i]=new TrieNode();
            }
            p=p->child[i];
        }
        p->isWord=true;
    }
    
    bool search(string word,bool prefix=false) {
        
        TrieNode* p=root;
        for(auto &a : word){
            int i=a-'a';
            if(!p->child[i]){
                return false;
            }
            p=p->child[i];
        }
        if(prefix==false){
            return p->isWord;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};