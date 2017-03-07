#include<iostream>
#include<cstring>
#include<algorithm>
#define MOD 1000000007
using namespace std;

int t,m,n;
int horizontal[1000000];
int vertical[1000000];

long long mincost(){
	int hindex=0,vindex=0;
	long long cost=0;
	int hcuts=1,vcuts=1;
	sort(horizontal,horizontal+m-1,greater<int>());
	sort(vertical,vertical+n-1,greater<int>());
	while(hindex<m-1 && vindex<n-1){
		if(horizontal[hindex]>vertical[vindex]){
			cost=(cost+(long long)horizontal[hindex]*vcuts)%MOD;
			hindex++;
			hcuts++;
		}
		else{
			cost=(cost+(long long)vertical[vindex]*hcuts)%MOD;
			vindex++;
			vcuts++;
		}
	}
	while(hindex<m-1){
		cost=(cost+(long long)horizontal[hindex]*vcuts)%MOD;
		hindex++;
	}
	while(vindex<n-1){
		cost=(cost+(long long)vertical[vindex]*hcuts)%MOD;
		vindex++;
	}
	return cost;
}

int main(){
	cin>>t;
	while(t--){
		cin>>m>>n;
		for(int i=0;i<m-1;i++)
			cin>>horizontal[i];
		for(int i=0;i<n-1;i++)
			cin>>vertical[i];
		cout<<mincost()<<endl;
		memset(horizontal,0,sizeof(horizontal));
		memset(vertical,0,sizeof(vertical));
	}
	return 0;
}

