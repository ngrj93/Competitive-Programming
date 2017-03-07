#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,f,mcount=0,fcount=0;
		cin>>n>>m>>f;
		int challenger[n];
		for(int i=0;i<n;i++)
			cin>>challenger[i];
		for(int i=0;i<n;i++){
			if(!(challenger[i]%m) && challenger[i]!=0)
				mcount++;
			else if(!(challenger[i]%f) && challenger[i]!=0)
				fcount++;
		}
		if((double)(fcount+mcount)/n>=0.7){
			cout<<"Yes"<<endl;
			if(mcount>fcount)
				cout<<"Multan"<<endl;
			else if(fcount>mcount)
				cout<<"Fultan"<<endl;
			else
				cout<<"Both"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
	return 0;
}


