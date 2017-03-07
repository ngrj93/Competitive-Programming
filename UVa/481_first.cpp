#include<iostream>
#include<vector>
using namespace std;

void recursive_print(vector<int> &input, vector<pair<int,int> > &lis,int ans){
	if(ans!=-1){
		recursive_print(input,lis,lis[ans].second);
		cout<<input[ans]<<endl;
	}
}

int main(){
	vector<int> input;
	int temp;
	while(cin>>temp)
		input.push_back(temp);
	vector< pair<int,int> > lis;
	lis.push_back(make_pair(1,-1));
	for(int i=1;i<input.size();i++){
		int largest=1,previous=-1;
		for(int j=0;j<i;j++){
			if(input[i]>input[j]){
				if(largest<=lis[j].first+1){
					largest=lis[j].first+1;
					previous=j;
				}
			}
		}
		lis.push_back(make_pair(largest,previous));
	}
	int ans=lis.size()-1;
	for(int i=0;i<lis.size();i++){
		if(lis[i].first>=lis[ans].first){
			ans=i;
		}
	}
	cout<<lis[ans].first<<endl;
	cout<<"-"<<endl;
	recursive_print(input,lis,ans);
	return 0;
}




