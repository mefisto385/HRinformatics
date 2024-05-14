//CREDITS TO BORNAG & TARPENT
#include <bits/stdc++.h>
using namespace std;
int arr[40];
int n;
int k;
int m;
int od[50];
int tr = 0;
int main(){
	cin>>n;
	cin>>k;
	cin>>m;
	
	for(int i = 1; i<n+1; i++){
		cin>>arr[i];
	}
	for (int i=0; i<n;i++){
		int ov = i+1;
		for(int j = 0; j<k-1; j++){
			ov = arr[ov];
		}
		if (ov==m){
			cout<<i+1<<'\n';
		}
	}
	
	
}
