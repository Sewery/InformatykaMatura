#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define Y second
#define X first
using namespace std;
const char* test="./DANE/przyklad.txt";
const char* zad="./DANE/liczby.txt";
const int D1=11 ;
const int D2=100 ;
ofstream output("wyniki4.txt",ios_base::app);
ifstream input(zad);
vector<string> vec;
vector<int> vec2;
map<int,int> maper;
const int MAX=(20e5)+1;
int isprime[MAX]={};
void sieve()
{
	for(int i=2;i<sqrt(MAX);i++)
	{
		if(isprime[i]==0)
		{
			for(int k=i*i;k<MAX-1;k+=i)
			{
				isprime[k]=1;
			}
		}
	}	
}
void zad4_1()
{
	vector<int> vec3;
	for(string st:vec)
	{
		reverse(st.begin(),st.end());
		if(stoi(st)%17==0)
			vec3.pb(stoi(st));
	}
	output<<"zad4.1\n";
	for(auto k:vec3)
		output<<k<<"\n";
}
void zad4_2()
{
	int maxer=0;
	int  liczba=0;
	for(string st:vec)
	{
		int a=stoi(st);
		reverse(st.begin(),st.end());
		int b=stoi(st);
		if(abs(a-b)>maxer)
		{
			maxer=abs(a-b);
			liczba=a;
		}
		
	}
	output<<"zad4.2\n"<<liczba<<" "<<maxer<<"\n";
}
void zad4_3()
{
	vector<int> liczby;
	for(string st:vec)
	{
		int a=stoi(st);
		reverse(st.begin(),st.end());
		int b=stoi(st);
		if(isprime[a]==0 && isprime[b]==0)
		{
			liczby.pb(a);
		}
		
	}

	output<<"zad4.3\n";
	for(auto w: liczby)
		output<<w<<'\n';

}
void zad4_4()
{
	int x=0,y=0,z=0;
	auto it=maper.begin();
	while(it!=maper.end())
	{
		x++;
		if(it->Y==2)
			y++;
		if(it->Y==3)
			z++;
		it++;
	}
	output<<"zad4.4\n"<<x<<" "<<y<<" "<<z<<"\n";

}

int main()
{
	sieve();
	for(int i=0;i<D2;i++)
	{
		string a;
		input>>a;
		vec.pb(a);
		int b= stoi(a);
		vec2.pb(b);
		maper[b]++;
	}
	zad4_1();
	zad4_2();
	zad4_3();
	zad4_4();
	return 0;
}