#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int x){
        val=x;
        right =nullptr;
        left = nullptr;
    }
} 
class LinkedList{
    public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}


    void pushback(Node* root,int x){
        if(root == nullptr){
            return new Node(x);
        }

        if(x< root->right){

        }
    }
}