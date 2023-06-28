#include <iostream>

using namespace std;

int main()
{  int n=200001,i,j;
   bool A[n];

   for (i=0;i<n;i++) A[i]=true;

   A[0]=A[1]=false;

   for(i=2;i*i<n;i++)
    if (A[i]==true)
   {
       j=2;
       while(i*j<n)
       {A[i*j]=false;
        j++;}
   }

   j=0;
   for(i=0;i<n-8 and j<3;i++)
    if(A[i]==true)
        if(A[i+2]==true and A[i+6]==true and A[i+8]==true)
            {cout<<i<<" "<<i+2<<" "<<i+6<<" "<<i+8<<endl;
                j++;}
    return 0;
}
