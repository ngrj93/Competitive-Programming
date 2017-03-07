/*
ID: ngrj931
PROG: maze1
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<queue>
#include<cstring>
using namespace std;

char grid[205][80];
int dist[205][80];
bool visited[205][80];
int w,h,coord[2][2];
int x[]={-2,0,2,0};
int y[]={0,2,0,-2};
int bx[]={-1,0,1,0};
int by[]={0,1,0,-1};
char barrier[]={'-','|','-','|'};
ofstream fout("maze1.out");
ifstream fin("maze1.in");

void compute_dist(int c){
	memset(visited,0,sizeof(visited));
	queue<pair<int,int> > q;
	visited[coord[c][0]][coord[c][1]]=true;
	dist[coord[c][0]][coord[c][1]]=0;
	if(coord[c][0]==0){
		q.push(make_pair(coord[c][0]+1,coord[c][1]));
		dist[coord[c][0]+1][coord[c][1]]=1;
		visited[coord[c][0]+1][coord[c][1]]=true;
	}
	else if(coord[c][0]==2*h){
		q.push(make_pair(coord[c][0]-1,coord[c][1]));
		dist[coord[c][0]-1][coord[c][1]]=1;
		visited[coord[c][0]-1][coord[c][1]]=true;
	}
	else if(coord[c][1]==0){
		q.push(make_pair(coord[c][0],coord[c][1]+1));
		dist[coord[c][0]][coord[c][1]+1]=1;
		visited[coord[c][0]][coord[c][1]+1]=true;
	}
	else{
		q.push(make_pair(coord[c][0],coord[c][1]-1));
		dist[coord[c][0]][coord[c][1]-1]=1;
		visited[coord[c][0]][coord[c][1]-1]=true;
	}
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			if(grid[p.first+bx[i]][p.second+by[i]]!=barrier[i] && !visited[p.first+x[i]][p.second+y[i]] && p.first+x[i]>0 && p.first+x[i]<2*h && p.second+y[i]>0 && p.second+y[i]<2*w){
				if(dist[p.first+x[i]][p.second+y[i]]!=0)
					dist[p.first+x[i]][p.second+y[i]]=min(dist[p.first+x[i]][p.second+y[i]],dist[p.first][p.second]+1);
				else
					dist[p.first+x[i]][p.second+y[i]]=dist[p.first][p.second]+1;
				q.push(make_pair(p.first+x[i],p.second+y[i]));
				visited[p.first+x[i]][p.second+y[i]]=true;
			}
		}
	}
}

void find_max(){
	int ans=0;
	for(int i=0;i<2*h+1;i++)
		for(int j=0;j<2*w+1;j++)
			ans=max(ans,dist[i][j]);
	fout<<ans<<endl;
}
					
int main(){
	fin>>w>>h;
	fin.ignore();
	int c=0;
	for(int i=0;i<2*h+1;i++){
		for(int j=0;j<2*w+1;j++){
			fin.get(grid[i][j]);
			if(i==0 && grid[i][j]!='+' && grid[i][j]!='-'){
				coord[c][0]=i,coord[c][1]=j;
				c++;
			}
			if(i==2*h && grid[i][j]!='+' && grid[i][j]!='-'){
				coord[c][0]=i,coord[c][1]=j;
				c++;
			}
			if(j==0 && grid[i][j]!='+' && grid[i][j]!='|'){
				coord[c][0]=i,coord[c][1]=j;
				c++;
			}
			if(j==2*w && grid[i][j]!='+' && grid[i][j]!='|'){
				coord[c][0]=i,coord[c][1]=j;
				c++;
			}
		}
		fin.get();
	}
	compute_dist(0);
	compute_dist(1);
	find_max();
	return 0;
}

