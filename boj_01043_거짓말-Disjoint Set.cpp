/*
boj_1043_거짓말(난이도 : 골드5)
Disjoint Set
서로소 집합과 큐를 사용해 진실만을 듣는 집합을 생성

큐가 빌 때 까지 반복
1. 큐에 넣을때 visited 를 체크하여 중복 검사 방지
2. front를 꺼내고 그 값을 이용해 모든 파티를 돌며 진실을 
	들어야하는 미방문 원소를 찾아 큐에 삽입

조건에 맞는 파티의 갯수 count
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
#include <climits>

#define PRIME 1000000007
#define mp make_pair

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

int N, M, K;

int know[51];
int num[51];
bool party[51][51];
vi src[51];

int parent[55];
queue<int> candidate;
bool visited[51];

void init(int size) {
	for (int n = 0; n <= size; n++) {
		parent[n] = n;
	}
}

int getPrnt(int p) {
	if (p == parent[p]) return p;
	else
		return parent[p] = getPrnt(parent[p]);
}

bool isSet(int a, int b) {
	a = getPrnt(a);
	b = getPrnt(b);
	return a == b;
}

void merge(int a, int b) {
	a = getPrnt(a);
	b = getPrnt(b);

	if (a < b) parent[b] = a;
	else if (b > a) parent[a] = b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	init(N);
	for (int k = 1; k <= K; k++) {
		cin >> know[k];
		candidate.push(know[k]);
		visited[know[k]] = 1;
	}

	for (int m = 1; m <= M; m++) {
		cin >> num[m];
		int name;
		for (int i = 1; i <= num[m]; i++) {
			cin >> name;
			party[m][name] = 1;
			src[m].push_back(name);
		}
	}

	while (!candidate.empty()) {
		int now = candidate.front();
		candidate.pop();
		merge(0, now);

		for (int m = 1; m <= M; m++) {
			if (party[m][now] == 1) {
				for (int n : src[m]) {
					if (visited[n] == 1) continue;
					else {
						visited[n] = 1;
						candidate.push(n);
					}
				}
			}
		}
	}

	int cnt = 0;
	for (int m = 1; m <= M; m++) {
		if (num[m] == 0) {
			cnt++;
			continue;
		}
		if (getPrnt(src[m][0]) != 0) {
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}


