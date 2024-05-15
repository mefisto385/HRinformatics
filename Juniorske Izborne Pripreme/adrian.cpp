#include <bits/stdc++.h>
using namespace std;

const int bitmax = 1e8+7;

#define ll long long

string s;
ll sol, xorPref;
int cntXor[bitmax];

ll pot2[30];

int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> s;
	
	pot2[0] = 1;
	for(int i = 1; i < 27; i++)
		pot2[i] = pot2[i-1]*2;

	cntXor[0] = 1;
	
	for(ll i = 0; i < s.size(); i++){
		char si = s[i];
		
		xorPref = xorPref ^ pot2[si-'a'];
		
		sol += cntXor[xorPref];
		
		for(ll j = 0; j < 26; j++){
			sol += cntXor[xorPref ^ pot2[j]];
		}
		
		cntXor[xorPref]++;
	}
	
	cout << sol << '\n';
}
