/*
boj_1933_스카이라인(난이도 : 골드2)
boj_1689_겹쳐진 선분 문제를 응용하면 풀 수 있음
들어가고 나오는 지점에 대해 높이의 최대값을 기록하여
선형 탐색을 통해 값이 변하눈 부분만 출력하면 됨
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
bool myCmp(ii a, ii b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int a, y, b;
	vii candidate;
	for (int n = 0; n < N; n++) {
		cin >> a >> y >> b;
		candidate.push_back({ a,y });
		candidate.push_back({ b,-y });
	}
	sort(candidate.begin(), candidate.end(), myCmp);
	multiset<int> state;
	state.insert(0);
	map<int, int> rst;

	for (ii data : candidate) {
		if (data.second > 0) {
			state.insert(data.second);
		}
		else {
			auto it = state.find(-data.second);
			state.erase(it);
		}
		auto it = state.end();
		it--;
		rst[data.first] = *it;
	}

	ii begin = *rst.begin();
	cout << begin.first << " " << begin.second << " ";
	int pre = begin.second;
	for (ii now : rst) {
		if (now.second != pre) {
			cout << now.first << " " << now.second << " ";
			pre = now.second;
		}
	}

	return 0;
}


