/*
Assignment no. : 3	Roll no. : 52	

Title :	A dictionary stores keywords & its meanings. Provide facility for adding new keywords,
	deleting keywords, updating values of any entry. Provide facility to display whole data sorted
	in ascending / descending order. Also find how many maximum comparisons may require for
	finding any keywords. Use binary search tree for implementation.
*/

#include<iostream>
#include<string.h>
using namespace std;
class BST
{
	struct node
	{
		char word[50], mean[50];	
		node * left;
		node * right;		
	}*root,*temp,*parent,*temp_successor;

	public:
			BST()
			{
				root=NULL;
			}
			void insert();
			void add(node *, node *);
			void display();
			void inorder(node *);			
			void search();
			void deleter();
			void update();
};
void BST::insert()
{
	char ans;
	do
	{	node *New;
		New = new node;		
		cout<<"\nEnter word : ";
		cin>>New->word;
		cout<<"\nEnter meaning : ";
		cin>>New->mean;
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


	if(strcmp(New->word , temp->word) == 0)
	{
		cout<<"\nWord already exist...";
		return;
	}
	if(strcmp(New->word , temp->word) == 1)
	{
		if(temp->right == NULL)
			temp->right = New;
		else
			add(temp->right, New);
	}else
	{
		if(temp->left == NULL)
			temp->left = New;
		else
			add(temp->left, New);
	}
}
void BST::display()
{
	if(root == NULL)
		cout<<"Tree is empty.";
	else
	{	int ans;
		do
		{	cout<<"\n1.In-order \n0.Back \n Enter choice : ";
			cin>>ans;
			
			switch(ans)
			{
				case 0:
						break;
				case 1:
						inorder(root);
						break;
				default:
						cout<<"Invalid choice...";
			}

		}while(ans != 0);
	}
}
void BST::inorder(node * temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<"\nWord :: "<<temp->word<<"\n\tMeaning :: "<<temp->mean;
		inorder(temp->right);
	}
}

void BST::search()
{
	if(root == NULL)
	{
		cout<<"Tree is Empty";	
	}else
	{		
		int flag=0,cmp=0;
		char search[50];
		cout<<"Enter word to be search : ";		
		cin>>search;
			temp = root;
			while(temp != NULL)
			{
				if(strcmp(search , temp->word) == (-1))
				{	cmp++;
					temp = temp->left;
				}else			
				if(strcmp(search , temp->word) == 1)
				{	cmp++;
					temp = temp->right;				
				}else
				if(strcmp(search , temp->word) == 0)
				{	cmp++;
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				cout<<"Word found...\nMeaning :: "<<temp->mean<<"\nComparisons required :: "<<cmp;		
			}else
			{
				cout<<"Word Not found...";
			}			
	}
}
void BST::deleter()
{
	if(root == NULL)
	{
		cout<<"\nTree is empty.";
	}else
	{	temp = root;
		parent = root;
		int flag = 0;
		char del_word[50];
		
		cout<<"\nEnter word to be deleted.";
		cin>>del_word;
					
		while(temp != NULL)
		{
			if(strcmp(temp->word,del_word) == 0)
			{
				if(temp->right == NULL && temp->left == NULL)
				{
					cout<<"Parent --> "<<parent->word;

					if(parent->left == temp)
						parent->left = NULL;
					else
						parent->right = NULL;	
				}				
				if(temp->left != NULL && temp->right == NULL)
				{
					if(parent->left == temp)
						parent->left = temp->left;
					else
						parent->right = temp->left;
				}				
				if(temp->left == NULL && temp->right != NULL)
				{
					if(parent->left == temp)
						parent->left = temp->right;
					else
						parent->right = temp->right;
				}
				if(temp->left != NULL && temp->right != NULL)
				{
					parent = temp;
					temp_successor = temp->right;
					while(temp_successor->left != NULL) 
					{	
						parent = temp->right;
						temp_successor = temp_successor->left;
					}
					strcpy(temp->word , temp_successor->word);
					strcpy(temp->mean , temp_successor->mean);
					if(parent->left == temp_successor)
						parent->left = temp_successor->right;
					else
						parent->right = temp_successor->right;
				}
				flag = 1;
			}
			if(strcmp(del_word , temp->word) == 1)
			{
				parent = temp;
				temp = temp->right;
			}else
			{
				parent = temp;
				temp = temp->left;
			}
			
		}
		if(flag == 1)
			cout<<"\nNode is deleted...";
		else
			cout<<"\nNode not found...";
	}
}
void BST::update()
{
	if(root == NULL)
	{
		cout<<"Tree is Empty";	
	}else
	{	int flag=0;
		char search[50];
		cout<<"Enter word of which meaning you want to update : ";		
		cin>>search;		
			temp = root;
			while(temp != NULL)
			{
				if(strcmp(search , temp->word) == (-1))
				{
					temp = temp->left;
				}else			
				if(strcmp(search , temp->word) == 1)
				{
					temp = temp->right;				
				}else
				if(strcmp(search , temp->word) == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				char update[50];
				cout<<"Word found...\nMeaning :: "<<temp->mean;
				cout<<"\nEnter updated meaning : ";
				cin>>update;
				strcpy(temp->mean , update);
				cout<<"\nMeaning updated...";
		
			}else
			{
				cout<<"Word Not found...";
			}				
	}
}
int main()
{
	BST bst;
	int ans;
	do
	{
	
		cout<<"\n1.Add node \n2.Display node \n3.Search \n4.Delete \n5.Update \n0.exit \n Enter your choice : ";
		cin>>ans;

		switch(ans)
		{
			case 0:
					break;

			case 1:	bst.insert();			
					break;

			case 2:	bst.display();
					break;
			case 3:
					bst.search();
					break;
			case 4:
					bst.deleter();
					break;
			case 5:
					bst.update();
					break;
			default:
					cout<<"\nInvalid choice...";
		}

	}while(ans != 0);
}


/***************   OUTPUT   ******************

1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 1

Enter word : permit

Enter meaning : permission
Do you want to add more node (Y/N): y

Enter word : slow

Enter meaning : low_speed
Do you want to add more node (Y/N): y

Enter word : grant

Enter meaning : allow
Do you want to add more node (Y/N): y

Enter word : frozen

Enter meaning : freeze
Do you want to add more node (Y/N): y

Enter word : discover

Enter meaning : to_findout
Do you want to add more node (Y/N): y

Enter word : command

Enter meaning : order
Do you want to add more node (Y/N): y

Enter word : tale

Enter meaning : story
Do you want to add more node (Y/N): y

Enter word : talent

Enter meaning : natural_ability
Do you want to add more node (Y/N): y

Enter word : vibrant

Enter meaning : thrilling
Do you want to add more node (Y/N): n

1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 2

1.In-order 
0.Back 
 Enter choice : 1

Word :: command
	Meaning :: order
Word :: discover
	Meaning :: to_findout
Word :: frozen
	Meaning :: freeze
Word :: grant
	Meaning :: allow
Word :: permit
	Meaning :: permission
Word :: slow
	Meaning :: low_speed
Word :: tale
	Meaning :: story
Word :: talent
	Meaning :: natural_ability
Word :: vibrant
	Meaning :: thrilling
1.In-order 
0.Back 
 Enter choice : 0

1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 3
Enter word to be search : permit
Word found...
Meaning :: permission
Comparisons required :: 1
1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 3
Enter word to be search : track
Word Not found...
1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 4

Enter word to be deleted.tale

Node is deleted...
1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 2

1.In-order 
0.Back 
 Enter choice : 1

Word :: command
	Meaning :: order
Word :: discover
	Meaning :: to_findout
Word :: frozen
	Meaning :: freeze
Word :: grant
	Meaning :: allow
Word :: permit
	Meaning :: permission
Word :: slow
	Meaning :: low_speed
Word :: talent
	Meaning :: natural_ability
Word :: vibrant
	Meaning :: thrilling
1.In-order 
0.Back 
 Enter choice : 0

1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 5   
Enter word of which meaning you want to update : vibrant
Word found...
Meaning :: thrilling
Enter updated meaning : vibrating

Meaning updated...
1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 2

1.In-order 
0.Back 
 Enter choice : 1

Word :: command
	Meaning :: order
Word :: discover
	Meaning :: to_findout
Word :: frozen
	Meaning :: freeze
Word :: grant
	Meaning :: allow
Word :: permit
	Meaning :: permission
Word :: slow
	Meaning :: low_speed
Word :: talent
	Meaning :: natural_ability
Word :: vibrant
	Meaning :: vibrating
1.In-order 
0.Back 
 Enter choice : 0

1.Add node 
2.Display node 
3.Search 
4.Delete 
5.Update 
0.exit 
 Enter your choice : 0

*/
