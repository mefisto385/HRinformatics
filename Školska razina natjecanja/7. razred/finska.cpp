//CREDITS TO BORNAG & TARPENT
#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int m;
string arr[50];

int main(){
	cin>>n;
	
	for(int i = 1; i<n+1; i++){
		cin>>arr[i];
		char pr = '*';
		for( int j = 0; j<arr[i].size(); j++){
			if(arr[i][j]==pr){
				continue;
			}
			pr=arr[i][j];
			cout<<pr;
		}
		cout<<' ';
	}
	
	
	
}
