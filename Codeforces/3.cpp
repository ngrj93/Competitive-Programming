#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		string input;
		cin>>input;
		if(input.size()>10){
			string mid=to_string(input.size()-2);
			input=input[0]+mid+input[input.size()-1];
		}
		cout<<input<<endl;
	}
	return 0;
}
