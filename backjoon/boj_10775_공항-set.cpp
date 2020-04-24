/*
boj_10775_공항(난이도 : 골드2)
Disjoint setGreedy / Segment tree / Set
서로소집합 : 노드를 사용하고 나면 n과 n-1을 mearge하여
더이상 그 노드를 사용하지 못하도록 하는 것이 핵심

segment tree : lowerbound을 통해 들어갈 수 있는 자리 탐색, 구현 복잡

set : lowerbound를 통해 들어갈 수 있는 자리 탐색, 가장 구현 간단함
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

int G, P;
int arr[100001];
si s;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> G >> P;
	for (int p = 1; p <= P; p++) {
		cin >> arr[p];
	}

	for (int g = 1; g <= G; g++) {
		s.insert(-g);
	}

	int rst = 0;
	for (int p = 1; p <= min(P, G); p++) {
		auto it = s.lower_bound(-arr[p]);
		if (it == s.end()) break;
		rst++;
		s.erase(it);
	}

	cout << rst << "\n";

	return 0;
}



