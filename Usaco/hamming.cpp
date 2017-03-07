/*
ID: ngrj931
PROG: hamming
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream fin("hamming.in");
ofstream fout("hamming.out");
int n,b,d;

int main(){
	fin>>n>>b>>d;
	int count=0;
	vector<int> ans;
	for(int i=0;i<256;i++){
		bool flag=true;
		for(int j=0;j<ans.size();j++){
			int val=ans[j]^i,temp=0;
			int shift=0;
			while(shift<b){
				if(val&(1<<shift))
					temp++;
				shift++;
			}
			if(temp<d){
				flag=false;
				break;
			}
		}
		if(flag){
			count++;
			ans.push_back(i);
		}
		if(count==n)
			break;
	}
	string str="";
	for(int i=0;i<ans.size();i++){
		if((!(i%10) && i!=0)){
			str=str.substr(0,str.length()-1);
			fout<<str<<endl;
			str="";
		}
		str+=to_string(ans[i])+" ";
		if(i+1==ans.size()){
			str=str.substr(0,str.length()-1);
			fout<<str<<endl;
			str="";
		}
	}
	return 0;
}
