#include<iostream>
using namespace std;

int t,n;
long long g_total;

int find_neg(int arr[],int start,int end){
	int index=end,l=0,r=0,tl=0,tr=0,steps=n-end+start;
	long long lmin=0,rmin=0,templ=0,tempr=0,total=0,ans=0;
	while(index!=start){
		templ+=arr[index];
		tl++;
		if(templ<lmin){
			lmin=templ;
			l=tl;
		}
		index=(index+1)%n;
	}
	index=start-1<0?n-1:start-1;
	int x=end-1<0?n-1:end-1;
	while(index!=x){
		tempr+=arr[index];
		tr++;
		if(tempr<rmin){
			rmin=tempr;
			r=tr;
		}
		index=index-1<0?n-1:index-1;
	}
	total=g_total;	
	if(r+l>steps){
		tl=0,templ=0,index=end;
		long long templmin=0,min_dist=0;
		while(tl<steps-r){
			templ+=arr[index];
			tl++;
			if(templ<templmin)
				templmin=templ;
			index=(index+1)%n;
		}
		min_dist=rmin+templmin;
		tr=0,tempr=0,index=start-1<0?n-1:start-1;
		long long temprmin=0;
		while(tr<steps-l){
			tempr+=arr[index];
			tr++;
			if(tempr<temprmin)
				temprmin=tempr;
			index=index-1<0?n-1:index-1;
		}
		min_dist=min_dist<lmin+temprmin?min_dist:lmin+temprmin;
		min_dist=min_dist<total?min_dist:total;
		if(min_dist<0)
			min_dist*=2;
		else
			min_dist=0;
		return min_dist;
	}
	ans=total<lmin+rmin?total:lmin+rmin;
	if(ans<0 && ans!=total)
		ans*=2;
	else if(ans!=total)
		ans=0;
	return ans;
}
		
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		g_total=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			g_total+=arr[i];
		}
		int start,end;
		cin>>start>>end;
		start--;end--;
		long long dist=0,min_dist=0;
		for(int i=start;i<end;i++)
			min_dist+=arr[i];
		dist=g_total-min_dist;
		min_dist+=find_neg(arr,start,end);
		dist+=find_neg(arr,end,start);
		min_dist=min_dist<dist?min_dist:dist;
		cout<<min_dist<<endl;
	}
	return 0;
}
