#include<iostream>

using namespace std;

class g
{
	public :
		int s, d, w;
		void accept();
		void display();
		void sort(g *[], int);
		int fp(int, int *);
		g *k(g *[], int);
};

void g::accept()
{
	cout<<"\nEnter source vertex : ";
	cin>>s;
	cout<<"\nEnter destination vertex : ";
	cin>>d;
	cout<<"\nEnter weight of the edge : ";
	cin>>w;
	
}
void g::sort(g *a[], int n)
{
	g *temp[n];
	int i, j;
    for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++) 
		{
		 if (a[j]>a[j+1]) 
		 {
		  temp[i]=a[j]; // int temp = x;
          a[j]=a[j+1]; // x=y;
          a[j+1]=temp[i]; //y=temp;
          
          }
		}
         
	 }
}

g *g::k(g *edge[], int v)
{
	int i, c = 0, p = 0;
	int *parent = new int[v];
	for(i=0;i<v;i++)
	{
		parent[i]=i;
	}
	cout<<"\nMinimum Spanning Tree : \nSourc\t\tDestination\t\tWeight\n";
	while(c!=(v-1))
	{
		int s = fp(edge[p]->s, parent);
		int d = fp(edge[p]->d, parent);
		if(s!=d)
		{
			cout<<"\n"<<edge[p]->s<<"\t\t"<<edge[p]->d<<"\t\t"<<edge[p]->w;
			parent[s]=d;
			c++;
		}
		p++;
	}
}
