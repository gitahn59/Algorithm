/*
boj_4386_별자리만들기(난이도 : )
MST
각 별자리 사이의 간선의 가중치를 계산하고 
별자리 그래프의 MST를 구하는 문제
별의 최대 개수가 100개 이므로 간선의 최대치는 
100(101) / 2 = 5050개
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
#include <tuple>

#define PRIME 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int prnt[101];
void init(int size) {
	for (int i = 1; i <= size; i++) {
		prnt[i] = i;
	}
}

int getParent(int a) {
	if (a == prnt[a]) return a;
	else return prnt[a] = getParent(prnt[a]);
}

bool isSet(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

void mearge(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	prnt[a] = b;
}

int N;
pair<double, double> pdd[101];
typedef struct edge {
	int form, to;
	double cost;
}Edge;

bool myCmp(Edge a, Edge b) {
	return a.cost < b.cost;
}

Edge edges[10001];
int M;

int main() {
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> pdd[n].first >> pdd[n].second;
	}

	for (int n = 1; n < N; n++) {
		for (int i = n + 1; i <= N; i++) {
			double dist = (pdd[n].first - pdd[i].first) * (pdd[n].first - pdd[i].first)
				+ (pdd[n].second - pdd[i].second) * (pdd[n].second - pdd[i].second);
			edges[++M] = { n,i, sqrt(dist) };
		}
	}

	sort(edges + 1, edges + 1 + M, myCmp);
	double sum = 0;
	init(N);
	for (int m = 1; m <= M; m++) {
		Edge now = edges[m];
		if (isSet(now.form, now.to)) continue;
		mearge(now.form, now.to);
		sum += now.cost;
	}

	printf("%.3lf", sum);

	return 0;
}



