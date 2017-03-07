#include<bits/stdc++.h>

using namespace std;
string a,b;

int minimum_distance(int i, int j){
	if(i==0)
		return j+1;
	else if(j==0)
		return i+1;
	else if(a[i]==b[j])
		return minimum_distance(i-1,j-1);
	else
		return 1+min(minimum_distance(i,j-1),min(minimum_distance(i-1,j),minimum_distance(i-1,j-1)));
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<minimum_distance(a.size()-1,b.size()-1);
	}
	return 0;
}
