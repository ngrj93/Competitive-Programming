/*
ID: ngrj931
PROG: castle 
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int m,n;
int floors[50][50];
vector<int> room_size;
int floor_component[50][50];
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
int wall[]={4,1,8,2};
ofstream fout("castle.out");

int flood_fill(int x,int y,int num){
	int size=1;
	floor_component[x][y]=num;
	for(int i=0;i<4;i++){
		if(!(wall[i]&floors[x][y])  && x+dr[i]<n && x+dr[i]>=0 && y+dc[i]>=0 && y+dc[i]<m && floor_component[x+dr[i]][y+dc[i]]==0)
			size+=flood_fill(x+dr[i],y+dc[i],num);
	}
	return size;
}

void largest_room_find(){
	int maxsize=0,x=0,y=0;
	char d='N';
	for(int j=0;j<m;j++){
		for(int i=n-1;i>=0;i--){
			if(i-1>=0 && floor_component[i-1][j]!=floor_component[i][j]){
				if(room_size[floor_component[i-1][j]-1]+room_size[floor_component[i][j]-1]>maxsize){
					maxsize=room_size[floor_component[i-1][j]-1]+room_size[floor_component[i][j]-1];
					x=i,y=j,d='N';
				}
			}
			if(j+1<m && floor_component[i][j+1]!=floor_component[i][j]){
				if(room_size[floor_component[i][j+1]-1]+room_size[floor_component[i][j]-1]>maxsize){
					maxsize=room_size[floor_component[i][j+1]-1]+room_size[floor_component[i][j]-1];
					x=i,y=j,d='E';
				}
			}
		}
	}
	fout<<maxsize<<endl;
	fout<<x+1<<" "<<y+1<<" "<<d<<endl;
}
			
int main(){
	ifstream fin("castle.in");
	fin>>m>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			fin>>floors[i][j];
	int number_of_rooms=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(floor_component[i][j]==0){
				number_of_rooms++;
				room_size.push_back(flood_fill(i,j,number_of_rooms));
			}
		}
	}
	fout<<number_of_rooms<<endl;
	fout<<*max_element(room_size.begin(),room_size.end())<<endl;
	largest_room_find();
	return 0;
}

