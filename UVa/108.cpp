#include<iostream>
#include<climits>
using namespace std;

int n;

int main(){
	cin>>n;
	int matrix[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>0)
				matrix[i][j]+=matrix[i-1][j];
			if(j>0)
				matrix[i][j]+=matrix[i][j-1];
			if(i>0 && j>0)
				matrix[i][j]-=matrix[i-1][j-1];
		}
	}
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){	for(int j=0;j<n;j++){	
		for(int x=i;x<n;x++){	for(int y=j;y<n;y++){
			int ans=matrix[x][y];
			if(i>0)
				ans-=matrix[i-1][y];
			if(j>0)
				ans-=matrix[x][j-1];
			if(i>0 && j>0)
				ans+=matrix[i-1][j-1];
			maxi=maxi>ans?maxi:ans;
		}	}
	}	}
	cout<<maxi<<endl;
	return 0;
}
				
