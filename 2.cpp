/*
Assignment no. : 2	Roll no. : 52	

Title :	Beginning with an empty binary search tree, Construct binary search tree by inserting  the 
	values in the order given. After constructing a binary tree -
	i.Insert new node
	ii.Find number of nodes in longest path
	iii.Minimum data value found in the tree
	iv.Change a tree so that the roles of the left and right pointers are swapped at every node
	v.Search a value
*/

#include<iostream>
using namespace std;
class BST
{
	struct node
	{
		int number;
		node * left;
		node * right;		
	} *root, *temp, *stk[10];
	
	int top, min, max;

	public:
			void insert();
			void add(node *, node *);
			void display();
			void inorder_rec(node *);
			void inorder_nrec(node *);
			int count(node *);
			int height(node * temp);			
			void min_max(node *);			

			node *swapper(node * temp)
			{
				node *p;

				if(temp != NULL)
				{
					p = temp->left;

					temp->left = swapper(temp->right);

					temp->right = swapper(p);
				}
					
				return temp;
			}


			BST()
			{
				top = -1;
				root = NULL;
			}

			int empty()
			{
				if(top == -1)
					return 1;
				else
					return 0;
			}
		
			void push(node *p)
			{
				stk[++top] = p;
			}
			
			node * pop()
			{
				return(stk[top--]);
			} 
};

void BST::insert()
{
	char ans;
	do
	{
		node *New;
		New = new node;
		
		cout<<"\nEnter number : ";
		cin>>New->number;

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

void BST::add(node * temp, node * New)
{

	if(New->number < temp->number)
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

void BST::display()
{
	if(root == NULL)
		cout<<"Tree is empty.";
	else
	{
		int ans;

		do
		{	
			cout<<"\n1.In-order_recursive \n2.In-order_non_recursive \n3.Count \n4.Swapper \n5.Height \n6.Min_Max node \n0.Back \n Enter choice : ";
			cin>>ans;
			
			switch(ans)
			{
				case 0:
						break;
				case 1:
						inorder_rec(root);
						break;
				case 2:
						inorder_nrec(root);
						break;
				case 3:
						cout<<"Total nodes in tree are : "<<count(root);
						break;
				case 4:
						swapper(root);
						cout<<"After swap tree is :";
						inorder_rec(root);			
						break;
				case 5:
						cout<<"Height of tree is :"<<height(root);
						break;

				case 6:
						min = root->number;	
						max = root->number;						
						min_max(root);
						cout<<"Max : "<<max<<"\t"<<"Min : "<<min;
						break;
				default:
						cout<<"Invalid choice...";
			}

		}while(ans != 0);
	}
}

void BST::inorder_rec(node * temp)
{
	if(temp != NULL)
	{
		inorder_rec(temp->left);
		cout<<"\t"<<temp->number;
		inorder_rec(temp->right);
	}
}

void BST::inorder_nrec(node *temp)
{
	while(temp != NULL)
	{
		push(temp);
		temp = temp->left;
	}
	
	while(!empty())
	{
		temp = pop();
		cout<<"\t"<<temp->number;
		temp = temp->right;
	
		while(temp != NULL)
		{
			push(temp);
			temp = temp->left;
		}
	}
}

int BST::count(node * temp)
{
	if(temp == NULL)
		return 0;

	return (1 + count(temp->left) + count(temp->right));
	
}

int BST::height(node * temp)
{
	int hl,hr;

	if(temp == NULL)
	{
		return 0;
	}
	if(temp -> left == NULL && temp -> right == NULL)
	{
		return 0;
	}

	hl = height(temp->left);
	hr = height(temp->right);

	if(hr < hl)
	{
		return (hl + 1);
	} 
	return (hr + 1);
}

void BST::min_max(node * temp)
{
	if(temp != NULL)
	{
		if(temp->number > max)
			max = temp->number;
		
		if(temp->number < min)
			min = temp->number;

		min_max(temp->right);
		min_max(temp->left);
	}
}


int main()
{
	BST bst;
	int ans;
	do
	{
		cout<<"\n1.Add node \n2.Display node \n0.exit \n Enter your choice : ";
		cin>>ans;

		switch(ans)
		{
			case 0:
					break;

			case 1:	bst.insert();			
					break;

			case 2:	bst.display();
					break;

			default:
					cout<<"\nInvalid choice...";
		}

	}while(ans != 0);
}



//////////////	30 y 15 y 45 y 7 y 18 y 33 y 78 y 3 y 8 y 16 y 25 y 55 n
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

Enter number : 30
Do you want to add more node (Y/N): y

Enter number : 15
Do you want to add more node (Y/N): y

Enter number : 45
Do you want to add more node (Y/N): y

Enter number : 7
Do you want to add more node (Y/N): y

Enter number : 18
Do you want to add more node (Y/N): y

Enter number : 33
Do you want to add more node (Y/N): y

Enter number : 78
Do you want to add more node (Y/N): y

Enter number : 3
Do you want to add more node (Y/N): y

Enter number : 8
Do you want to add more node (Y/N): y

Enter number : 16
Do you want to add more node (Y/N): y

Enter number : 25
Do you want to add more node (Y/N): y

Enter number : 55
Do you want to add more node (Y/N): n

1.Add node 
2.Display node 
0.exit 
 Enter your choice : 2

1.In-order_recursive 
2.In-order_non_recursive 
3.Count 
4.Swapper 
5.Height 
6.Min_Max node 
0.Back 
 Enter choice : 1
	3	7	8	15	16	18	25	30	33	45	55	78
1.In-order_recursive 
2.In-order_non_recursive 
3.Count 
4.Swapper 
5.Height 
6.Min_Max node 
0.Back 
 Enter choice : 2
	3	7	8	15	16	18	25	30	33	45	55	78
1.In-order_recursive 
2.In-order_non_recursive 
3.Count 
4.Swapper 
5.Height 
6.Min_Max node 
0.Back 
 Enter choice : 3

Total nodes in tree are : 12

1.In-order_recursive 
2.In-order_non_recursive 
3.Count 
4.Swapper 
5.Height 
6.Min_Max node 
0.Back 
 Enter choice : 4

After swap tree is :	78	55	45	33	30	25	18	16	15	8	7	3

1.In-order_recursive 
2.In-order_non_recursive 
3.Count 
4.Swapper 
5.Height 
6.Min_Max node 
0.Back 
 Enter choice : 5

Height of tree is :3

1.In-order_recursive 
2.In-order_non_recursive 
3.Count 
4.Swapper 
5.Height 
6.Min_Max node 
0.Back 
 Enter choice : 6

Max : 78	Min : 3

1.In-order_recursive 
2.In-order_non_recursive 
3.Count 
4.Swapper 
5.Height 
6.Min_Max node 
0.Back 
 Enter choice : 0

*/
