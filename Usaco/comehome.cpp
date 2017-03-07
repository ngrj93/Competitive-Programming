/*
ID: ngrj931
PROG: comehome
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int p;
map<char,vector< pair<int,char> > > adj;
ofstream fout("comehome.out");
ifstream fin("comehome.in");

class Distcomp{
public:
	bool operator()(pair<int,char> n1,pair<int,char> n2){
		return n1.first>n2.first;
	}
};

void dijkstra(){
	map<char,int> mp;
	priority_queue< pair<int,char>,vector< pair<int,char> >,Distcomp> q;
	q.push(make_pair(0,'Z'));
	while(!q.empty()){
		pair<int,char> temp=q.top();
		q.pop();
		if(!mp.count(temp.second)){
			mp.insert(make_pair(temp.second,temp.first));
			for(int i=0;i<adj[temp.second].size();i++)
				if(!mp.count(adj[temp.second][i].second))
					q.push(make_pair(adj[temp.second][i].first+temp.first,adj[temp.second][i].second));
		}
	}
	pair<char,int> ans('0',INT_MAX);
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
		if(it->second<ans.second && it->first>=65 && it->first<90)
			ans=make_pair(it->first,it->second);
	}
	fout<< ans.first <<" "<< ans.second <<endl;
}

int main(){
	fin>>p;
	for(int i=0;i<p;i++){
		char x,y;
		int weight;
		fin>>x>>y>>weight;
		if(!adj.count(x))
			adj[x]=vector< pair<int,char> >();
		if(!adj.count(y))
			adj[y]=vector< pair<int,char> >();
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));
	}
	dijkstra();
	return 0;
}

