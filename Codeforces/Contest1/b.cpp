#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n][n];
	int x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0)
				x=i,y=j;
		}
	}
	if(n==1){
		if(arr[0][0]==0)
			cout<<1<<endl;
		return 0;
	}
	long long col[n-1],row[n-1];
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
	for(int i=0,k=0;k<n;i++,k++){
		for(int j=0;j<n;j++) {
			if(k!=x)
			row[i]+=arr[k][j];
			else{
				i--;
				break;
			}
		}
	}
	for(int i=0,k=0;k<n;i++,k++){
		for(int j=0;j<n;j++){
			if(k!=y)  
			col[i]+=arr[j][k];
			else{
				i--;
				break;
			}
		}
	}
	for(int i=0;i<n-2;i++){
		if(row[i]!=row[i+1] || col[i]!=col[i+1] || row[i]!=col[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	long long n_row,n_diag,n_rev;
	long long n_col=n_row=n_diag=n_rev=0;
	for(int i=0;i<n;i++){
		n_row+=arr[x][i];
		n_col+=arr[i][y];
		n_diag+=arr[i][i];
		n_rev+=arr[i][n-1-i];
	}
	if(x==y && x==n-1-y){
	if(n_row==n_col && n_diag==n_rev && n_col==n_diag){
		long long ans=col[0]-n_row;
		if(ans>0)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
		return 0;
	}
	}
	else if(x==y){
		if(n_row==n_col && n_diag==n_col && n_rev==col[0]){
			long long ans=col[0]-n_row;
			if(ans>0)
				cout<<ans<<endl;
			else
				cout<<-1<<endl;
			return 0;
		}
	}
	else if(x==n-1-y){
		if(n_row==n_col && n_rev==n_col && n_diag==col[0]){
			long long ans=col[0]-n_row;
			if(ans>0)
				cout<<ans<<endl;
			else
				cout<<-1<<endl;
			return 0;
		}
	}
	else{
		if(n_row==n_col && n_diag==n_rev && n_diag==col[0]){
			long long ans=col[0]-n_row;
			if(ans>0)
				cout<<ans<<endl;
			else
				cout<<-1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}


