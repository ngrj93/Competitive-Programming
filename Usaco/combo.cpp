/*
ID: ngrj931
PROG: combo
LANG: C++11
*/

#include<fstream>
#include<iostream>
#include<set>
using namespace std;

int n;

int modulus_calc(int val,int diff){
	if(n<diff)
		return val;
	if(val+diff<0)
		return n+val+diff;
	else if(val+diff>=n)
		return val+diff-n;
	else
		return val+diff;
}

int main(){
	ofstream fout("combo.out");
	ifstream fin("combo.in");
	fin>>n;
	set<string> s;
	int combination1[3],combination2[3];
	for(int i=0;i<3;i++){
		fin>>combination1[i];
		combination1[i]--;
	}
	for(int i=0;i<3;i++){
		fin>>combination2[i];
		combination2[i]--;
	}
	int lefti=modulus_calc(combination1[0],-2),leftj=modulus_calc(combination1[1],-2),leftk=modulus_calc(combination1[2],-2);
	int total=n>5?5:n,counti=total,i=lefti;
	while(counti--){
		int countj=total,j=leftj;
		while(countj--){
			int countk=total,k=leftk;
			while(countk--){
				string str=to_string(i)+","+to_string(j)+","+to_string(k);
				s.insert(str);
				k=(k+1)%n;
			}
			j=(j+1)%n;
		}
		i=(i+1)%n;
	}
	lefti=modulus_calc(combination2[0],-2),leftj=modulus_calc(combination2[1],-2),leftk=modulus_calc(combination2[2],-2);
	counti=total,i=lefti;
	while(counti--){
		int countj=total,j=leftj;
		while(countj--){
			int countk=total,k=leftk;
			while(countk--){
				string str=to_string(i)+","+to_string(j)+","+to_string(k);
				s.insert(str);
				k=(k+1)%n;
			}
			j=(j+1)%n;
		}
		i=(i+1)%n;
	}
	fout<<s.size()<<endl;
	return 0;
}
