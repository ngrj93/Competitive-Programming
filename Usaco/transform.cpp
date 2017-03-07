/*
ID: ngrj931
PROB: transform
LANG: C++11
*/

#include<fstream>
using namespace std;

int n;

int check_rotation(char original[][10],char transformed[][10]){
	bool flag=true;
	for(int i=0,k=n-1;i<n;i++,k--){
		for(int j=0;j<n;j++){
			if(original[i][j]!=transformed[j][k]){
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	if(flag)
		return 1;
	flag=true;
	for(int i=0,k=n-1;i<n;i++,k--){
		for(int j=0,l=n-1;j<n;j++,l--){
			if(original[i][j]!=transformed[k][l]){
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	if(flag)
		return 2;
	
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0,l=n-1;j<n;j++,l--){
			if(original[i][j]!=transformed[l][i]){
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	if(flag)
		return 3;
	return 0;
}

int check_matrix(char original[][10],char transformed[][10]){
	int val=check_rotation(original,transformed);
	if(val>0)
		return val;

	bool flag=true;
	char horizontal[10][10];
	for(int i=0;i<n;i++)
		for(int j=n-1,k=0;j>=0;j--,k++)
			horizontal[i][j]=original[i][k];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(horizontal[i][j]!=transformed[i][j]){
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	if(flag)
		return 4;

	val=check_rotation(horizontal,transformed);
	if(val>0)
		return 5;

	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(original[i][j]!=transformed[i][j]){
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	if(flag)
		return 6;
	return 7;

}

int main(){
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	fin>>n;
	char original[10][10],transformed[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin>>original[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin>>transformed[i][j];
	fout<<check_matrix(original,transformed)<<endl;
	return 0;
}
