//CREDITS TO BORNAG TARPENT
#include<bits/stdc++.h>
using namespace std;
int k;
int n;
int od = 9999999;
int x;

int main(){
	cin>>k;
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>x;
		if(od>abs(k-x)){
			od=abs(k-x);
		}
	}
	cout<<od;
}
