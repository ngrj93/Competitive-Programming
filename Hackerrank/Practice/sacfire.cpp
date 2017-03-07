#include <cmath>
#include<iomanip>
#include <cstdio>
#include <iostream>
using namespace std;

int t,s1,s2;

int main() {
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        s1>s2?s1:(s1=s1^s2,s2=s1^s2,s1=s1^s2);
        double ans=sqrt(3*s1*s1/(double)4)*(s1+((s2-(double)s1/2)>0?(s2-(double)s1/2):0));
        cout<<setprecision(3)<<fixed<<ans<<endl;
    }
    
    return 0;
}

