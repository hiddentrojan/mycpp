#include <iostream> //package for taking the input and output
#include <stdio.h> // package for operations 
#include <string> // package for taking string values

using namespace std; // used to take cin and cout statement in the program

struct Class{ // structure created to store values of multiple variable and different data types
	int roll_no; // storing roll no. of students
	string name; // storing name of students
	float sgpa; // storing SGPA of students
};

void display(struct Class class_record[], int n) // function created to display using the parameters that are passed
{
	cout<<"\nRollno.\t\tName\t\tSGPA\n"; //Output pattern
	for(int i=0;i<n;i++)// to call out every element according the sequence
	{
		cout<<class_record[i].roll_no<<"\t\t"<<class_record[i].name<<"\t\t"<<class_record[i].sgpa<<"\n"; // values displayed according to the pattern
	}
	
}

void search(struct Class class_record[], int n) // function created to search the SGPA of the students using the parameters that are passed
{
	int flag = 0; // varible created if the value is not found after the for loop gets excuted to displaye the other output
	float s; // variable created to store the value of SGPA that user has to search
	cout<<"\nEnter Your SGPA : "; // asking the user to enter the sgpa
	cin>>s; // storing the value in the variable created
	cout<<"\nRollno.\tName\tSGPA\n";// output pattern
	for(int i=0;i<n;i++) // using linear search patter in the for loop, checking single single element to get the element asked by the user to be searched
	{
		if(class_record[i].sgpa==s) // if element found then it will show the output according to the pattern
		{
			cout<<class_record[i].roll_no<<"\t"<<class_record[i].name<<"\t"<<class_record[i].sgpa<<"\n";
			flag=1;// change the value of flag because element is found and make false the other statement
		}
	}
	if(flag==0) // if flag value is constant after the value, it means element is nt found and this condition should execute
	{
		cout<<"No Record was found with such SGPA. \n";
	}
}


void bsort(struct Class class_record[], int n) // function created for bubble sort using name and paramters that are passed
{
	int i, j; // variables for For loop 
    for (i = 0; i < n-1; i++) // First loop
	{
		for (j = 0; j < n-i-1; j++) //Second loop
		{
		 if (class_record[j].roll_no>class_record[j+1].roll_no) // condition to check if the elements at that postion is greater than other element
		 {
		  //swaping records using temporay structure object
		  struct Class temp = class_record[j]; // int temp = x;
          class_record[j]=class_record[j+1]; // x=y;
          class_record[j+1]=temp; //y=temp;
          }
		}
         
	 }     
}

void bsearch(struct Class class_record[], int n) // Function created for binary search using name and parameters that are passed
{
	bsort(class_record, n); // bubble sort function as being called so that data gets sorted as binary search works on sorted data only
	string t; // variable to store the name that has to be searched by the user
	cout<<"Enter the Name:";//asking the value
	cin>>t;//storing the value in the variable
	int low=0;//variable declared of searching 
	int high=n-1;//variable declared of searching
	int si=-1; // variable to store startindex
	while (low<=high) // to check if low is smaller than or equal to high
	{
		int mid=(low+high)/2; // divide the elements to search 
		if(class_record[mid].name>t) 
		{
			high = mid-1;
		}
		else if(class_record[mid].name==t) // if the element is found then set the startindex position to mid
		{
			si=mid;
			high= mid-1;
		}
		else // if not found than change the value of low
		{
			low=mid+1;
		}
	}
	
	int ei=-1; // variable to declared to store endindex
	low=0;
	high=n-1;
	while(low<=high)// to check if low is smaller than or equal to high
	{
		int mid=(low+high)/2;// divide the elements to search 
		if(class_record[mid].name>t)
		{
			high=mid-1;
		}
		else if(class_record[mid].name==t)// if the element is found then set the endindex position to mid
		{
			ei=mid;
			low=mid+1;
		}
		else// if not found than change the value of low
		{
			low=mid+1;
		}
	}
	if(si!=-1 && ei!=-1) // checking if si and ei are equal to -1 to display the elements
	{
		cout<<"\nRollNo\t\tName\t\tSGPA\n"; // output pattern
		for(int i=si;i<=ei;i++) // loop to display elements from startindex to endindex
		{
			cout<<class_record[i].roll_no<<"\t\t"<<class_record[i].name<<"\t\t"<<class_record[i].sgpa<<"\n";
		}
	}
}

void isort(struct Class class_record[], int n) // function created for insertion sort for roll no using parameters that are passed 
{
	int i, j; // variable declared for looping
	for(i=1;i<n;i++) // loop for insertion sorting
	{
		struct Class temp= class_record[i]; // created to swap record, a temporary structure
		j = i-1;
		while(j>=0 && temp.name<class_record[j].name)
		{
			class_record[j+1]=class_record[j]; // records get swap
			j--;
		}
		class_record[j+1]=temp; // swap with temporary object of struct Class
	}
}

void qdisplay(struct Class class_record[], int n) // function created for displaying after quick sorting is done
{
	cout<<"\nRollno.\t\tName\t\tSGPA\n"; // output pattern
	for(int i=n-1;i>4;i--) // displaying top 10 using for loop
	{
	 cout<<class_record[i].roll_no<<"\t\t"<<class_record[i].name<<"\t\t"<<class_record[i].sgpa<<"\n";
	}
}


void qsort(struct Class class_record[], int h, int l) // function for quick sorting
// h is for high which is number of elements and l is low which is zero
{

	struct Class temp; // temporary Struct for swapping purpose
		
	if(l<h) // run until the condition gets false
	{
	 int p= l; // pivot
	 int tbi = l+1; // toobigindex
	 int tsi = h; // toosmallindex
	 while(tsi>tbi)
	{
	 while(class_record[tbi].sgpa<=class_record[p].sgpa)
	 {
		++tbi;
	 }
	 
	 while(class_record[tsi].sgpa>class_record[p].sgpa)
	 {
		--tsi;
	 }
	
	 if(tbi<tsi) // swapping records with toobigindex and toosmallindex
	 {
		temp=class_record[tbi];
		class_record[tbi]=class_record[tsi];
		class_record[tsi]=temp;
	 }
	}
	// swaping records with pivot 
	temp=class_record[tsi];
	class_record[tsi]=class_record[p];
	class_record[p]=temp;
	//recursive function calling
	qsort(class_record, tsi-1, p);
	qsort(class_record, h, tsi+1);
	}
}

int main()
{
	int elements; // Variable declared for storing number of records
	cout<<"Enter the Number of Records to be entered : ";
	cin>>elements;// Number of records are taken from the user to be stored
	struct Class class_record[elements]; // Structure object in array form is being created here
	int i, c; // Here i is used for For loop condition and c is for storing value of the choice for the Switch Case
	
	do
	{ 
		cout<<"\n1]GetData\n2]Display\n3]Linear Search\n4]Bubble Sorted\n5]Binary Search\n6]Insertion Sort\n7]Quick Sort\n8]Exit\nEnter Your Choice : "; // Menu for the user to choose one option to do
	    cin>>c;// Choice of user has being stored in this varible 
		switch(c) // checking the case according to users choice
		{
			case 1:
				cout<<"Enter the Roll no. , Name, SGPA : \n"; // Pattern of taking in the value from the user
				for(i=0;i<elements;i++) // Used for loop for taking multiple values given by the user in the first statement of the program
				{
					cin>>class_record[i].roll_no>>class_record[i].name>>class_record[i].sgpa; // Getting values according to the pattern given above
				}
				break;// take out of the switch one's the process of this particular case has being completed
			case 2:
				display(class_record, elements); // calling out display function and passing parameters to the function
				break;// take out of the switch ones the process of this particular case has being completed
			case 3:
				search(class_record, elements);// calling out search function and passing parameters to the function
				break;// take out of the switch ones the process of this particular case has being completed
			case 4:
				bsort(class_record, elements);// calling out bsort function and passing parameters to the function
				display(class_record, elements);// calling out display function and passing parameters to the function
				break;// take out of the switch ones the process of this particular case has being completed
			case 5:
				bsearch(class_record, elements);// calling out display function and passing parameters to the function
				break;// take out of the switch ones the process of this particular case has being completed
			case 6:
				isort(class_record, elements);// calling out isort function and passing parameters to the function
				display(class_record, elements);// calling out display function and passing parameters to the function
				break;// take out of the switch ones the process of this particular case has being completed
			case 7:
				qsort(class_record, elements-1, 0);// calling out qsort function and passing parameters to the function
				qdisplay(class_record, elements);// calling out display function and passing parameters to the function
				break;// take out of the switch ones the process of this particular case has being completed
			case 8: exit; // exiting the program
			    break;// take out of the switch ones the process of this particular case has being completed
			default : cout<<"Wrong Choice"; // if user choose's another case than displayed in the menu
				
		} // closing switch case
	}while(c!=8); // condition to check if the choice is not equal to 8 and run the do loop if the condition is true until it gets false
    return 0; // used for the functions that have being called in the switch case
} // closing of the main
