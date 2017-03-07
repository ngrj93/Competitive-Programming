#include<iostream>
#include<cstring>
using namespace std;

string input;
int digit[10];

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		cin>>input;
		for(int i=0;i<input.size();i++)
			digit[input[i]-48]++;
		bool flag2=true;
		for(int i=0;i<125;i++){
			int limit;
			if(input.size()==1)
				limit=1;
			else if(input.size()==2)
				limit=2;
			else
				limit=3;			
			int it[10]={0},val=8*i,q=0;
			while(val!=0){
				it[val%10]++;
				q++;
				val/=10;
			}
			while(q<limit){
				it[0]++;
				q++;
			}
			bool flag=true;
			for(int i=0;i<10;i++){
				if(digit[i]<it[i])
					flag=false;
			}
			if(flag){
				cout<<"YES"<<endl;
				flag2=false;
				break;
			}
		}
		if(flag2)
			cout<<"NO"<<endl;
		memset(digit,0,sizeof(digit));
	}
	return 0;
}

