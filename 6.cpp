/*
Assignment No. 6	Roll No. 52
Title:	Consider telephone book database of N clients. Make use of a Hash table implementation 
	to quickly look up client's telephone number.
*/

#include<iostream>
#define MAX 10
using namespace std;
class Hash
{
	private:	struct node
			{
				int ID;
				char name[50],mobile[12];
				node *next;
			}*temp,*head[MAX];
	public:
			Hash()
			{
				for(int i=0;i<MAX;i++)
					head[i]=NULL;
			}
			void create();
			void display();
			void search();
};
void Hash::create()
{
	char ch;
	int key;
	node *New;
	do
	{
		New = new node();
		cout<<"\nEnter client ID : ";
		cin>>New->ID;
		cout<<"\nEnter client name : ";
		cin>>New->name;
		cout<<"\nEnter client mobile number : ";
		cin>>New->mobile;
		New->next=NULL;
		key = (New->ID % MAX);
		if(head[key] == NULL)
		{
			head[key]=New;
		}else
		{
			temp = head[key];
		
			while(temp->next != NULL)
				temp = temp->next;

			temp->next = New;	
		}
	
		cout<<"\nDo you want to enter next entry (y/n) : ";
		cin>>ch;	
	}while(ch=='y' || ch=='Y');
}

void Hash::display()
{
	int i,j;
	
	cout<<"*****************  Entries in Hash table  *****************";
	for(i=0 ; i<MAX ; i++)
	{		
		cout<<"\n Hash["<<i<<"] --> ";

		temp = head[i];

		while(temp != NULL)
		{
			cout<<"{"<<temp->ID<<","<<temp->name<<","<<temp->mobile<<"} --> ";
			temp=temp->next;
		}
		cout<<"NULL";
	}	
}

void Hash::search()
{
	int ID,key,flag=0;

	cout<<"\nEnter client ID :: ";
	cin>>ID;

	key = (ID % MAX);
	
	if(head[key] != NULL)
	{
		temp = head[key];

		while(temp != NULL)
		{
			if(temp->ID == ID)
			{
				cout<<"\nClient info ::\nName ->>> "<<temp->name;	
				cout<<"\nMobile No. ->>> "<<temp->mobile<<"\n";
				flag=1;
				break;	
			}
			temp = temp->next;
		}
	}
	
	if(flag==0)
	{
		cout<<"\n->>> Info for client ID "<<ID<<" is not found...\n";
	}
}
int main()
{
	Hash hash;
	int ch;		

	do
	{
		cout<<"\n####### MENU #######";
		cout<<"\n1.Create / Insert \n2.Display \n3.Search \n0.Exit \n Enter your choice :: ";

		cin>>ch;

		switch(ch)
		{
			case 0:
					break;
			case 1:
					hash.create();
					break;
			case 2:
					hash.display();
					break;
			case 3:
					hash.search();
					break;
			default:
					cout<<"\nInvalid choice...";			
		}
	
	}while(ch != 0);
}


/******************* OUTPUT *******************

####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 1

Enter client ID : 6352

Enter client name : Harish

Enter client mobile number : 8767898744 

Do you want to enter next entry (y/n) : y

Enter client ID : 7813

Enter client name : Kalpesh

Enter client mobile number : 7823698568    

Do you want to enter next entry (y/n) : y

Enter client ID : 8272 

Enter client name : Anil

Enter client mobile number : 7845390453

Do you want to enter next entry (y/n) : y

Enter client ID : 8954

Enter client name : Kushal

Enter client mobile number : 2904363749

Do you want to enter next entry (y/n) : y

Enter client ID : 8217 

Enter client name : Sudhir

Enter client mobile number : 8923472896

Do you want to enter next entry (y/n) : n

####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 2
*****************  Entries in Hash table  *****************
 Hash[0] --> NULL
 Hash[1] --> NULL
 Hash[2] --> {6352,Harish,8767898744} --> {8272,Anil,7845390453} --> NULL
 Hash[3] --> {7813,Kalpesh,7823698568} --> NULL
 Hash[4] --> {8954,Kushal,2904363749} --> NULL
 Hash[5] --> NULL
 Hash[6] --> NULL
 Hash[7] --> {8217,Sudhir,8923472896} --> NULL
 Hash[8] --> NULL
 Hash[9] --> NULL
####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 3

Enter client ID :: 8272

Client info ::
Name ->>> Anil
Mobile No. ->>> 7845390453

####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 3

Enter client ID :: 6756

->>> Info for client ID 6756 is not found...

####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 0

**************************************************************/
