#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> input;
	int temp;
	while(cin>>temp)
		input.push_back(temp);
	vector<int> result;
	for(int i=0;i<input.size();i++){
		int pos=binary_search(input,result,input[i]);
		if(pos==i)
			result[i]=

