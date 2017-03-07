#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int q=1;q<=t;q++){
		int n,m,k;
		cin>>n>>m>>k;
		int matrix[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>matrix[i][j];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i>0)
					matrix[i][j]+=matrix[i-1][j];
				if(j>0)
					matrix[i][j]+=matrix[i][j-1];
				if(i>0 && j>0)
					matrix[i][j]-=matrix[i-1][j-1];
			}
		}
		long long area=0,maximum=0,ans_area=0,ans_max=0;
		for(int i=0;i<n;i++){	for(int j=0;j<m;j++){	
			for(int x=i;x<n;x++){	for(int y=j;y<m;y++){
				area=(x-i+1)*(y-j+1);
				maximum=matrix[x][y];
				if(i>0)
					maximum-=matrix[i-1][y];
				if(j>0)
					maximum-=matrix[x][j-1];
				if(i>0 && j>0)
					maximum+=matrix[i-1][j-1];
				if(area>ans_area){
					if(maximum<=k){
						ans_area=area;
						ans_max=maximum;
					}
				}
				else if(area==ans_area){
					if(maximum<ans_max)
						ans_max=maximum;
				}
			}	}
		} }
		printf("Case #%d: %lld %lld\n",q,ans_area,ans_max);
	}
	return 0;
}






		
