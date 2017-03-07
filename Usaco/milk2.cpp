/*
ID: ngrj931
PROG: milk2
LANG: C++11
*/

#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int n;
	fin>>n;
	vector< pair<int,int> > farmer;
	for(int i=0;i<n;i++){
		int start,finish;
		fin>>start>>finish;
		farmer.push_back(make_pair(start,finish));
	}
	sort(farmer.begin(),farmer.end());
	int longest_milked=farmer[0].second-farmer[0].first,longest_non_milked=0;
	int best_milked=longest_milked,best_non_milked=0,last_milked=farmer[0].second;
	for(int i=1;i<n;i++){
		if(farmer[i].first<=last_milked && farmer[i].second>last_milked){
			longest_milked+=farmer[i].second-last_milked;
			last_milked=farmer[i].second;
		}
		else if(farmer[i].first>last_milked){
			longest_milked=farmer[i].second-farmer[i].first;
			longest_non_milked=farmer[i].first-last_milked;
			last_milked=farmer[i].second;
		}
		if(longest_milked>best_milked)
			best_milked=longest_milked;
		if(longest_non_milked>best_non_milked)
			best_non_milked=longest_non_milked;
	}
	fout<<best_milked<<" "<<best_non_milked<<endl;
	return 0;
}
