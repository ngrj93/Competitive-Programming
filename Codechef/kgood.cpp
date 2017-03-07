#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int minDeletion(int arr[],int i,int j,int k){
	if(abs(arr[i]-arr[j])<=k)
		return 0;
	int min=arr[j]-(arr[i]+k);
	if(i!=j-1)
		min+=minDeletion(arr,i,j-1,k);
	int min1=arr[i];
	if(min1<min && i+1!=j)
		min1+=minDeletion(arr,i+1,j,k);
	min=min1<min?min1:min;
	return min;
}
	
int main(){
	int t,k;
	cin>>t;
	while(t--){
		cin.ignore();
		string s;
		cin>>s>>k;
		int frequency[26]={0},count=0;
		for(int i=0;i<s.length();i++)
			frequency[s[i]-97]++;
		sort(frequency,frequency+26);
		for(int i=0;i<26;i++){
			if(frequency[i]!=0)
				break;
			count++;
		}
		cout<<minDeletion(frequency,count,25,k)<<endl;
	}
	return 0;
}
