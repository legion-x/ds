/*
Assignment no. 11	Roll n. :52

Title: Program for Student Information using Sequential File */

#include <stdio.h>
#include<stdlib.h>
typedef struct 
{
  	int roll;
    	char name[25];
    	int m1,m2,m3;
}stud;
stud s;
void display(FILE *);
int search(FILE *,int);
void main() 
{
    	int i, n, key, ch;
    	FILE *fp;
	char ans;
    	printf("\nHow many Records ? ");
    	scanf("%d",&n);
    	fp=fopen("stud.dat","w");
    	for (i=0;i<n;i++) 
	{
    		printf("\nRead the Info for Student: %d (Roll No,Name,m1,m2,m3) \n",i+1);
    		scanf("%d%s%d%d%d",&s.roll,s.name,&s.m1,&s.m2,&s.m3);
    		fwrite(&s,sizeof(s),1,fp);
    	}
    	fclose(fp);
    	fp=fopen("stud.dat","r");
    	do 
	{	printf("\n\t***MENU****");
    		printf("\n1.Display\n2.Search\n3.Exit");
		printf("\nEnter Your choice");
    		scanf("%d",&ch);
    		switch(ch) 
		{
    			case 1: 	printf("\nStudent Records in the File \n");
    					display(fp);
    					break;
    			case 2: 	printf("\nRead the Roll No of the student to be searched ?");
    					scanf("%d",&key);
    					if(search(fp, key)) 
					{
    						printf("\nSuccess ! Record found in the file\n");
    						printf("\n%d\t%s\t%d\t%d\t%d\n",s.roll,s.name,s.m1,s.m2,s.m3);
    					} 
					else
					{
    			   			printf("\nFailure!! Record with USN %d not found\n",key);
					}
    					break;
    			case 3: 	exit(0);
    			default:  printf("\nInvalid Option!!! Try again !!!\n");
    		}
		printf("\nDo you want to continue...");
		scanf("\n%c",&ans);
    	}while(ans== 'y');
	fclose(fp);
}
void display(FILE *fp) 
{
    	rewind(fp);
	printf("\nRoll\tName\tM1\tM2\tM3");
	printf("\n--------------------------------------------------------------");
    	while(fread(&s,sizeof(s),1,fp))
	{
		printf("\n%d\t%s\t%d\t%d\t%d\n",s.roll,s.name,s.m1,s.m2,s.m3);
	}
}
int search(FILE *fp, int key) 
{
    	rewind(fp);
    	while(fread(&s,sizeof(s),1,fp))
	{
		if( s.roll == key) 
		{
			return 1;
		}
	}
    		return 0;
}

/****************************   OUTPUT   ************************************
How many Records ? 4

Read the Info for Student: 1 (Roll No,Name,m1,m2,m3) 
21 Naresh 77 66 76   

Read the Info for Student: 2 (Roll No,Name,m1,m2,m3) 
22 Paresh 88 67 69

Read the Info for Student: 3 (Roll No,Name,m1,m2,m3) 
23 Suresh 86 54 77

Read the Info for Student: 4 (Roll No,Name,m1,m2,m3) 
24 Ramesh 77 88 78

	***MENU****
1.Display
2.Search
3.Exit
Enter Your choice1

Student Records in the File 

Roll	Name	M1	M2	M3
--------------------------------------------------------------
21	Naresh	77	66	76

22	Paresh	88	67	69

23	Suresh	86	54	77

24	Ramesh	77	88	78

Do you want to continue...y

	***MENU****
1.Display
2.Search
3.Exit
Enter Your choice2

Read the Roll No of the student to be searched ?23

Success ! Record found in the file

23	Suresh	86	54	77

Do you want to continue...y

	***MENU****
1.Display
2.Search
3.Exit
Enter Your choice3

**********************************************************************/
