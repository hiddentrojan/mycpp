#include<iostream>

using namespace std;

int main()
{
	int T, D, N, K, i=0, j=0;
	int h[1000], s[1000], e[1000];

	do
	{
		cin>>T;
	}while(T<1 || T>100);
	do
	{
		do
		{
			cin>>D>>N>>K;
		}while((D<1 || D>1000) || (N<1 || N>1000) || (K<1 || K>N));
		do
		{
			cin>>h[j]>>s[j]>>e[j];
			if((1>s[j] || (s[j]>e[j]) || (1>e[j]) || (s[j]>D) || (e[j]>D)) || (1>h[j]))
			 cout<<"\nTrue\n";
			else
			 cout<<"\nFalse \n";
			 j++;
		}while(j<N);
	}while(i<T);
}
