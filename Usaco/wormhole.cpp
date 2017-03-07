/*
ID: ngrj931
PROG: wormhole 
LANG: C++11
*/


#include<fstream>
#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
using namespace std;



int ans,n;
int cou;
bool visited[12];

class Hole{
public:	
	int pair_edge;
	int forward_edge;
	bool visited_pair_edge;
	bool visited_forward_edge;
	Hole(){
		pair_edge=forward_edge=n;
		visited_pair_edge=visited_forward_edge=false;
	}
};

vector<Hole> g;
vector< pair<int,int> > wormhole;
vector<int> pairing;

void check_loop(){
	for(int i=0;i<n;i++){
		if(i%2)
			g[pairing[i]].pair_edge=pairing[i-1];
		else
			g[pairing[i]].pair_edge=pairing[i+1];
	}
	for(int i=0;i<n;i++){
		bool turn=true,flag=false;
		int next=i;
		while(true){
			if(turn){
				if(!g[next].visited_pair_edge){
					g[next].visited_pair_edge=true;
					next=g[next].pair_edge;
				}
				else{
					ans++;
					flag=true;
					break;
				}
			}
			else{
				if(!g[next].visited_forward_edge){
					g[next].visited_forward_edge=true;
					next=g[next].forward_edge;
				}
				else{
					ans++;
					flag=true;
					break;
				}
			}
			turn=turn^true;
			if(next==n)
				break;
		}
		for(int j=0;j<n;j++)
			g[j].visited_forward_edge=g[j].visited_pair_edge=false;
		if(flag)
			break;
	}
}
		
void wormhole_pair(int cur){
	if(cur==n){
		check_loop();
		cou++;
		return;
	}
	vector<int> clear;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			visited[i]=true;
			clear.push_back(i);
			pairing.push_back(i);
			for(int j=0;j<n;j++){
				if(!visited[j]){
					pairing.push_back(j);
					visited[j]=true;
					wormhole_pair(cur+2);
					visited[j]=false;
					pairing.pop_back();
				}
			}
			pairing.pop_back();
		}
	}
	for(int i=0;i<clear.size();i++)
		visited[clear[i]]=false;
}

void set_forward_edges(){
	g.resize(n+1);
	for(int i=0;i<n;i++){
		int x=wormhole[i].first;
		int y=wormhole[i].second;
		int bestx=INT_MAX;
		for(int j=0;j<n;j++){
			int curx=wormhole[j].first;
			int cury=wormhole[j].second;
			if(cury==y && curx>x){
				if(curx<bestx){
					bestx=curx;
					g[i].forward_edge=j;
				}
			}
		}
	}
}

int main(){
	ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");
	fin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		fin>>x>>y;
		wormhole.push_back(make_pair(x,y));
	}
	set_forward_edges();
	wormhole_pair(0);
	fout<<ans<<endl;
	cout<<cou<<endl;
	return 0;
}
