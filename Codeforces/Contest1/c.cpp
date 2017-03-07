#include<iostream>
#include<climits>
using namespace std;
long long dp[101][101][101];

int main(){
	int n,k,m;
	cin>>n>>m>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int colour[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>colour[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
			for(int l=0;l<m;l++)
				dp[i][j][l]=-1;
	if(arr[0]==0)
		for(int i=0;i<m;i++)
			dp[0][1][i]=colour[0][i];
	else
		dp[0][1][arr[0]-1]=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			if(arr[i]==0){
				for(int d=0;d<m;d++){
					long long minimum=LLONG_MAX;
					for(int l=0;l<m;l++){
						if(l!=d){
							long long temp=dp[i-1][j-1][l];
							if(temp!=-1)
								minimum=minimum<temp?minimum:temp;
						}
					}
					if(minimum!=LLONG_MAX)
						dp[i][j][d]=colour[i][d]+minimum;
					if(dp[i][j][d]!=-1 && dp[i-1][j][d]!=-1)
						dp[i][j][d]=dp[i][j][d]>dp[i-1][j][d]+colour[i][d]?dp[i-1][j][d]+colour[i][d]:dp[i][j][d];
					else if(dp[i][j][d]==-1 && dp[i-1][j][d]!=-1)
						dp[i][j][d]=dp[i-1][j][d]+colour[i][d];
					}
			}
			else{
				long long minimum=LLONG_MAX;
				for(int l=0;l<m;l++){
					if(l!=arr[i]-1){
						long long temp=dp[i-1][j-1][l];
						if(temp!=-1)
							minimum=minimum<temp?minimum:temp;
					}
				}
				if(minimum!=LLONG_MAX)
					dp[i][j][arr[i]-1]=minimum;
				if(dp[i][j][arr[i]-1]!=-1 && dp[i-1][j][arr[i]-1]!=-1)
					dp[i][j][arr[i]-1]=dp[i][j][arr[i]-1]>dp[i-1][j][arr[i]-1]?dp[i-1][j][arr[i]-1]:dp[i][j][arr[i]-1];
				else if(dp[i][j][arr[i]-1]==-1 && dp[i-1][j][arr[i]-1]!=-1)
					dp[i][j][arr[i]-1]=dp[i-1][j][arr[i]-1];
			}
		}
	}
	cout<<endl;
	long long mini=LLONG_MAX;
	for(int i=0;i<m;i++){
		if(dp[n-1][k][i]!=-1)
			mini=mini>dp[n-1][k][i]?dp[n-1][k][i]:mini;
	}
	if(mini!=LLONG_MAX)
		cout<<mini<<endl;
	else
		cout<<-1<<endl;
	return 0;
}



					



