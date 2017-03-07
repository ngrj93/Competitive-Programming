/*
ID: ngrj931
PROG: cowtour
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

ofstream fout("cowtour.out");
ifstream fin("cowtour.in");
int n;
vector< pair<int,int> > location;
double dist[150][150];

double calculate_distance(int source,int destination){
	return sqrt((location[source].first-location[destination].first)*(location[source].first-location[destination].first)+(location[source].second-location[destination].second)*(location[source].second-location[destination].second));
}

void all_pair_paths(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
}

double find_dist(int x){
	double ans=0;
	for(int i=0;i<n;i++){
		if(dist[x][i]!=INFINITY)
			ans=max(ans,dist[x][i]);
	}
	return ans;
}

int main(){
	fin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		fin>>x>>y;
		location.push_back(make_pair(x,y));
	}
	for(int i=0;i<n;i++){
		string s;
		fin>>s;
		for(int j=0;j<n;j++){
			if(i==j)
				dist[i][j]=0;
			else if(s[j]=='0')
				dist[i][j]=INFINITY;
			else
				dist[i][j]=calculate_distance(i,j);
		}
	}
	double ans=INFINITY;
	 all_pair_paths();
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(dist[i][j]==INFINITY)
				ans=min(ans,calculate_distance(i,j)+find_dist(i)+find_dist(j));
	for(int i=0;i<n;i++)
		ans=max(ans,find_dist(i));
	fout<<std::fixed<<std::setprecision(6)<<ans<<endl;
	return 0;
}
