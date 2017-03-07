/*
ID: ngrj931
PROG: fracdec
LANG: C++11
*/

#include<iostream>
#include<fstream>

using namespace std;

ofstream fout("fracdec.out");
ifstream fin("fracdec.in");
int visited[1000000];
int n,d;

void solve(){
	string ans="";
	int quotient=n/d;
	int rem=n%d;
	ans=to_string(quotient)+'.';
	rem*=10;
	bool flag=true;
	while(rem!=0 && visited[rem]==0){
		flag=false;
		visited[rem]=ans.size();
		quotient=rem/d;
		rem=rem%d;
		rem*=10;
		ans+=to_string(quotient);
	}
	if(flag)
		ans+='0';
	else if(rem!=0)
		ans=ans.substr(0,visited[rem])+'('+ans.substr(visited[rem])+')';
	for(int i=0,j=0;i<ans.size();i++,j++){
		if(j==76){
			fout<<endl;
			j=0;
		}
		fout<<ans[i];
	}
	fout<<endl;
}	

int main(){
	fin>>n>>d;
	solve();
	return 0;
}
	
