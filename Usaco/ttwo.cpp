/*
ID: ngrj931
PROG: ttwo
LANG: C++11
*/

#include<fstream>
#define MAX 10000000
using namespace std;

ofstream fout("ttwo.out");
ifstream fin("ttwo.in");
char grid[10][10];
int coord[2][2],direction[2];
int x[]={-1,0,1,0};
int y[]={0,1,0,-1};

bool ok(int x,int y){
	if(x>=0 && x<10 && y>=0 && y<10 && grid[x][y]!='*')
		return true;
	return false;
}

void move(int ent){
	int nx=coord[ent][0]+x[direction[ent]];
	int ny=coord[ent][1]+y[direction[ent]];
	if(ok(nx,ny)){
		coord[ent][0]=nx;
		coord[ent][1]=ny;
	}
	else
		direction[ent]=(direction[ent]+1)%4;
}

void solve(){
	int ans=0;
	while(ans<MAX){
		move(0);
		move(1);
		ans++;
		if(coord[0][0]==coord[1][0] && coord[0][1]==coord[1][1]){
			fout<<ans<<endl;
			return;
		}
	}
	fout<<0<<endl;
}

int main(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			fin>>grid[i][j];
			if(grid[i][j]=='F')
				coord[0][0]=i,coord[0][1]=j;
			if(grid[i][j]=='C')
				coord[1][0]=i,coord[1][1]=j;
		}
	}
	solve();
	return 0;
}
			

