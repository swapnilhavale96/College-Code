#include<iostream>

using namespace std;

class treenode
{
    int data;
    treenode* left;
    treenode* right;
    friend class tree;
};

class tree
{
    treenode* root;
    public:
        tree();
        void create();
       
};

tree::tree()
{
    root = NULL;
}

void tree::create()
{
	treenode* temp = root;
	root = new treenode();
        cout << "Enter data for the root: ";
        cin >> root->data;
        char choice;
        do{
        	temp=root;
       		int flag = 0;
        	treenode* curr = new treenode();
        	int data;
        	cout << "Enter data of node: ";
        	cin >> data;
        	curr->data = data;
        	curr->left = NULL;
        	curr->right = NULL;
        	
        while(flag==0){
			if(curr->data<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					flag=1;
				}
				else
					temp=temp->left;
			}
			else{
				if(temp->right==NULL)
				{
					temp->right=curr;
					flag=1;
				}
				else
					temp=temp->right;
			   }
			}
			cout << "Add more nodes?(y/n): ";
       			cin >> choice;
   		}
   	while(choice == 'y');
}

int main()
{
	tree bt;
	bt.create();
}