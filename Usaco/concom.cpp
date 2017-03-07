/*
ID: ngrj931
PROG: concom
LANG: C++11
*/

#include<iostream>
#include<fstream>

using namespace std;

ofstream fout("concom.out");
ifstream fin("concom.in");
int n;
int company[101][101];
bool visited[101][101];

void solve(){
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(i!=j && !visited[i][j] && company[i][j]>50){
				visited[i][j]=true;
				for(int k=1;k<=100;k++){
					if(company[i][k]<51)
						company[i][k]+=company[j][k];
				}
				j=0;
			}
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(visited[i][j])
				fout<<i<<" "<<j<<endl;
		}
	}
}

int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		fin>>a>>b>>c;
		company[a][b]=c;
	}
	solve();
	return 0;
}
