/*
pro_67258_보석쇼핑(난이도 : level3)
Sweeping
1차원 스위핑문제
1. 모든 보석을 포함하는 첫번째 구간 탐색
2. 그 구간부터 시작해서 우로 한칸씩 구간을 확장하고,
	좌에서 필요없는 보석들을 매번 제거함 
	=> 항상 모든 보석을 포함하는 상태로 구간 이동
3. 탐색 중에 식별되는 구간들 중 가장 짧은 구간 기록
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

int M;
int cnt[100000];
vi candidate;

void preprocessing(vector<string>& gems) {
	int idx = 1;
	map<string, int> id;

	for (string s : gems) {
		if (id[s] == 0) {
			id[s] = idx++;
		}
		candidate.push_back(id[s] - 1);
	}
	M = idx - 1;
}

vi sweeping() {
	set<int> first;
	int N = candidate.size();
	int i = 0;
	// first
	for (; i < N; i++) {
		first.insert(candidate[i]);
		cnt[candidate[i]]++;
		if (first.size() == M) {
			break;
		}
	}

	ii rst = { 0,i };
	while (rst.first < rst.second && cnt[candidate[rst.first]] > 1) {
		cnt[candidate[rst.first]]--;
		rst.first++;
	}
	ii range = rst;
	i++;
	for (i; i < N; i++) {
		cnt[candidate[i]]++;
		range.second++;
		while (range.first < range.second && cnt[candidate[range.first]]>1) {
			cnt[candidate[range.first]]--;
			range.first++;
		}
		if (rst.second - rst.first > range.second - range.first) {
			rst = range;
		}
	}

	return { rst.first + 1, rst.second + 1 };
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	preprocessing(gems);
	return sweeping();
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vi rst = solution({ "b","a","b","b", "c","c","b","a" });

	return 0;
}


