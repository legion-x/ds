#include<stdio.h>
int main()
{
	int a[5],b[5],c[10],i,m=0,ch,f=0,j;
	int k=0;
	int q;
	printf("\nenter the elements of a\n");
	for(i=0;i<5;i++)
	{	printf("enter the element[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("\nenter the element of b\n");
	for(i=0;i<5;i++)
	{	printf("enter the element[%d]:",i);
		scanf("%d",&b[i]);
	}
	do
	{
	printf("enter the choice\n1.AUB\n2.A intersection of B\n3.A-B\n4.B-A\n5.Symmetric \n6.assymetric\n7.exit:\n");
	scanf("%d",&ch);
	
	
	switch(ch)
	{
		case 1: 
			printf("the union elements are\n");
			for(i=0;i<5;i++)
			{	
				c[k]=a[i];k++;
			}
			for(i=0;i<5;i++)
			{	f=0;
			for(j=0;j<5;j++)
			{
			if(a[j]==b[i])
			{	f=0;
				break;
			}
			else 
				f=1;					
					
			}
			if(f==1)
			{	
				c[k]=b[i];
				k++;
			
			}
			}
			m=k;
				
			for(k=0;k<m;k++)
			{
				printf("%d,",c[k]);
			}			
				break;
		case 2:
			printf("Intersection of elements are");
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
			if(a[i]==b[j])
			{
				f=b[j];
				printf("%d,",f);
				
			}
			}
		}
				break;
	case 3:
		printf("difference of element:");
		
		for(i=0;i<5;i++)
		{f=1;
			for(j=0;j<5;j++)
			{
				if(a[i]==b[j])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				printf(",%d",a[i]);
			}
			
		}	
				break;
	case 4:
		printf("difference of element:");
		for(i=0;i<5;i++)
		{f=1;
			for(j=0;j<5;j++)
			{
				if(b[i]==a[j])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				printf("%d",b[i]);
			}
		}
	case 5:
		printf("symmetric of sets are:");
		for(i=0;i<5;i++)
		{f=1;
			for(j=0;j<5;j++)
			{
				if(a[i]==b[j])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				c[k++]=a[i];
			}
		}
		for(i=0;i<5;i++)
		{f=1;
			for(j=0;j<5;j++)
			{
				if(b[i]==a[j])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				c[k++]=b[i];
			}
		}
		m=k;	
		for(i=0;i<m;i++)
		{
			printf("%d,",c[i]);
		}
			break;
	case 6:
		printf("asymmetric difference of sets are");
		printf("enter the total numbers of student:");
		scanf("%d",&m);
		printf("enter the total player");
		scanf("%d",&f);
		printf("%d",m-f-1); 
		break;
	case 7:
		exit(0);
		break;
	default:
		printf("invlaid choice!!!!!!!!");	
			
	}
	printf("\nwant to continue:(1=yes/0=no)\n");
	scanf("%d",&q);
	}while(q==1);

	
	return 0;		
}
/********************************Output*************************
enter the elements of a
enter the element[0]:1
enter the element[1]:2
enter the element[2]:3
enter the element[3]:4
enter the element[4]:5

enter the element of b
enter the element[0]:5
enter the element[1]:6
enter the element[2]:2
enter the element[3]:3
enter the element[4]:9
enter the choice
1.AUB
2.A intersection of B
3.A-B
4.B-A
5.Symmetric 
6.assymetric
7.exit:
1
the union elements are
1,2,3,4,5,6,9,
want to continue:(1=yes/0=no)
1
enter the choice
1.AUB
2.A intersection of B
3.A-B
4.B-A
5.Symmetric 
6.assymetric
7.exit:
2
Intersection of elements are2,3,5,
want to continue:(1=yes/0=no)
1
enter the choice
1.AUB
2.A intersection of B
3.A-B
4.B-A
5.Symmetric 
6.assymetric
7.exit:
3
difference of element:,1,4
want to continue:(1=yes/0=no)
1
enter the choice
1.AUB
2.A intersection of B
3.A-B
4.B-A
5.Symmetric 
6.assymetric
7.exit:
4
difference of element:69symmetric of sets are:1,2,3,4,5,6,9,1,4,6,9,
want to continue:(1=yes/0=no)
1
enter the choice
1.AUB
2.A intersection of B
3.A-B
4.B-A
5.Symmetric 
6.assymetric
7.exit:
5
symmetric of sets are:1,2,3,4,5,6,9,1,4,6,9,1,4,6,9,
want to continue:(1=yes/0=no)
1
enter the choice
1.AUB
2.A intersection of B
3.A-B
4.B-A
5.Symmetric 
6.assymetric
7.exit:
6
asymmetric difference of sets areenter the total numbers of student:5
enter the total player3
1
want to continue:(1=yes/0=no)
1
enter the choice
1.AUB
2.A intersection of B
3.A-B
4.B-A
5.Symmetric 
6.assymetric
7.exit:
7
*/



		


