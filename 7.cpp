/*
Assignment No. 7	Roll No. 52

Title:	Implement all the functions of dictionary (ADT) using hashing. 
	Data: 	Set of (key,value) pairs,Keys are mapped to values, Keys 
		must be comparable, Keys must be unique 
	Standard operation: Insert(key,value), Find (key), Delete(key)
*/

#include<iostream>
#include<string.h>
using namespace std;

class Dictionary
{
	struct node
	{
		char word[50],mean[50];
		node *next;		
	}*head[26],*temp,*prev;
	
	public:
		Dictionary()
		{	
			for(int i=0;i<26;i++)
				head[i]=NULL;
	
		}
		void create();
		void find();
		void deleter();
		void display();
		int hash(char);
};

int Dictionary::hash(char ch)
{
	if((int)ch <= 90)
		return (int)ch-65;
	else
		return (int)ch-97;
}

void Dictionary::create()
{
	char ch;
	int key;
	node *New;

	do
	{
		New = new node;
		
		cout<<"\nEnter word :: ";
		cin>>New->word;

		cout<<"\nEnter meaning :: ";
		cin>>New->mean;
	
		New->next = NULL;
		
		key = hash(New->word[0]);

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
			
	}while(ch == 'y' || ch == 'Y');
	
}

void Dictionary::display()
{
	for(int i=0;i<26;i++)
	{
		cout<<"\nhead["<<(char)(i+65)<<"]";
		temp = head[i];
		while(temp != NULL)
		{
			cout<<"-->[ "<<temp->word<<", "<<temp->mean<<" ]";
			temp = temp->next;
		}
		cout<<"--> NULL";
	}
}

void Dictionary::find()
{
	char word[50];
	int key,flag=0;		

	cout<<"\nEnter word to be find :: ";
	cin>>word;
	key = hash(word[0]);

	if(head[key] != NULL)
	{
		temp = head[key];
		while(temp != NULL)
		{
			if(strcmp(temp->word,word)==0)
			{
				cout<<"\nWord : "<<temp->word<<"\nMean : "<<temp->mean;
				flag=1;
				break;
			}
			temp=temp->next;
		}
	}

	if(flag == 0)
	{
		cout<<"\n--->> Word to be search not found ...";
	}
	
}

void Dictionary::deleter()
{
	char word[50];
	int key,flag=0;
	cout<<"Enter word to be delete from dictionary :: ";
	cin>>word;
	
	key = hash(word[0]);

	if(head[key] != NULL)
	{
		temp = head[key];
		
		while(temp != NULL)
		{
			if(strcmp(temp->word,word) == 0)
			{
				if(temp == head[key])
				{
					head[key] = head[key]->next;
				}else
				if(temp->next != NULL)
				{
					prev->next = temp->next;					
				}else
				{
					prev->next = NULL;
				}				

				delete temp;
				cout<<"--->> Word is deleted form dictionay...";
				flag=1;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	
	if(flag == 0)
		cout<<"--->> Word to be delete from dictionary not found...";
		
}


int main()
{
	Dictionary dict;
	int ch;

	do
	{	cout<<"\n1.Create / Insert \n2.Display \n3.Find \n4.Delete \n0.Exit \n Enter your choice :: ";
		cin>>ch;
	
		switch(ch)
		{
			case 0:
				break;
			case 1:
				dict.create();
				break;
			case 2:
				dict.display();
				break;
			case 3:
				dict.find();
				break;
			case 4:
				dict.deleter();
				break;
			default:
				cout<<"\n--->> Invalid choice...";
		}
	}while(ch != 0);
}

/***************************   OUTPUT   ******************************

1.Create / Insert 
2.Display 
3.Find 
4.Delete 
0.Exit 
 Enter your choice :: 1

Enter word :: permit

Enter meaning :: permission

Do you want to enter next entry (y/n) : y

Enter word :: slow

Enter meaning :: low_speed

Do you want to enter next entry (y/n) : y 

Enter word :: grant

Enter meaning :: allow

Do you want to enter next entry (y/n) : y

Enter word :: frozen

Enter meaning :: freeze

Do you want to enter next entry (y/n) : y

Enter word :: discover

Enter meaning :: to_findout

Do you want to enter next entry (y/n) : y

Enter word :: command

Enter meaning :: order

Do you want to enter next entry (y/n) : y

Enter word :: tale

Enter meaning :: story

Do you want to enter next entry (y/n) : y

Enter word :: talent

Enter meaning :: natural_ability

Do you want to enter next entry (y/n) : y

Enter word :: vibrant

Enter meaning :: thrilling

Do you want to enter next entry (y/n) : n

1.Create / Insert 
2.Display 
3.Find 
4.Delete 
0.Exit 
 Enter your choice :: 2

head[A]--> NULL
head[B]--> NULL
head[C]-->[ command, order ]--> NULL
head[D]-->[ discover, to_findout ]--> NULL
head[E]--> NULL
head[F]-->[ frozen, freeze ]--> NULL
head[G]-->[ grant, allow ]--> NULL
head[H]--> NULL
head[I]--> NULL
head[J]--> NULL
head[K]--> NULL
head[L]--> NULL
head[M]--> NULL
head[N]--> NULL
head[O]--> NULL
head[P]-->[ permit, permission ]--> NULL
head[Q]--> NULL
head[R]--> NULL
head[S]-->[ slow, low_speed ]--> NULL
head[T]-->[ tale, story ]-->[ talent, natural_ability ]--> NULL
head[U]--> NULL
head[V]-->[ vibrant, thrilling ]--> NULL
head[W]--> NULL
head[X]--> NULL
head[Y]--> NULL
head[Z]--> NULL
1.Create / Insert 
2.Display 
3.Find 
4.Delete 
0.Exit 
 Enter your choice :: 3

Enter word to be find :: tale

Word : tale
Mean : story
1.Create / Insert 
2.Display 
3.Find 
4.Delete 
0.Exit 
 Enter your choice :: 4
Enter word to be delete from dictionary :: talent
--->> Word is deleted form diictionay...
1.Create / Insert 
2.Display 
3.Find 
4.Delete 
0.Exit 
 Enter your choice :: 0

********************************************************************/
