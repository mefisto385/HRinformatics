#include <bits/stdc++.h>
using namespace std;

const long long maxn = 2e5+7;

long long n, t, a, b;
long long knjige[maxn];
long long pref[maxn];

//uvijek ce biti niz bbbbbbb...aaaaaa...
//samo je pitanje kada da pocne sa a
//tako cemo sa prefix sumama izracunat kao ako pocne na poziciji i onda ce procitati jos (t-(i+1)*b)/a = x knjiga a inspiracija ce mu biti pref[i+x-1]-pref[i-1]

int main(){
	cin >> n >> t >> a >> b;
	
	for(long long i = 0; i < n; i++){
		cin >> knjige[i];
	}
	
	pref[0] = 0;
	for(long long i = 0; i < n; i++){
		pref[i+1] = pref[i]+knjige[i]; 
	}
	
	long long sol = 0;
	for(long long i = 0; i < n; i++){
		long long timeleft = t-i*b;
		long long x = max(timeleft/a, 0LL);
		long long inspir;
		
		if(i != 0) inspir = pref[min(i+x, n)]-pref[i];
		else inspir = pref[min(i+x, n)];
		
		sol = max(inspir, sol);
	}
	
	cout << sol << '\n';
}
