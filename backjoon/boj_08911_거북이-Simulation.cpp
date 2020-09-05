/*
boj_거북이_Simulation(난이도 : 실버2)
Simulation
거북이의 움직임을 조건 그대로 시뮬레이션
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <set>
#include <bitset>
#include <climits>
#include <functional>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int N;
string path;
int n = 0;
int e = 1;
int w = 2;
int s = 3;
int next_d[4][120];
ii next_m[4][120];

void preprocessing() {
	next_d[n]['L'] = w;
	next_d[n]['R'] = e;

	next_d[e]['L'] = n;
	next_d[e]['R'] = s;

	next_d[w]['L'] = s;
	next_d[w]['R'] = n;

	next_d[s]['L'] = e;
	next_d[s]['R'] = w;

	next_m[n]['F'] = { 0,1 };
	next_m[n]['B'] = { 0,-1 };

	next_m[e]['F'] = { 1,0 };
	next_m[e]['B'] = { -1,0 };

	next_m[w]['F'] = { -1,0 };
	next_m[w]['B'] = { 1,0 };

	next_m[s]['F'] = { 0,-1 };
	next_m[s]['B'] = { 0,1 };
}

int simulation() {
	ii lb = { 0,0 }, rh = { 0,0 };
	ii pos = { 0,0 };
	int d = n;
	for (char op : path) {
		if (op == 'L' || op == 'R') {
			d = next_d[d][op];
		}
		else {
			pos.first += next_m[d][op].first;
			pos.second += next_m[d][op].second;

			lb.first = min(lb.first, pos.first);
			lb.second = min(lb.second, pos.second);

			rh.first = max(rh.first, pos.first);
			rh.second = max(rh.second, pos.second);
		}
	}

	return (rh.first - lb.first) * (rh.second - lb.second);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	preprocessing();

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> path;
		cout << simulation() << "\n";
	}

	return 0;
}


