#include<iostream>
#include<climits>

using namespace std;

int n;
int arr[10001];

void find_largest_sum(){
	int maxi=INT_MIN,temp_max=0;
	for(int i=0;i<n;i++){
		temp_max+=arr[i];
		if(temp_max>maxi)
			maxi=temp_max;
		if(temp_max<0)
			temp_max=0;
	}
	if(maxi<=0)
		cout<<"Losing streak."<<endl;
	else
		cout<<"The maximum winning streak is "<<maxi<<"."<<endl;
}

int main(){
	do{
		cin>>n;
		if(n!=0){
			for(int i=0;i<n;i++)
				cin>>arr[i];
			find_largest_sum();
		}
	}while(n!=0);
	return 0;
}
