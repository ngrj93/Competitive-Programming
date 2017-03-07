/*
ID: ngrj931
PROB: milk3
LANG: C++11
*/

#include<fstream>
#include<iostream>

using namespace std;

ofstream fout("milk3.out");
int max_capacity[3];
int bucket[3],total;
bool state[21][21][21];
bool ans[21];

void recurse_solve(int a,int b,int c){
	state[a][b][c]=true;
	if(a==0)
		ans[c]=true;
	if(a!=0){
		int pour=max_capacity[1]-b>=a?a:max_capacity[1]-b;
		if(state[a-pour][b+pour][c]==false)
			recurse_solve(a-pour,b+pour,c);
		pour=max_capacity[2]-c>=a?a:max_capacity[2]-c;
		if(state[a-pour][b][c+pour]==false)
			recurse_solve(a-pour,b,c+pour);
	}
	if(b!=0){
		int pour=max_capacity[0]-a>=b?b:max_capacity[0]-a;
		if(state[a+pour][b-pour][c]==false)
			recurse_solve(a+pour,b-pour,c);
		pour=max_capacity[2]-c>=b?b:max_capacity[2]-c;
		if(state[a][b-pour][c+pour]==false)
			recurse_solve(a,b-pour,c+pour);
	}
	if(c!=0){
		int pour=max_capacity[1]-b>=c?c:max_capacity[1]-b;
		if(state[a][b+pour][c-pour]==false)
			recurse_solve(a,b+pour,c-pour);
		pour=max_capacity[0]-a>=c?c:max_capacity[0]-a;
		if(state[a+pour][b][c-pour]==false)
			recurse_solve(a+pour,b,c-pour);
	}
}

int main(){
	ifstream fin("milk3.in");
	fin>>max_capacity[0]>>max_capacity[1]>>max_capacity[2];
	recurse_solve(0,0,max_capacity[2]);
	string str="";
	for(int i=0;i<21;i++){
		if(ans[i])
			str=str+to_string(i)+" ";
	}
	str=str.substr(0,str.length()-1);
	fout<<str<<endl;
	return 0;
}
