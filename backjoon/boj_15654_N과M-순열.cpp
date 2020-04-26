/*
boj_15654_N과 M(난이도 : 실버3)
순열
next_permutation을 이용한 중복체크 및 출력
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
int arr[9];
int order[] = { 0,1,2,3,4,5,6,7,8 };
set<string> ss;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}
	sort(arr + 1, arr + 1 + N);

	do {
		string str = "";
		for (int m = 1; m <= M; m++) {
			str += (order[m] + '0');
		}
		if (ss.find(str) != ss.end()) continue;
		else ss.insert(str);

		for (int m = 1; m <= M; m++) {
			cout << arr[order[m]] << " ";
		}
		cout << "\n";
	} while (next_permutation(order + 1, order + N + 1));

	return 0;
}

