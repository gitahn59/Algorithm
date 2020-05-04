/*
pro_42890_후보키(난이도 : level2 )
Bitmask
비트 와이즈 연산을 통해 후보들을 선정하고
각 후보마다 자기보다 작은 후보들 중에서 
중복여부를 & 연산을 통해서 확인
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

string arr[21][9];
int N, M;
int selected[9];

bool myCheck(int selected) {
	string target[21];
	for (int n = 1; n <= N; n++) {
		string rst;
		for (int i = 1; i <= M; i++) {
			if ((1 << i) & selected) {
				rst += arr[n][i];
			}
		}
		target[n] = rst;
	}
	sort(target + 1, target + N + 1);
	auto it = unique(target + 1, target + N + 1);
	if (target + N + 1 == it) {
		return true;
	}
	return false;
}

int solve() {
	int end = (1 << (M + 1)) - 1;
	vi rst;

	for (int m = 1; m <= M; m++) {
		for (int num = 2; num <= end; num++) {
			int cnt = 0;
			if (1 & num) continue;
			for (int j = 1; j <= M; j++) {
				if (1 << j & num) cnt++;
			}
			if (cnt == m) {
				bool flag = true;
				for (int child : rst) {
					int temp = child & num;
					if (temp == child) {
						flag = false;
						break;
					}
				}

				if (flag && myCheck(num)) {
					rst.push_back(num);
				}
			}
		}
	}

	return rst.size();
}



int solution(vector<vector<string>> relation) {
	N = relation.size();
	M = relation[0].size();
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			arr[n][m] = relation[n - 1][m - 1];
		}
	}

	int answer = solve();
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution({ {"100","ryan","music","2"}, {"200","apeach","math","2"},
		{"300","tube","computer","3"},{"400","con","computer","4"},
		{"500","muzi","music","3"},{"600","apeach","music","2"} });

	return 0;
}
