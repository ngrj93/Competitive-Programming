#include<iostream>
#include<climits>

using namespace std;

int t,a,b,c;

int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		long long dp[a][b][c];
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				for(int k=0;k<c;k++)
					cin>>dp[i][j][k];
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					if(i>0)
						dp[i][j][k]+=dp[i-1][j][k];
					if(j>0)
						dp[i][j][k]+=dp[i][j-1][k];
					if(k>0)
						dp[i][j][k]+=dp[i][j][k-1];
					if(i>0 && j>0)
						dp[i][j][k]-=dp[i-1][j-1][k];
					if(i>0 && k>0)
						dp[i][j][k]-=dp[i-1][j][k-1];
					if(j>0 && k>0)
						dp[i][j][k]-=dp[i][j-1][k-1];
					if(i>0 && j>0 && k>0)
						dp[i][j][k]+=dp[i-1][j-1][k-1];
				}
			}
		}
		long long maxi=LLONG_MIN;
		for(int i=0;i<a;i++){	for(int j=0;j<b;j++){	for(int k=0;k<c;k++){
			for(int x=i;x<a;x++){	for(int y=j;y<b;y++){	for(int z=k;z<c;z++){
				long long ans=dp[x][y][z]; 
				if(i>0)
					ans-=dp[i-1][y][z];
				if(j>0)
					ans-=dp[x][j-1][z];
				if(k>0)
					ans-=dp[x][y][k-1];
				if(i>0 && j>0)
					ans+=dp[i-1][j-1][z];
				if(i>0 && k>0)
					ans+=dp[i-1][y][k-1];
				if(j>0 && k>0)
					ans+=dp[x][j-1][k-1];
				if(i>0 && j>0 && k>0)
					ans-=dp[i-1][j-1][k-1];
				maxi=maxi>ans?maxi:ans;
			}	}	}
		}	}	}
		cout<<maxi<<endl<<(t>=1?"\n":"");
	}
	return 0;
}
