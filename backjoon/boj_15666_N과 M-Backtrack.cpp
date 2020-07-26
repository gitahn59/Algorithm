/*
boj_15666_N과 M(12)(난이도 : 실버2)
Backtrack
백트래킹을 통해 후보 탐색
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
vi candidate;
int selected[10];

void backtrack(int pre, int now, int cnt) {
	if (cnt == M) {
		for (int m = 1; m <= M; m++) {
			cout << candidate[selected[m]]<<" ";
		}
		cout << "\n";
		return;
	}

	for (int i = now; i <= K; i++) {
		selected[cnt + 1] = i;
		backtrack(i, i, cnt + 1);
		selected[cnt + 1] = 0;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	vi temp;
	int num;
	for (int n = 1; n <= N; n++) {
		cin >> num;
		temp.push_back(num);
	}

	sort(temp.begin(), temp.end());
	vi::iterator it = unique(temp.begin(), temp.end());
	candidate.push_back(-1);
	for (vi::iterator i = temp.begin(); i != it; i++) {
		candidate.push_back(*i);
	}
	K = candidate.size()-1;
	backtrack(0, 1, 0);
		
	return 0;
}

