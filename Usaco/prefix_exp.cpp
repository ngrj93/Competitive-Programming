/*
ID: ngrj931
PROG: prefix
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<set>

using namespace std;

set<string> primitives;
string seq;
int largest;

int largest_prefix(int lindex,int length){
	if(lindex+length>seq.length()||length>largest)
		return lindex;
	string temp=seq.substr(lindex,length);
	if(!primitives.count(temp))
		return largest_prefix(lindex,length+1);
	else
		return max(largest_prefix(lindex+length,1),largest_prefix(lindex,length+1));
}
	
int main(){
	ofstream fout("prefix.out");
	ifstream fin("prefix.in");
	string input;
	fin>>input;
	while(input!="."){
		largest=largest>input.length()?largest:input.length();
		primitives.insert(input);	
		fin>>input;
	}
	fin>>input;
	while(!fin.eof()){
		seq+=input;
		fin>>input;
	}
	fout<<largest_prefix(0,1)<<endl;
	return 0;
}

