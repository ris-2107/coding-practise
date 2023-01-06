//PLPROCESS

#include <bits/stdc++.h>
//#define int long long
using namespace std;


int32_t main (){

	freopen ("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t ;
	cin >> t;
	while(t--){
		int n;
		cin>> n;
    int ans=0, sum=0, pref=0;
    int a[n];
    for(int i=0; i<n; i++){
    	cin >> a[i];
    	sum += a[i];
    }
    ans=sum;

    for(int i=0; i<n ; i++){
    	pref+= a[i];
    	int rem =sum-pref;
    	int req_time= max(rem, pref);
    	ans=min(ans, req_time);
    }
    cout << ans << '\n';
	}
	return 0;
    
}