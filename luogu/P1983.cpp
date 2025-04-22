// P1983 [NOIP 2013 普及组] 车站分级
#include <bits/stdc++.h>
#define gki g[k][i]
using namespace std;
const int N = 1005;
int n, m;
int s;
int id[N];
int cnt[N];
int sum[N];
int ans = 0;
int k;
bool sgn[N];
bool w[N][N];
vector<int> g[N];
queue<int> q;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		memset(sgn, false, sizeof(sgn));
		for (int j = 0; j < s; j++) {
			cin >> id[j];
			sgn[id[j]] = true;
		}
		for (int j = id[0]; j <= id[s - 1]; j++) {
			if (!sgn[j]) {
				for (int k = 0; k < s; k++) {
					if (!w[j][id[k]]) {
						g[j].push_back(id[k]);
						w[j][id[k]] = true;
						cnt[id[k]]++;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			q.push(i);
			sum[i] = 1;
		}
	}
	while (!q.empty()) {
		k = q.front();
		q.pop();
		for (int i = 0; i < g[k].size(); i++) {
			cnt[gki]--;
			sum[gki] = max(sum[gki], sum[k] + 1);
			if (cnt[gki] == 0) {
				q.push(gki);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, sum[i]);
	}
	cout << ans;
	return 0;
}