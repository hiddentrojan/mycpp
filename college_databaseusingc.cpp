#include<stdio.h>
#include<stdlib.h>

struct student
{
	char name[10];
	int age;
}v[10];

void getdata(int i)
{
	printf("\nEnter The Name : ");
	scanf("%s", v[i].name);
	printf("\nEnter The Age. :");
	scanf("%d", &v[i].age); 
}

void display(int i)
{

	printf("\n%s", v[i].name);
	printf("\t\t%d", v[i].age);
}

int main()
{
	int rec, i, c, mod, search, del;
	
	printf("Number of Records to be Entered : ");
	scanf("%d", &rec);
	
	for(i=0;i<rec;i++)
	{
		getdata(i);
	}
	
	printf("\nName\t\tAge\n");	
	for(i=0;i<rec;i++)
	{
		display(i);
	}
	
	do
	{
		printf("\n1]Modify Data of a Student\n2]Search a Student\n3]Delete A Data of A Student\n4]Add A Student Data\n5]Exit\n Enter Your Choice :  ");
		scanf("%d", &c);
		
		switch(c)
		{
			case 1:
				printf("Enter the student no. to be Modify : ");
				scanf("%d", &mod);
				getdata(mod-1);
				for(i=0;i<rec;i++)
				{
					display(i);
				}
				break;
			case 2:
				printf("Enter the student no. to be search : ");
				scanf("%d", &search);
				display(search-1);
				break;
			case 3:
				printf("Enter the student no. to be deleted : ");
				scanf("%d", &del);
				for(i=del;i<rec;i++)
				{
					v[i-1]=v[i];
				}
				
				for(i=0;i<rec;i++)
				{
					display(i);
				}
				break;
			case 4:
				rec=rec+1;
				getdata(rec-1);
				for(i=0;i<rec;i++)
				{
					display(i);
				}
				break;
			case 5:exit(0);
				break;
		}
	}while(c>0);
	return 0;
}
