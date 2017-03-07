#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	bool flag=true;
	char matrix[n][5];
	for(int i=0;i<n;i++)
			cin>>matrix[i][0]>>matrix[i][1]>>matrix[i][2]>>matrix[i][3]>>matrix[i][4];
	for(int i=0;i<n;i++){
			if(matrix[i][0]==matrix[i][1] && matrix[i][0]=='O' && flag){
				matrix[i][0]=matrix[i][1]='+';
				flag=false;
			}
			if(matrix[i][3]==matrix[i][4] && matrix[i][3]=='O' && flag){
				matrix[i][3]=matrix[i][4]='+';
				flag=false;
			}
		}
	if(flag)
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++)
			cout<<matrix[i][j];
		cout<<endl;
	}
	}
		return 0;
}



