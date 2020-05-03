/*
pro_60062_외벽점검(난이도 : level 3)
완전탐색
외벽의 취약점들에 대해서 
가능한 모든 순서와, 가능한 모든 친구의 순서로
완전탐색
weak의 길이가 벽의 취약점의 순서는 고정되고 길이가 15이하이므로
15가지 순서가 있음
친구의 수가 8이하이므로 8! = 40320
따라서 15 * 40320 의 시간복잡도를 가짐

주의)
후보에 의해 조건검사를 하는 부분이 까다로움
1. 길이가 친구가 가능한 거리보다 짧으면 큐에서 뺴기만하고
2. 길이가 더 길면 친구의 투입수를 올려주어야 함
3. 큐에 남은 취약점이 1개이면, 그 크기에 상관없이 무조건 가능하므로
그냥 break 해주면 됨
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

int N, M;
int len[16];
int candidate[9];

int myCheck() {
	queue<int> qi;
	for (int n = 1; n <= N; n++) {
		qi.push(len[n]);
	}

	int myMin = M + 1;
	for (int n = 1; n <= N; n++) {
		int temp = qi.front();
		{
			queue<int> q = qi;
			int m = 1;
			int now = 0;
			while (!q.empty() && m <= M) {
				if (q.size() == 1) {
					break;
				}
				if (now + q.front() <= candidate[m]) {
					now += q.front();
					q.pop();
				}
				else {
					q.pop();
					now = 0;
					m++;
				}
			}
			myMin = min(myMin, m);
		}
		qi.pop();
		qi.push(temp);
	}

	return myMin;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	N = weak.size();
	if (n == 1) return 1;

	for (int n = 1; n < N; n++) {
		len[n] = weak[n] - weak[n - 1];
	}
	len[N] = n + weak[0] - weak[N - 1];
	M = dist.size();

	int per[] = { 0,1,2,3,4,5,6,7 };
	int myMin = M + 1;
	// O(8!) = 40320
	do {
		for (int m = 1; m <= M; m++) {
			candidate[m] = dist[per[m - 1]];
		}
		myMin = min(myMin, myCheck());
	} while (next_permutation(per, per + M));

	if (myMin > M) return -1;
	else return myMin;
}


int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution(12, { 1, 5, 6, 10 }, { 1, 2, 3, 4 });


	return 0;
}
