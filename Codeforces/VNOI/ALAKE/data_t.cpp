#include<algorithm>
#include<iostream>
#include<cstdio>

#define prev asdfasdfas
#define next asdfasdf
using namespace std;
 
const int N = 1e5 + 2, INF = 1e9 + 7;
int h[N], w[N], next[N], prev[N], n;
long long res[N];
 
int main() {
	ios::sync_with_stdio(false);

  // Reading input
	cin >> n;
	h[0] = h[n + 1] = INF;
	for(int i = 1; i <= n; ++i) cin >> w[i] >> h[i];

	for(int i = 0; i <= n + 1; ++i) prev[i] = i - 1, next[i] = i + 1;

	int index = min_element(h + 1, h + n + 1) - h;
	long long total = 0;
	while(h[index] < INF) {
		res[index] = total + w[index];
		next[prev[index]] = next[index];
		prev[next[index]] = prev[index];
		if(h[next[index]] < h[prev[index]]) {
			w[next[index]] += w[index];
			total += 1LL * (h[next[index]] - h[index]) * w[index];
			index = next[index];
			while(h[next[index]] < h[index]) index = next[index];
		} else {
			w[prev[index]] += w[index];
			total += 1LL * (h[prev[index]] - h[index]) * w[index];
			index = prev[index];
			while(h[prev[index]] < h[index]) index = prev[index];
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%lld\n", res[i]);
	return 0;
}
