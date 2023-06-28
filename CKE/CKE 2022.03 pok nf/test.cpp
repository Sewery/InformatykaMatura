

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
constexpr int LICZBA_PLANSZ=125;
int s,n;
void tura(vector<int> &A,vector<bool> &B,int k)
{
	for(int i=s;i>=A[k];i--)
	{
		if(B[i-A[k]] && !B[i])
			B[i]=1;
	}
}
int main()
{	cin>>s>>n;
	vector<int> A(n+1,0);
	vector<bool> B(n+1,0);
	for(int i=1;i<=n;i++)
	{
		int r;
		cin>>r;A[i]=r;
	}
     B[0]=1;
	for(int k=1;k<=n;k++)
	{
		tura(A,B,k);
	}
	
	cout<<B[s];
	return 0;
}