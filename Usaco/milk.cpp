/*
ID: ngrj931
PROG: milk
LANG: C++11
*/

#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int n,m;
	fin>>n>>m;
	vector< pair<int,int> > farmer;
	for(int i=0;i<m;i++){
		int price,total;
		fin>>price>>total;
		farmer.push_back(make_pair(price,total));
	}
	sort(farmer.begin(),farmer.end());
	int i=0,total_cost=0;
	while(n>0 && m!=0){
		if(farmer[i].second<=n){
			total_cost+=farmer[i].first*farmer[i].second;
			n-=farmer[i].second;
		}
		else{
			total_cost+=farmer[i].first*n;
			n=0;
		}
		i++;
	}
	fout<<total_cost<<endl;
	return 0;
}
