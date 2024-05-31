#include <iostream>
#include <list>
#include <queue>
using namespace std;


template <class T>
list<T> createList(BSTNode<T>* root);
int main() {
    
    return 0;
}

template <class T>
class BSTNode;
template <class T>
list<T> createList(BSTNode<T>* root) {
    queue<T> q;
    list<T> llist(root);
    q.push(root);
    while (!q.empty()) {
        BSTNode<T>* curr = q.front();
        q.pop();
        if (curr->left != nullptr) {
            q.push(curr->left);
            llist.push_back(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
            llist.push_back(curr->right);
        }
    }
    return llist;
}