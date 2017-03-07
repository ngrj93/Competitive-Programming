#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	cin>>s;
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ||s[i]=='Y');
		else if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='y');
		else if(s[i]>='A' && s[i]<='Z')
			cout<<'.'<<(char)(s[i]+32);
		else
			cout<<'.'<<s[i];
	}
	return 0;
}
