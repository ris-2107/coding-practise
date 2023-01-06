#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int>array={1,2,3};
	vector<int>temp;
	vector<int>temp1;
	vector<vector<int>> subsets;
	subsets.push_back({} );

	for(int ele:array){
		for(int i=0;i<subsets.size();i++){
			temp=subsets[i];
			temp1.push_back(ele);
			auto temp2=temp.push_back(temp1);
			subsets.push_back(temp2);
			
			temp1.clear();
		}
		for (int i = 0; i < temp.size(); ++i)
		{
			/* code */
			cout<< temp [i];
		}
		cout << endl;
		//temp.clear();
	}
	
	
	 }