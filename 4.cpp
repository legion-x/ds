/*
Assignment no. : 4	Roll no. : 52

Title:	Write a function to get the number of vertices is an undirected graph and it's edges.
	You may assume that no edges is input twice
	1.Use adjacency list representation of graph and find run time of the function
	2.Use adjacency matrix representation of graph and find run time of the function
*/

#include<iostream>
using namespace std;

class Graph
{
	struct node
	{
		int vertex;
		node *adj;
	}*head[10],*temp;

	int vertex_total,visit[10],adj_mtx[10][10];

	public :
		void init_visited();
		int create();
		void display_Adj_mtx();
		void display_Adj_list();
		void dfs(int);
};

void Graph::init_visited()
{
	for(int i=0 ; i<vertex_total ; i++)
		visit[i]=0;
}

int Graph::create()
{
	int i,j,v1,v2;
	char ch;

	node *New;

	cout<<"\nEnter total number of vertex in graph :: ";

	cin>>vertex_total;

	for(i=0 ; i<vertex_total ; i++)
	{
		head[i] = NULL;

		for(j=0 ; j<vertex_total ; j++)
		{
			adj_mtx[i][j]=0;
		}
	}	

	do
	{
		cout<<"Enter edge : \n";
		cin>>v1>>v2;

		if(v1 >= vertex_total || v2 >= vertex_total)
		{
			cout<<"\n -->> Error...(max vertex no. ( 0 - "<<vertex_total-1<<") )";
		}else
		{
			
			New = new node;

			New->vertex = v2;
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

			New->vertex = v1;
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

			adj_mtx[v1][v2] = 1;
			adj_mtx[v2][v1] = 1;	
		}
	
		cout<<"\nDo you want to add another edge (y/n) : ";
		cin>>ch;	
	}while(ch=='y' || ch=='Y');

	return vertex_total;
}

void Graph::display_Adj_mtx()
{
	int i,j;
	
	cout<<"\nAdjacency matrix : \n\n";

	for(i=0 ; i<vertex_total ; i++)
	{
		cout<<"\n\n";
		
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

	cout<<"\nvertex no. \tAdjacent vertex";

	for(i=0 ; i<vertex_total ; i++)
	{		
		cout<<"\n v"<<i<<" \t:\t";

		temp = head[i];

		while(temp != NULL)
		{
			cout<<temp->vertex<<"\t";
			temp=temp->adj;
		}
	}	
}

void Graph::dfs(int v1)
{
	int v2;
	cout<<"\t"<<v1;
	visit[v1]=1;
	
	for(v2=0 ; v2<vertex_total ; v2++)
	{
		if(adj_mtx[v1][v2]==1  &&  visit[v2]==0)
		{
			dfs(v2);
		}
	}

}

int main()
{
	int ch,v,i,vertex_total;
	Graph gph;
	
	do
	{
		cout<<"\n1.Create graph \n2.Display Adjacency matrix \n3.Display list representation \n4.DFS \n0.Exit \n Enter your choice :: ";

		cin>>ch;
		
		switch(ch)
		{
			case 0:
				break;
			case 1:
				vertex_total = gph.create();
				break;
			case 2:
				gph.display_Adj_mtx();
				break;
			case 3:
				gph.display_Adj_list();
				break;
			case 4:				
				cout<<"\n Enter vertex number from which DFS should start :: ";
				cin>>v;			
				cout<<endl;		
				gph.init_visited();
				gph.dfs(v);				
				break;
			default:
				cout<<"Invalid choice...";			
		}
	}while(ch != 0);
	return 0;
}

/***************   OUTPUT ***************


1.Create graph 
2.Display Adjacency matrix 
3.Display list representation 
4.DFS 
0.Exit 
 Enter your choice :: 1

Enter total number of vertex in graph :: 4
Enter edge : 
0 2

Do you want to add another edge (y/n) : y
Enter edge : 
0 1

Do you want to add another edge (y/n) : y
Enter edge : 
0 3

Do you want to add another edge (y/n) : y
Enter edge : 
1 3

Do you want to add another edge (y/n) : y
Enter edge : 
3 2

Do you want to add another edge (y/n) : n

1.Create graph 
2.Display Adjacency matrix 
3.Display list representation 
4.DFS 
0.Exit 
 Enter your choice :: 2

Adjacency matrix : 

0	1	1	1	

1	0	0	1	

1	0	0	1	

1	1	1	0	

1.Create graph 
2.Display Adjacency matrix 
3.Display list representation 
4.DFS 
0.Exit 
 Enter your choice :: 3

vertex no. 	Adjacent vertex
 v0 	:	2	1	3	
 v1 	:	0	3	
 v2 	:	0	3	
 v3 	:	0	1	2	
1.Create graph 
2.Display Adjacency matrix 
3.Display list representation 
4.DFS 
0.Exit 
 Enter your choice :: 4

 Enter vertex number from which DFS should start :: 0

	0	1	3	2
1.Create graph 
2.Display Adjacency matrix 
3.Display list representation 
4.DFS 
0.Exit 
 Enter your choice :: 0

*/
