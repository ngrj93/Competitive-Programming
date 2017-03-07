/*
ID: ngrj931
PROG: numtri
LANG: C++11
*/

#include<iostream>
#include<fstream>
using namespace std;

int ans=-1,n;
int matrix[1001][1001];
int solution[1001][1001];

void solve(){
	solution[0][0]=matrix[0][0];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<=i;j++){
			if(matrix[i+1][j]+solution[i][j]>solution[i+1][j])
				solution[i+1][j]=solution[i][j]+matrix[i+1][j];
			if(matrix[i+1][j+1]+solution[i][j]>solution[i+1][j+1])
				solution[i+1][j+1]=solution[i][j]+matrix[i+1][j+1];
		}
	}
	for(int i=0;i<n;i++)
		ans=solution[n-1][i]>ans?solution[n-1][i]:ans;
}

int main(){
	ofstream fout("numtri.out");
	ifstream fin("numtri.in");
	fin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			fin>>matrix[i][j];
	solve();
	fout<<ans<<endl;
	return 0;
}
