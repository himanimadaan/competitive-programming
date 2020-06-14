/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class... Args>
auto create(size_t n, Args&&... args) {
	if constexpr(sizeof...(args) == 1)
		return vector(n, args...);
	else
		return vector(n, create(args...));
}

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args), ...);
}

void solve() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> arr(n, 0);
		priority_queue<pair<int, pair<int, int>>> pq;
		int cnt = 0, l = 0, r = n - 1;
		pq.push({1LL, {l, r}});
		while (!pq.empty()) {
			l = pq.top().second.first;
			l = -l;
			r = pq.top().second.second;
			pq.pop();
			if (l > r)
				continue;
			int m = l + (r - l) / 2;
			cnt++;
			arr[m] = cnt;
			pq.push({m - l, { -l, m - 1}});
			pq.push({r - m, { -1 - m, r}});
		}
		for (auto &ele : arr)
			cout << ele << " ";
		cout << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}