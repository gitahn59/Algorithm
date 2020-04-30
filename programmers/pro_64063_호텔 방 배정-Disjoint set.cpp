/*
pro_64063_호텔 방 배정(난이도 : level4)
서로소 집합 + map
수의 범위가 커 map을 이용한 수 매핑이 필요한 문제
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

map<ll, ll> prnt;
ll getPrnt(ll a) {
	if (prnt[a] == 0) {
		prnt[a] = a;
		return a;
	}

	if (a == prnt[a]) return a;
	else return prnt[a] = getPrnt(prnt[a]);
}

void merage(ll a, ll b) {
	a = getPrnt(a);
	b = getPrnt(b);

	if (a > b) {
		prnt[b] = a;
	}
	else {
		prnt[a] = b;
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (int i = 0; i < room_number.size(); i++) {
		ll p = getPrnt(room_number[i]);
		answer.push_back(p);
		ll next = getPrnt(p + 1);
		merage(p, next);
	}

	return answer;
}

