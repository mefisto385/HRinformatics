#include <bits/stdc++.h>
using namespace std;

long long n;

void testcase(){
	cin >> n;
	
	long long cnt = 0;
	while(n >= 2){
		
		long long lo = 1;
		long long hi = n;
		long long finalcards = 0;
		
		while(lo < hi){
			long long mid = (lo+hi)/2;
			long long pyramids = ((mid+1)*(mid))/2;
			
			long long cards = pyramids*3 - mid;
			
			if(cards > n){
				hi = mid;
			} else {
				finalcards = max(cards, finalcards);
				lo = mid+1;
			}
		}
		
		if(finalcards) cnt++;
		n-=finalcards;
	}
	cout << cnt << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long long t; cin >> t;
	while(t--){
		testcase();
	}	
}
