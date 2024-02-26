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
        void search();
       
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

class queue{
    int front;
    int back;
    treenode *data[30];
    treenode* root;
     treenode* temp;
    
    public:
        queue();
        void enqueue();
        void dequeue();
        int isEmpty(){
        	if(back==front)
        	{
        		return 1;
        	}
        	else
        	{
        		return 0;
        	}
        }
        friend class tree;
 	};
 	
void queue::dequeue()
{
	front=-1;
	back=-1;
}

void queue::enqueue()
{
	back++;
	data[30]=temp;
}


void tree::search()
{
	int flag = 0;
	treenode *temp;
	temp = root;
	int num;
	cout <<"Enter number to be searched: " << endl;
	cin >> num;
	while(temp != NULL)
	{
		if (num == temp->data)
		{
			flag = 1;
			break;
		}
		else if(num < temp->data)
		temp = temp->left;
		else
		temp = temp->right;
	}
	if(flag == 1)
	{
	cout << "Number found!" << endl;
	}
	else
	{
	cout << "Number not found" << endl;
	}
}

void tree::copy() {
    // Create a new tree
    tree *newTree = new tree;

    // Copy the value of the root node
    newTree->value = this->value;

 // If the root node has children, copy them recursively
    if (this->left) newTree->left = new tree;
    if (this->right) newTree->right = new tree;
    if (this->left) this->left->copy(newTree->left);
    if (this->right) this->right->copy(newTree->right);
}

void 




int main()
{
	tree bt;
	//queue q;
	bt.create();
	bt.search();
}
