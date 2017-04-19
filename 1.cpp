/*
Assignment no. 1		Roll n. :52

Title :	A book consist of chapters, chapters consist of sections and section consist of sub sections.
	Construct a tree and print the nodes. Find the times and space requirements of your method.
*/

#include<iostream>
using namespace std;
class BT
{
	struct node
	{
		char data[50];
		node * left;
		node * right;		
	}*root;

	public:
			BT()
			{
				root=NULL;
			}
			void insert();
			void add(node *, node *);
			void display();
			void inorder(node *);			
			void preorder(node *);
			void postorder(node *);
};

void BT::insert()
{
	char ans;
	do
	{	node *New;
		New = new node;
		
		cout<<"\nEnter book/chapter/section name : ";
		cin>>New->data;

		New->left = NULL;
		New->right = NULL;

		if(root == NULL)
			root = New;
		else
			add(root,New);

		cout<<"Do you want to add more node (Y/N): ";
		cin>>ans;

	}while(ans == 'y' || ans == 'Y');
}

void BT::add(node * temp, node * New)
{
	char ans;
	
	cout<<"Where do you want to add node (L) or (R) of "<< temp->data <<" : ";
	cin>>ans;

	if(ans=='L' || ans=='l')
	{
		if(temp->left == NULL)
			temp->left = New;
		else
			add(temp->left, New);
	}else
	{
		if(temp->right == NULL)
			temp->right = New;
		else
			add(temp->right, New);
	}
}

void BT::display()
{
	if(root == NULL)
		cout<<"Tree is empty.";
	else
	{
		int ans;

		do
		{	
			cout<<"\n1.Pre-order \n2.In-order \n3.Post-order \n0.Back \n Enter choice : ";
			cin>>ans;
			
			switch(ans)
			{
				case 0:
						break;
				case 1:
						preorder(root);
						break;
				case 2:
						inorder(root);
						break;
				case 3:	
						postorder(root);
						break;
				default:
						cout<<"Invalid choice...";
			}

		}while(ans != 0);
	}
}

void BT::inorder(node * temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<"\t"<<temp->data;
		inorder(temp->right);
	}
}

void BT::preorder(node * temp)
{
	if(temp != NULL)
	{
		cout<<"\t"<<temp->data;
		preorder(temp->left);
		preorder(temp->right);
	}
}

void BT::postorder(node * temp)
{
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<"\t"<<temp->data;
	}
}

int main()
{
	BT bt;
	int ans;
	do
	{
	
		cout<<"\n1.Add node \n2.Display node \n0.exit \n Enter your choice : ";
		cin>>ans;

		switch(ans)
		{
			case 0:
					break;

			case 1:	bt.insert();			
					break;

			case 2:	bt.display();
					break;
			default:
					cout<<"\nInvalid choice...";
		}

	}while(ans != 0);
}


//10 y 20 l y 50 l l y 60 l r y 70 l r l y 80 l r r y 30 r y 90 r r y 100 r r r n

/*

1.Add node 
2.Display node 
0.exit 
 Enter your choice : 2
Tree is empty.
1.Add node 
2.Display node 
0.exit 
 Enter your choice : 1

Enter book/chapter/section name : DATA_STRUCTURE
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 1.Linked_List
Where do you want to add node (L) or (R) of DATA_STRUCTURE : l
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 1.1:Types
Where do you want to add node (L) or (R) of DATA_STRUCTURE : l
Where do you want to add node (L) or (R) of 1.Linked_List : l
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 1.1.1:Linear_list
Where do you want to add node (L) or (R) of DATA_STRUCTURE : l
Where do you want to add node (L) or (R) of 1.Linked_List : l
Where do you want to add node (L) or (R) of 1.1:Types : l
Do you want to add more node (Y/N): y                  

Enter book/chapter/section name : 1.1.2:Circular_list
Where do you want to add node (L) or (R) of DATA_STRUCTURE : l
Where do you want to add node (L) or (R) of 1.Linked_List : l
Where do you want to add node (L) or (R) of 1.1:Types : r
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 1.2:Operations    
Where do you want to add node (L) or (R) of DATA_STRUCTURE : l
Where do you want to add node (L) or (R) of 1.Linked_List : r
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 1.2.1:Traversing
Where do you want to add node (L) or (R) of DATA_STRUCTURE : l
Where do you want to add node (L) or (R) of 1.Linked_List : r
Where do you want to add node (L) or (R) of 1.2:Operations : l
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 1.2.2:Searching
Where do you want to add node (L) or (R) of DATA_STRUCTURE : l
Where do you want to add node (L) or (R) of 1.Linked_List : r
Where do you want to add node (L) or (R) of 1.2:Operations : r
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 2.Trees
Where do you want to add node (L) or (R) of DATA_STRUCTURE : r
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 2.1:Types
Where do you want to add node (L) or (R) of DATA_STRUCTURE : r
Where do you want to add node (L) or (R) of 2.Trees : l
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 2.1.1:General_tree
Where do you want to add node (L) or (R) of DATA_STRUCTURE : r
Where do you want to add node (L) or (R) of 2.Trees : l
Where do you want to add node (L) or (R) of 2.1:Types : l
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 2.1.2:Binary_tree
Where do you want to add node (L) or (R) of DATA_STRUCTURE : r
Where do you want to add node (L) or (R) of 2.Trees : l
Where do you want to add node (L) or (R) of 2.1:Types : r
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 2.2:Traversal
Where do you want to add node (L) or (R) of DATA_STRUCTURE : r
Where do you want to add node (L) or (R) of 2.Trees : r
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 2.2.1:Inorder_traversal
Where do you want to add node (L) or (R) of DATA_STRUCTURE : r
Where do you want to add node (L) or (R) of 2.Trees : r
Where do you want to add node (L) or (R) of 2.2:Traversal : l
Do you want to add more node (Y/N): y

Enter book/chapter/section name : 2.2.2:Preorder_traversal
Where do you want to add node (L) or (R) of DATA_STRUCTURE : r
Where do you want to add node (L) or (R) of 2.Trees : r
Where do you want to add node (L) or (R) of 2.2:Traversal : r
Do you want to add more node (Y/N): n

1.Add node 
2.Display node 
0.exit 
 Enter your choice : 2   

1.Pre-order 
2.In-order 
3.Post-order 
0.Back 
 Enter choice : 1
	DATA_STRUCTURE	1.Linked_List	1.1:Types	1.1.1:Linear_list	1.1.2:Circular_list
	1.2:Operations	1.2.1:Traversing	1.2.2:Searching		2.Trees		2.1:Types
	2.1.1:General_tree	2.1.2:Binary_tree	2.2:Traversal	2.2.1:Inorder_traversal	2.2.2:Preorder_traversal

1.Pre-order 
2.In-order 
3.Post-order 
0.Back 
 Enter choice : 0

1.Add node 
2.Display node 
0.exit 
 Enter your choice : 0

*/

