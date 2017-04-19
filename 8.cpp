/*Roll No:47 Batch-A4
title:- program to implement optimal binary search tree.  */

#include<iostream>
#define SIZE 10
using namespace std;
class Optimal
{
private:
	int p[SIZE];
	int q[SIZE];
	int a[SIZE];
	int w[SIZE][SIZE];
	int c[SIZE][SIZE];
	int r[SIZE][SIZE];
	int n;
	int front,rear,queue[20];
public:
	Optimal();
	void get_data();
	int Min_Value(int,int);
	void OBST();
	void build_tree();
	};

Optimal::Optimal()
	{
	front=rear=-1;
	}


void Optimal::get_data()
{
	int i;
	cout<<"\nOptimal binary search tree \n";
	cout<<"\nEnter the number of nodes\n";
	cin>>n;
	cout<<"\n Enter the data as....\n";
	for(i=1;i<=n;i++)
	{	
	cout<<"a["<<i<<"]: ";
	cin>>a[i];
	}
cout<<"\n Enter probabilities for successful search..\n";
for(i=1;i<=n;i++)
	{
	cout<<"p["<<i<<"]: ";
	cin>>p[i];
	}
cout<<"\n Enter probabilities for successful search..\n";
for(i=0;i<=n;i++)
	{
	cout<<"q["<<i<<"]: ";
	cin>>q[i];
	}
}

int Optimal::Min_Value(int i,int j)
{
int m,k;
int minimum=32000;
for(m=r[i][j-1];m<=r[i+1][j];m++)
{
	if((c[i][m-1]+c[m][j])<minimum)
	{
	minimum=c[i][m-1]+c[m][j];
	k=m;
	}
}
return k;
}


void Optimal::OBST()
{
int i,j,m,k;
for(i=0;i<n;i++)
	{
	w[i][i]=q[i];
	r[i][i]=c[i][i]=0;
	w[i][i+1]=q[i]+q[i+1]+p[i+1];
	r[i][i+1]=i+1;
	c[i][i+1]=q[i]+q[i+1]+p[i+1];
	}
w[n][n]=q[n];
r[n][n]=c[n][n]=0;
for(m=2;m<=n;m++)
	{
	for(i=0;i<=n-m;i++)
		{
		j=i+m;
		w[i][j]=w[i][j-1]+p[j]+q[j];
		k=Min_Value(i,j);
		c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
		r[i][j]=k;
		}
	}
}

void Optimal::build_tree()
{
int i,j,k;
cout<<"the optimal binary search tree for the given nodes is...\n";
cout<<"\n the root of this OBST is ::"<<r[0][n];
cout<<"\n the cost of this OBST is ::"<<c[0][n];
cout<<"\n\n\tNODE\tLEFT child\tRight Child";
cout<<"\n------------------------------"<<endl;
queue[++rear]=0;
queue[++rear]=n;
while(front!=rear)
{
	i=queue[++front];
	j=queue[++front];
	k=r[i][j];
	cout<<"\n\t"<<k;
	if(r[i][k-1]!=0)
	{
	cout<<"         "<<r[i][k-1];
	queue[++rear]=i;
	queue[++rear]=k-1;
}
else
	cout<<"        -";
	if(r[k][j]!=0)
	{
	cout<<"        "<<r[k][j];
	queue[++rear]=k;
	queue[++rear]=j;
	}
else
	cout<<"        ";
	}
	cout<<endl;
}



int main()
{
Optimal obj;
obj.get_data();
obj.OBST();
obj.build_tree();
}



/*OUTPUT:- 
student@siftworkstation:~$ g++ punam.cpp
student@siftworkstation:~$ ./a.out

Optimal binary search tree 

Enter the number of nodes
4

 Enter the data as....
a[1]: 4
a[2]: 2
a[3]: 3
a[4]: 5

 Enter probabilities for successful search..
p[1]: 3
p[2]: 3
p[3]: 1
p[4]: 1

 Enter probabilities for successful search..
q[0]: 1
q[1]: 1 
q[2]: 1
q[3]: 1
q[4]: 1
the optimal binary search tree for the given nodes is...

 the root of this OBST is ::2
 the cost of this OBST is ::26

	NODE	LEFT child	Right Child
------------------------------

	2         1        3
	1        -        
	3        -        4
	4        -        
student@siftworkstation:~$ */


