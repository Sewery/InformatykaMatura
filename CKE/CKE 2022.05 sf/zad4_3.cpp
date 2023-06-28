#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
#define X first
#define Y second
#define pb push_back
#define ll long long
ifstream input("./Dane_2205/liczby.txt");
ofstream output("wyniki4.txt",ios_base::app);
ofstream output2("trojki.txt",ios_base::app);
vector<int> liczby;
int counter_trojka=0;
int counter_piatka=0;
//od 10 do 10^5
const int MAXER=10e5 +2;
bool arr[MAXER]={};
bool visited[MAXER]={};
ll prep[201][6]={};
int counter=0;

ll duwm_new(ll n, ll k)
{
	if(k==0 || n==k)	
		return prep[n][k]=1;;
	return  prep[n][k]=(prep[n-1][k-1]==0?duwm_new(n-1,k-1):prep[n-1][k-1]) +(prep[n-1][k]==0?duwm_new(n-1,k):prep[n-1][k]);
}
void func(ll x,int k)
{
	bool bylo_robione=false;
	for(ll i=2;i<=(ll)pow(10,5);i++)
	{	
		
		if(x*i>=MAXER)
			break;
		if(arr[(x*i)]==1 && visited[(x*i)]==0)
		{	visited[(x*i)]=1;
			func(x*i,k+1);
		}else if(!bylo_robione)
		{
			if(k>=5)
			{
				counter_piatka+= prep[k][5];
			}
			bylo_robione=true;
		}
	}
}
void pre()
{
	for(int i=5;i<=50;i++)
	{
		prep[i][5]=duwm_new(i,5);
	}
}
int main()
{
	
	output<<"zad 4.3\n";
	vector<int> vec_trojek;
	pre();
	memset(arr,0,sizeof arr);
	vector<int> vec;
	for(int i=0;i<200;i++)
	{
		int x;
		input>>x;
		arr[x]=1;	
		vec.pb(x);	
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<200;i++)
	{
		for(int j=i+1;j<200;j++)
			for(int k=j+1;k<200;k++)
			{
				int a=vec[i],b=vec[j],c=vec[k];
				if(gcd(a,b)==a && gcd(b,c)==b && a!=b && b!=c)
				{
					vec_trojek.pb(a);vec_trojek.pb(b);vec_trojek.pb(c);
					counter_trojka++;
				}
				
			}
	}
	func(1,0);
	output<<"a) "<<counter_trojka<<"\nb) "<<counter_piatka<<'\n';
	for(int i=0;i<vec_trojek.size();i++)
	{
		if(i%3==0 &&i>0)
			output2<<'\n';
		output2<<vec_trojek[i]<<" ";
	}
	return 0;
}