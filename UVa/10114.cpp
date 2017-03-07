#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main(){
	int duration,n;
	double down_payment,amount;
	scanf("%d",&duration);
	while(duration>0){
		scanf("%lf%lf%d",&down_payment,&amount,&n);
		map<int,double> mp;
		int month;double dep;
		for(int i=0;i<n;i++){
			scanf("%d%lf",&month,&dep);
			mp[month]=dep;
		}
		double to_be_paid=amount;
		double current_price=(1-mp[0])*(amount+down_payment);
		int i=1,cur=0,count=0;
		double diff=amount/duration;
		while(to_be_paid>=current_price){
			if(mp.count(i)){
				cur=i;
			}
			to_be_paid-=diff;
			current_price*=(1-mp[cur]);
			count++;
			i++;
		}
		(count==1)?printf("%d month\n",count):printf("%d months\n",count);
		scanf("%d",&duration);
	}
	return 0;
}
