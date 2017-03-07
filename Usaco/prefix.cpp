/*
ID: ngrj931
PROG: prefix
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<string> primitives;
string seq;
bool visited[200001];

int largest_prefix(){
	for(int i=0;i<seq.length();i++){
		if(i!=0 && !visited[i])
			continue;
		for(int j=0;j<primitives.size();j++){
			if(i+primitives[j].length()<=seq.length() && seq.substr(i,primitives[j].length())==primitives[j]){
				visited[i+primitives[j].length()]=true;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=seq.length();i++){
		if(visited[i])
			ans=i;
	}
	return ans;
}

int main(){
	ofstream fout("prefix.out");
	ifstream fin("prefix.in");
	string input;
	fin>>input;
	while(input!="."){
		primitives.push_back(input);
		fin>>input;
	}
	fin>>input;
	while(!fin.eof()){
		seq+=input;
		fin>>input;
	}
	fout<<largest_prefix()<<endl;
	return 0;
}

