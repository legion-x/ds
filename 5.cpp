/*
Assignment no. 5		Roll n. :52

Title:	There are filght paths between cities. If there is a flight between city A and B then there is an edge 
	between the cities. The cost of the edge can be the time that flight takes to reach city B from city A 
	or the amount of fuel used for the journey. Represent this as a graph. the node can be represented by 
	airport name or name of the city. Use adjacency list representation of the graph or use adjacency 
	matrix representation of the graph. Justify the storage representation used.
	
*/

#include<iostream>
#include<string.h>
using namespace std;

class Graph
{
	struct node
	{
		int weight;
		char city[50];
		node *adj;
	}*head[10],*temp;

	int vertex_total,front,rear,Q[10],visit[10],adj_mtx[10][10];
	char city[10][50];

	public :
		void create();
		void display_weight_mtx();
		void display_Adj_list();
		void bfs();
};

void Graph::create()
{
	int i,j,v1,v2,weight;
	char vc1[50],vc2[50];
	
	char ch;

	node *New;

	cout<<"\nEnter total number of vertex(cities) in graph :: ";

	cin>>vertex_total;

	for(i=0 ; i<vertex_total ; i++)
	{
		head[i] = NULL;
		
		cout<<"\nEnter name of city "<<i+1<<" :: ";
		cin>>city[i];

		for(j=0 ; j<vertex_total ; j++)
		{
			adj_mtx[i][j]=0;
		}
	}	

	do
	{
		v1=v2=99;

		cout<<"Enter edge (name of two cities): \n";
		cin>>vc1>>vc2;
	
		for(i=0 ; i<vertex_total ; i++)
		{
			if(strcmp(vc1,city[i]) == 0)
				v1=i;

			if(strcmp(vc2,city[i]) == 0)
				v2=i;
		}
		
		cout<<"Enter weight of edge "<<vc1<<"-"<<vc2<<"  :: ";
		cin>>weight;		

		if(v1 >= vertex_total || v2 >= vertex_total)
		{
			cout<<"\n -->> Error...(city not in graph)";
		}else
		{
			
			New = new node;
			strcpy(New->city , vc2);
			New->weight = weight;
			New->adj = NULL;

			temp = head[v1];
				

			if(temp == NULL)
				head[v1] = New;
			else
			{
				while(temp->adj != NULL)
					temp = temp->adj;

				temp->adj = New;	
			}


			New = new node;
			strcpy(New->city , vc1);
			New->weight = weight;
			New->adj = NULL;
			
			temp = head[v2];

			if(temp == NULL)
				head[v2] = New;
			else
			{
				while(temp->adj != NULL)
					temp = temp->adj;

				temp->adj = New;	
			}

			adj_mtx[v1][v2] = weight;
			adj_mtx[v2][v1] = weight;	
		}
	
		cout<<"\nDo you want to add another edge (y/n) : ";
		cin>>ch;	
	}while(ch=='y' || ch=='Y');
}

void Graph::display_weight_mtx()
{
	int i,j;
	
	cout<<"\n\nWeight matrix : \n\n";

	for(i=0 ; i<vertex_total ; i++)
		cout<<"\t"<<city[i];	

	for(i=0 ; i<vertex_total ; i++)
	{
		cout<<"\n\n"<<city[i]<<"\t";
		
		for(j=0 ; j<vertex_total ; j++)
		{
			cout<<adj_mtx[i][j]<<"\t";
		}		
	}
	cout<<endl;
}

void Graph::display_Adj_list()
{
	int i,j;

	cout<<"\nCity name \tAdjacent city(weight)";

	for(i=0 ; i<vertex_total ; i++)
	{		
		cout<<"\n "<<city[i]<<" \t:\t";

		temp = head[i];

		while(temp != NULL)
		{
			cout<<temp->city<<"("<<temp->weight<<")"<<"\t";
			temp=temp->adj;
		}
	}	
}

void Graph::bfs()
{

	int v1,v2,i;
	char vc[50];

	cout<<"\n Enter name of city from which BFS should start :: ";
	cin>>vc;

	for(i=0 ; i<vertex_total ; i++)
	{
		if(strcmp(vc,city[i]) == 0)
			v1=i;
	}

	cout<<endl;

	front=-1;
	rear=-1;

	for(i=0 ; i<vertex_total ; i++)
		visit[i]=0;

	visit[v1] = 1;
	Q[++rear] = v1;

	while(front != rear)
	{
		v1 = Q[++front];
		cout<<"\t"<<city[v1];
		for(v2=0 ; v2<vertex_total ; v2++)
		{
			if(adj_mtx[v1][v2]!=0 && visit[v2]==0)
			{
				Q[++rear]=v2;
				visit[v2]=1;
			}
		}
	}
}

int main()
{
	int ch;
	Graph gph;
	
	do
	{
		cout<<"\n1.Create graph \n2.Display weight matrix \n3.Display list representation \n4.BFS \n0.Exit \n Enter your choice :: ";

		cin>>ch;
		
		switch(ch)
		{
			case 0:
				break;
			case 1:
				gph.create();
				break;
			case 2:
				gph.display_weight_mtx();
				break;
			case 3:
				gph.display_Adj_list();
				break;
			case 4:
				gph.bfs();
				break;
			default:
				cout<<"Invalid choice...";			
		}
	}while(ch != 0);
	return 0;
}

/***************   OUTPUT   ***********************

1.Create graph 
2.Display weight matrix 
3.Display list representation 
4.BFS 
0.Exit 
 Enter your choice :: 1

Enter total number of vertex(cities) in graph :: 4

Enter name of city 1 :: Pune

Enter name of city 2 :: Nashik

Enter name of city 3 :: Mumbai

Enter name of city 4 :: Aurangabad
Enter edge (name of two cities): 
Pune Nashik
Enter weight of edge Pune-Nashik  :: 25

Do you want to add another edge (y/n) : y
Enter edge (name of two cities): 
Nashik Mumbai
Enter weight of edge Nashik-Mumbai  :: 22

Do you want to add another edge (y/n) : y
Enter edge (name of two cities): 
Mumbai Aurangabad
Enter weight of edge Mumbai-Aurangabad  :: 18

Do you want to add another edge (y/n) : y
Enter edge (name of two cities): 
Aurangabad Pune
Enter weight of edge Aurangabad-Pune  :: 10

Do you want to add another edge (y/n) : y
Enter edge (name of two cities): 
Aurangabad Nashik
Enter weight of edge Aurangabad-Nashik  :: 16

Do you want to add another edge (y/n) : y
Enter edge (name of two cities): 
nagpur Nashik
Enter weight of edge nagpur-Nashik  :: 77

 -->> Error...(city not in graph)
Do you want to add another edge (y/n) : n

1.Create graph 
2.Display weight matrix 
3.Display list representation 
4.BFS 
0.Exit 
 Enter your choice :: 2


Weight matrix : 

		Pune	Nashik	Mumbai	Aurangabad

Pune		0	25	0	10	

Nashik		25	0	22	16	

Mumbai		0	22	0	18	

Aurangabad	10	16	18	0	

1.Create graph 
2.Display weight matrix 
3.Display list representation 
4.BFS 
0.Exit 
 Enter your choice :: 3

City name 			Adjacent city(weight)
 Pune 		:	Nashik(25)	Aurangabad(10)	
 Nashik 		:	Pune(25)	Mumbai(22)	Aurangabad(16)	
 Mumbai 	:	Nashik(22)	Aurangabad(18)	
 Aurangabad 	:	Mumbai(18)	Pune(10)	Nashik(16)	
1.Create graph 
2.Display weight matrix 
3.Display list representation 
4.BFS 
0.Exit 
 Enter your choice :: 4

 Enter name of city from which BFS should start :: Nashik

	Nashik	Pune	Mumbai	Aurangabad
1.Create graph 
2.Display weight matrix 
3.Display list representation 
4.BFS 
0.Exit 
 Enter your choice :: 0

*/
