/*


				          PROBLEM STATEMENT:
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she 
manages to save some money out of it daily. After buying vegetables, she goes to 
"Momos Market", where there are ‘n’ number of shops of momos. Each of the shop of
momos has a rate per momo. She visits the market and starts buying momos (one from 
each shop) starting from the first shop. She will visit the market for ‘q’ days.
You have to tell that how many momos she can buy at each day if she starts buying 
from the first shop daily. She cannot use the remaining money of one day on some other 
day. But she will save them for other expenses in future, so, 
you also need to tell the sum of money left with her at the end of each day.
*/


// Input Format:
// First line will have an integer ‘n’ denoting the number of shops in market.
// Next line will have ‘n’ numbers denoting the price of one momo of each shop.
// Next line will have an integer ‘q’ denoting the number of days she will visit the market.
// Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.

// Constraints:
// 1 <= n <= 10^5
// 1 <= q <= 10^5
// 1 <= X <= 10^9

// Output:
// There will be ‘q’ lines of output each having two space separated integers denoting 
// number of momos she can buy and amount of money she saved each day.

// Sample Input:
// 4
// 2 1 6 3
// 1
// 11

// Sample Output:
// 3 2









	             //This Code gives TLE for only 1 test case:

	
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void momos(vector<ll> a,ll n,vector<ll> b,ll q)
{
    ll p=q,j=0;
    while(p--&&j<q)
    {
        ll moneyForDay=b[j],moneyLeft,count=0;
        for(ll i=0;i<n;i++)
    	{
            if(moneyForDay<a[i])
            {
               
                moneyLeft=moneyForDay;
                 break;
            }
        	moneyForDay=moneyForDay-a[i];
            count++;
   		}
        cout<<count<<" "<<moneyLeft<<endl;;
        j++;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    ll n;
    vector<ll> a,b;
    cin>>n;
    ll m=n;
	while(m--)
    {
        ll input;
        cin>>input;
        a.push_back(input);
    }
    ll q;
    cin>>q;
    ll p=q;
    while(p--)
    {
        ll days;
        cin>>days;
        b.push_back(days);
    }
    
    momos(a,n,b,q);
	return 0;
}