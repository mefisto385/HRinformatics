#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int arr[1000100];
int l,d,s;
long long od;
int ch(int h){
	od = 0;
	for(int i = 0; i<n; i++){
		if(arr[i]>h){
			od+=arr[i]-h;
		}

	}
	return(od<m);
}
int ma;
int main(){
	cin>>n;
	cin>>m;
	ma = 0;
	for(int i = 0; i<n;i++){
		cin>>arr[i];
		if(arr[i]>ma){
			ma=arr[i];
		}
		
	}
	l=0;
	d=ma+2;
	s=d/2;
	while (l<=d){
		if(ch(s)){
			d=s-1;
			s=(d+l)/2;
		}
		else{
			l=s+1;
			s=(d+l)/2;
		}
	}
	cout<<s;
	return(0);
	
}
