//CREDITS TO BORNAG & TARPENT
#include<bits/stdc++.h>
using namespace std;

int n;
int y;
char z;

int main(){
	cin>>z;
	cin>>n;
	cin>>y;
	
	if(z=='Z'){
		if(y<=n){
			cout<<y;
		}
		else{
			cout<<n+y+30;
		}
	}
	else{
		cout<<n+y;
	}
}
