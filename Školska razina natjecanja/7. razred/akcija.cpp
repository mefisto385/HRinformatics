//CREDIT TO BORNAG & TARPENT
#include <bits/stdc++.h>
using namespace std;

int cijene[17];

int getbest(){
	int ind, maxi;
	maxi = 0;
	ind = 0;
	
	for(int i = 0; i < 17; i++){
		if(maxi < cijene[i]){
			ind = i;
			maxi = cijene[i];
		}
	} return ind;
}

int suma(){
	int ret = 0;
	for(int i = 0; i < 17; i++) ret+=cijene[i];
	return ret;
}

int main(){
	int n, k; cin >> n >> k;
	
	for(int i = 0; i < n; i++) cin >> cijene[i];
	
	int ret = 0;
	
	for(int i = 0; i < n/k; i++){
		for(int j = 0; j < k; j++){
			
			int best = getbest();
			cout << "";
			
			if(j != k-1) ret+=cijene[best];
			cijene[best] = 0;
		}
	} 
	
	cout << ret+suma();
}
