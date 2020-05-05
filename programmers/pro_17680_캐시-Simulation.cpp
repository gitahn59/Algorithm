/*
pro_17680_캐시(난이도 : level 2)
시뮬레이션
문제의 크기가 작아 단순한 구현 가능
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

typedef struct node {
	int t;
	string city;

	bool operator<(node a) const {
		return t < a.t;
	}
}Node;

int CS, N;
string arr[100001];

int simulation() {
	int sum = 0;
	if (CS == 0) return N * 5;

	vector<Node> vs;
	for (int n = 1; n <= N; n++) {
		bool flag = false;
		for (Node& now : vs) {
			if (now.city == arr[n]) {
				now.t = n;
				sum += 1;
				sort(vs.begin(), vs.end());
				flag = true;
				break;
			}
		}

		if (!flag) {
			sum += 5;
			if (vs.size() < CS) {
				vs.push_back({ n,arr[n] });
			}
			else {
				vs.erase(vs.begin());
				vs.push_back({ n,arr[n] });
			}
		}
	}

	return sum;
}

int solution(int cacheSize, vector<string> cities) {
	CS = cacheSize;
	N = cities.size();
	for (int n = 1; n <= N; n++) {
		string rst;
		for (char c : cities[n - 1]) {
			rst += tolower(c);
		}
		arr[n] = rst;
	}

	int answer = simulation();
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });

	return 0;
}
