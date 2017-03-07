#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string a,b;
		cin>>a>>b;
		int one_count=0,zero_count=0,one_change_count=0,zero_change_count=0;
		for(int i=0;i<a.length();i++){
			if(a[i]==b[i]){
				if(a[i]=='1')
					one_count++;
				else
					zero_count++;
			}
			else if(b[i]=='1'){
				zero_change_count++;
				zero_count++;
			}
			else{
				one_change_count++;
				one_count++;
			}
		}
		int finans=(zero_change_count>one_change_count?one_change_count:zero_change_count);
		one_change_count-=finans;
		zero_change_count-=finans;
		if(zero_change_count>0){
			if(one_count>0){
				finans+=zero_change_count;
				cout<<"Lucky Chef"<<endl<<finans<<endl;
			}
			else
				cout<<"Unlucky Chef"<<endl;
		}
		else if(one_change_count>0){
			if(zero_count>0){
				finans+=one_change_count;
				cout<<"Lucky Chef"<<endl<<finans<<endl;
			}
			else
				cout<<"Unlucky Chef"<<endl;
		}
	}
	return 0;
}
