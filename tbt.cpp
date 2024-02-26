#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class tbtnode{
    int data;
    bool rbit;
    bool lbit;
    tbtnode* right;
    tbtnode* left;
    friend class tbt;
    public:
        tbtnode();
};

tbtnode::tbtnode() {   // constructor for tbtnode
    lbit = 0;            // initialize left child bit to 0
    rbit = 0;            // initialize right child bit to 0
}

class tbt{
    tbtnode* head;
    public:
        void create();
        void preOrder();
        void inOrder();
        tbtnode* insuccr(tbtnode* temp);
        tbt();
};

tbt::tbt(){
    head = new tbtnode();
    head->rbit = 1;
    head->left = head;
    head->right = head;
}

void tbt::create(){
    tbtnode* root = new tbtnode();
    int data;
    cout << "Enter data of root node: ";
    cin >> data;
    root->data = data;
    head->lbit = 1;
    root->left = head;
    root->right = head;
    head->left = root;
    char c = 'y';
    do{
        int flag = 0;
        tbtnode* temp = root;
        tbtnode* curr = new tbtnode();
        int data;
        cout << "Enter data of node: ";
        cin >> data;
        curr->data = data;
        while(flag == 0){
            char ch;
            cout << "Enter node on left or right?(l/r): ";
            cin >> ch;
            if (ch == 'l'){
                if (temp->lbit == 0){
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 1;
                    flag = 1;
                }else{
                    temp = temp->left;
                }
            }else{
                if (temp->rbit == 0){
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 1;
                    flag = 1;
                }else{
                    temp = temp->right;
                }
            }
        }
        cout << "\nEnter another node?(y/n): ";
        cin >> c;
    }while(c == 'y');
}

void tbt::inOrder(){
    tbtnode* temp = head;
    while(1){
        temp = insuccr(temp);
        if (temp == head){
            break;
        }
        cout << temp->data << " ";
    }
}

tbtnode* tbt::insuccr(tbtnode* temp){
    tbtnode* x = temp->right;
    if (temp->rbit == 1){
        while(x->lbit == 1){
            x = x->left;
        }
    }
    return x;
}

void tbt::preOrder(){
    tbtnode* temp = head->left;
    while(temp != head){
        cout << temp->data << " ";
        while(temp->lbit != 0){
            temp = temp->left;
            cout << temp->data << " ";
        }
        while(temp->rbit == 0){
            temp = temp->right;
        }
        temp = temp->right;
    }
}

int main(){
    tbt tbt;
    tbt.create();
    int n;
    cout << "Inorder or Preorder traversal?(1/0): ";
    cin >> n;
    if (n == 1){
        tbt.inOrder();
    }
    else{
        tbt.preOrder();
    }
    return 0;
}
