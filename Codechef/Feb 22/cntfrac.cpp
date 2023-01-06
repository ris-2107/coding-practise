//CNTFRAC :- Codechef





#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
     if(b==0)
     return a;
     return gcd(b,a%b);
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	      int n;
	      cin>>n;
	      int f[n+1][n+1];
	      memset(f,0,sizeof f);
	      for(int i=1;i<=n;i++)
	      {
	                     for(int j=1;j<=n;j++)
	                     {
	                                    int g=gcd(i,j);
	                                     int x=i/g;
	                                     int y=j/g;
	                                     f[x%y][y]++;
	                                     
	                     }
	      }
	      long long ans=0;
	      for(int d=1;d<=n;d++)
	      {
	            for(int i=0;i<d;i++)
	            {
	                 ans+=f[i][d]*f[(d-i)%d][d];
	            }
	      }
	      cout<<ans<<endl;
	}
	return 0;
}
