/*
ID: ngrj931
PROG: frac1 
LANG: C++11
*/

#include<iostream>
#include<set>
#include<fstream>

using namespace std;

int n;
set< pair<double,string> > s;
set<double> check;

void generate_fractions(int den){
	for(int i=0;i<=den;i++){
		double val=(double)i/den;
		if(!check.count(val)){
			check.insert(val);
			s.insert(make_pair(val,to_string(i)+"/"+to_string(den)));
		}
	}
}

int main(){
	ofstream fout("frac1.out");
	ifstream fin("frac1.in");
	fin>>n;
	for(int i=1;i<=n;i++)
		generate_fractions(i);
	for(set< pair<double,string> >::iterator it=s.begin();it!=s.end();it++)
		fout<<it->second<<endl;
	return 0;
}

