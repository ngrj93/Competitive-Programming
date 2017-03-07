/*
ID: ngrj931
PROG: holstein
LANG: C++11
*/

#include<iostream>
#include<fstream>

using namespace std;

int v,g;
int vitamin[25],feed[15][25],sum[25],ans[15];
ofstream fout("holstein.out");

bool check_combination(int length){
	for(int i=0;i<v;i++){
		if(sum[i]<vitamin[i])
			return false;
	}
	string str="";
	for(int i=0;i<=length;i++)
		str+=to_string(ans[i]+1)+" ";
	str=str.substr(0,str.length()-1);
	fout<<length+1<<" "<<str<<endl;
	return true;
}

bool generate_combinations(int length,int cur,int index,int boundary){
	if(cur>length)
		return check_combination(length);
	else{
		for(int i=index;i<boundary;i++){
			ans[cur]=i;
			for(int j=0;j<v;j++)
				sum[j]+=feed[i][j];
			if(generate_combinations(length,cur+1,i+1,boundary+1))
				return true;
			for(int j=0;j<v;j++)
				sum[j]-=feed[i][j];
			ans[cur]=0;
		}
		return false;
	}
}
			

int main(){
	ifstream fin("holstein.in");
	fin>>v;
	for(int i=0;i<v;i++)
		fin>>vitamin[i];
	fin>>g;
	for(int i=0;i<g;i++)
		for(int j=0;j<v;j++)
			fin>>feed[i][j];
	for(int i=0;i<g;i++){
		if(generate_combinations(i,0,0,g-i))
			break;
	}
	return 0;
}
