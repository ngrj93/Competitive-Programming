#include<iostream>
#include<map>
#include<climits>
#include<vector>
using namespace std;

int n,d,t;
int input[100005];
map<int,vector<int> > mp;

int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>input[i];
	for(int i=1;i<=n;i++){
		if(!mp.count(input[i])){
			mp.insert(make_pair(input[i],vector<int>()));
			mp[input[i]].push_back(i);
		}
		else
			mp[input[i]].push_back(i);
	}
	while(d--){
		cin>>t;
		int mindiff=INT_MAX,min_left=-1,min_right=-1;
		for(int i=1;i<=n;i++){
			int temp=input[i]+t;
			if(mp.count(temp)){
				int curdiff=0;
				for(int j=0;j<mp[temp].size();j++){
					curdiff=mp[temp][j]-i;
					if(curdiff>=mindiff)
						break;
					if(mp[temp][j]>i){
						mindiff=mindiff<mp[temp][j]-i?mindiff:mp[temp][j]-i;
						min_left=i;
						min_right=mp[temp][j];
						break;
					}
				}
			}
		}
		if(mindiff==INT_MAX)
			cout<<-1<<endl;
		else
			cout<<min_left<<" "<<min_right<<endl;
	}
	return 0;
}



