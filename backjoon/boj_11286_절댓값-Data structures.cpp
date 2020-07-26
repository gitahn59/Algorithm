/*
boj_11286_절댓값(난이도 : 실버1)
자료구조
사용자 정의 CMP를 이용한 우선순위 큐
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

int N;
typedef struct cmp {
	bool operator()(int a, int b) {
		int absa = abs(a);
		int absb = abs(b);
		if (absa == absb) {
			return a > b;
		}
		else {
			return absa > absb;
		}
	}
}CMP;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, CMP> q;
	cin >> N;
	int num;
	for (int n = 1; n <= N; n++) {
		cin >> num;
		if (num != 0) {
			q.push(num);
		}
		else {
			if (q.empty()) {
				cout << 0 << "\n";
			}
			else {
				int now = q.top();
				q.pop();
				cout << now << "\n";
			}
		}
	}

	return 0;
}

