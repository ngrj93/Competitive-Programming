#include<iostream>
#include<cmath>
using namespace std;

string a,b;

int min_deletions(){
	int freq1[26]={0},freq2[26]={0};
	for(int i=0;i<a.length();i++)
		freq1[a[i]-97]++;
	for(int i=0;i<b.length();i++)
		freq2[b[i]-97]++;
	int ans=0;
	for(int i=0;i<26;i++)
		ans+=abs(freq1[i]-freq2[i]);
	return ans;
}

int main(){
	cin>>a>>b;
	cout<<min_deletions()<<endl;
	return 0;
}
