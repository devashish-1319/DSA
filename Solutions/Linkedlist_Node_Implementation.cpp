#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(int data){
        //node mai data hai
        this -> data=data;
        //node ka next point kar rha hai abhi NULL ko
        this -> next=NULL;
    }
};

int main(){
    node* node1= new node(10);
    cout<<node1 -> data << endl;
    cout<<node1 -> next <<endl;
}