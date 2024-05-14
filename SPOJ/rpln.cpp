#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, q, t, ni, qi, bn, qi2;
ll grades[100007];
ll tour[100007*4];

void upd(int x, int v){
	x+=bn;
	tour[x] = v;
	x /= 2;
	while(x > 0){
		tour[x] = min(tour[x*2], tour[x*2+1]);
		x /= 2; 
	}
}

int query(int ax, int bx, int x, int l, int r){
	//cout << l << ' ' << r << ' ' << ax << ' ' <<  bx << endl;
	if(l > bx or r < ax) return INT_MAX;//izvan granica
	
	//if(l >= ax and r <= bx) cout << "omg" << tour[x] << ' ' << x << ' ' << endl;
	
	if(l >= ax and r <= bx) return tour[x]; //Ako je skroz u granicama
	//else if(l >= ax and r <= bx) return tour[x-1];
	
	int mid = (l + r)/2;
	
	/*cout << query(ax, bx, x*2, l, mid) << ' ' << 
		   query(ax, bx, x*2+1, mid+1, r) << endl;*/
	
	return min(query(ax, bx, x*2, l, mid),
			   query(ax, bx, x*2+1, mid+1, r));
}


void program(){
	cin >> n >> q;	
	bn = 1;
	while(bn < n) bn*=2;
	
	for(int i = n; i < bn; i++) tour[i + bn] = INT_MAX;

	for(int i = 0; i < n; i++){
		cin >> tour[i + bn];
	}
	
	for(int i = bn-1; i >= 1; i--){
		tour[i] = min(tour[i*2], tour[i*2+1]);
	}
	
	//cout << query(1, 3, 1, 0, n-1) << endl;
	
	for(int i = 0; i < q; i++){
		cin >> qi >> qi2;
		cout << query(qi-1, qi2-1, 1, 0, bn-1) << '\n';
	}
	
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0; i < t; i++){
		cout << "Scenario #" << i+1 << ":\n";
		program();
	}
}
