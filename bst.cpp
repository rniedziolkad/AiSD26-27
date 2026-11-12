// zadanie polega na zbudowaniu drzewa bst i przejściu go inorder
// a następnie na sprawdzeniu czy istnieją szukane wartości
#include <iostream>
using namespace std;


struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

void insert(Node*& current, int key) {
    if (current == nullptr) {
        current = new Node(key);
        // cout << "Wstawiono: " << key << "\n";
        return;
    }
    if (key < current->key) {
        insert(current->left, key);
    } else if (key > current->key) {
        insert(current->right, key);
    }
    // key == current->key -- tutaj zignoruję, można to obsłużyć jakoś
}

void inorder(Node* current) {
    if (current == nullptr) return;

    inorder(current->left);
    cout << current->key << " ";
    inorder(current->right);
}

Node* find(Node* current, int target) {
    if (current == nullptr) return nullptr;
    if (current->key == target) return current;

    if (target < current->key) return find(current->left, target);
    return find(current->right, target);
}


int main() {
    Node* root = nullptr;
    int n;
    cin >> n;

    int key;
    while (n--) {
        cin >> key;
        insert(root, key);
    }
    inorder(root);
    cout << "\n";
    cin >> n;
    while(n--) {
        cin >> key;
        Node* found = find(root, key);
        if (found == nullptr) {
            cout << "N ";
        } else {
            cout << "T ";
        }
    }
    cout << "\n";
    
    return 0;
}
