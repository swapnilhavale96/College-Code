#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class tbtnode // Ternary Search Tree Node
{
public:
    char data; // Character data
    bool rbit, lbit; // Right and left bit
    tbtnode *rightc; // Right child
    tbtnode *leftc; // Middle child

    // Friend class for tbt
    friend class tbt;

public:
    // Default constructor
    tbtnode();
};


tbtnode::tbtnode() // constructor for tbtnode
{                  
	lbit = 0;        // initialize left child bit to 0
	rbit = 0;        // initialize right child bit to 0
}
class tbt // Class for Threaded Binary Tree
{
private:    // Private member variables
    tbtnode *head; // Head node for threaded list

public:     // Public member functions
    void create(); // Function to create the tree
    void preorder(); // Function to perform preorder traversal
    void inorder(); // Function to perform inorder traversal
    tbtnode *insuccr(tbtnode *temp); // Function to find inorder successor
    tbt(); // Constructor for the class
};

tbt::tbt() 
{ // constructor for tbt class
   head = new tbtnode; // create new head node
   head->rbit = 1; // set head node's right child bit to 1
   head->leftc = head; // set head node's left child to itself
   head->rightc = head; // set head node's right child to itself
}

void tbt::create()
{
	tbtnode *temp; // Temp node pointer
	tbtnode *curr; // Current node pointer

	int flag;
	char ch1;
	int ch;
	tbtnode *root;
	root=new tbtnode; // Allocate memory for root node

	cout<<"Enter the root data: "<<endl;
	cin>>root->data; // Read root data

	head->lbit=1; // Set head node's left child bit to 1
	root->leftc=head; // Set root's left child to head
	root->rightc=head; // Set root's right child to head
	head->leftc=root; // Set head's left child to root
	do
    {
        flag=0;
		temp=root;
		curr=new tbtnode();
		cout<<"\n Enter the data for current node: ";
		cin>>curr->data;

		while(flag==0)
        {
            cout<<"Accept choice left or right: ";
            cin>>ch1;
            if (ch1= 'l')
            {
                if(temp->lbit==0)
                {
                    curr->rightc=temp;
                    curr->leftc=temp->leftc;
                    temp->leftc=curr;
                    temp->lbit=1;
                    flag=1;
                }
                else
                {
                    temp=temp->leftc;
                }
            }
            if(ch1=='r')
            {
               if (temp->rbit==0)
               {
                curr->leftc=temp;
				curr->rightc=temp->rightc;
				temp->rightc=curr;
				temp->rbit=1;
				flag=1;
               }
               else
               {
                temp=temp->rightc;
               }
               
            }
            cout << "\nEnter another node?(y/n): ";
            cin >> c;
		}while(ch==1);
	}
}
tbtnode *tbt::insuccr(tbtnode *temp){
	tbtnode *x=temp->rightc;
	if(temp->rbit==1)
	{
		while(x->lbit==1)
		x=x->leftc;
	}
	return x;
}

void tbt::inorder()
{
	tbtnode *temp;
	temp=head;
	while(1)
	{
		temp=insuccr(temp);
		if(temp==head)
		break;
		cout<<temp->data<<"\t";
	}
}

int main()
{
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
                  
    