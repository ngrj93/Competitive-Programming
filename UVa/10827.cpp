#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int matrix[n*2-1][n*2-1];
		memset(matrix,0,sizeof(matrix));
		for(int i=n-1;i<2*n-1;i++)
			for(int j=n-1;j<2*n-1;j++)
				cin>>matrix[i][j];
		for(int i=n-1;i<2*n-1;i++)
			for(int j=n,k=0;j<2*n-1;j++,k++)
				matrix[i][k]=matrix[i][j];
		for(int i=n,k=0;i<2*n-1;i++,k++)
			for(int j=n-1;j<2*n-1;j++)
				matrix[k][j]=matrix[i][j];
		for(int i=n,k=0;i<2*n-1;i++,k++)
			for(int j=n,l=0;j<2*n-1;j++,l++)
				matrix[k][l]=matrix[i][j];
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<2*n-1;j++){
				if(i>0)
					matrix[i][j]+=matrix[i-1][j];
				if(j>0)
					matrix[i][j]+=matrix[i][j-1];
				if(i>0 && j>0)
					matrix[i][j]-=matrix[i-1][j-1];
			}
		}
		int max=INT_MIN;
		for(int i=0;i<2*n-1;i++){	for(int j=0;j<2*n-1;j++){
			for(int x=i;x<2*n-1 && x<i+n;x++){	for(int y=j;y<2*n-1 && y<j+n;y++){
				int ans=matrix[x][y];
				if(i>0)
					ans-=matrix[i-1][y];
				if(j>0)
					ans-=matrix[x][j-1];
				if(i>0 && j>0)
					ans+=matrix[i-1][j-1];
				max=ans>max?ans:max;
			}	}
		}	}
		cout<<max<<endl;
	}
	return 0;
}
