#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const long long maxn = 1e5+7;
int block = 320;

struct query {
    long long lm; long long rm; long long idx;
    
    query() {}
    query(long long _l, long long _r, long long _i) {
        lm = _l; rm = _r; idx = _i;
    }
};

bool cmp(query a, query b) {
    int x = a.lm / block;
    int y = b.lm / block;
    if (x != y)
        return x < y;
    return a.rm < b.rm;
}

long long n, m, v[maxn], sol[maxn], tour[maxn*4], wn;
query qs[maxn];

void upd(long long x, long long s) {
    while (x <= n) {
		tour[x] += s;
		x += (x & -x);
	}
}

long long quert(int x) {
	long long res = 0;
	while (x) {
		res += tour[x];
		x -= (x & -x);
	}
	return res;
}

int main() {
    scanf("%lld %lld", &n, &m);
    
    block = sqrt(n);
    
    for (long long i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    for (long long i = 0; i < m; i++) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        qs[i] = query(l-1, r-1, i);
    }
    
    sort(qs, qs+m, cmp);
    
    wn = 1;
    while (wn <= n) wn *= 2;
    
    for (int i = 0; i < 2*wn; i++) tour[i] = 0;
    
    long long moLeft = 0, moRight = 0; // moleft -> lijevi, moright -> jedan poslije desnog
    long long ans = 0;
    
    for (int i = 0; i < m; i++) {
        query q = qs[i];
        while (moLeft < q.lm) {
            ans -= quert(v[moLeft]-1);
            upd(v[moLeft], -1);
            moLeft++;
        }
        
        while (moLeft > q.lm) {
            moLeft--;
            ans += quert(v[moLeft]-1);
            upd(v[moLeft], 1);
        }
        
        while (moRight <= q.rm) {
            ans += quert(n) - quert(v[moRight]);
            upd(v[moRight], 1);
            moRight++;
        }
        
        while (moRight > q.rm+1) {
            moRight--;
            ans -= quert(n) - quert(v[moRight]);
            upd(v[moRight], -1);
        }
        
        sol[q.idx] = ans;
    }
    
    for (long long i = 0; i < m; i++)
        printf("%lld\n", sol[i]);
}
