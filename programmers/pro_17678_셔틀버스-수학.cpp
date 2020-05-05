/*
pro_17678_셔틀버스(난이도 : level 3)
수학
마지막 버스 전에
최대한 태울수 있는 사람을 제외하고
남아있는 인원들 중에서 M등인 사람보다 1분 빨리오면 됨
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

int S, N, T, M;
int bus[11];
int arr[2001];

int solve() {
	int num = 1;
	for (int n = 1; n < N; n++) {
		int cnt = 0;
		for (; num <= S && cnt < M; num++) {
			if (arr[num] <= bus[n]) {
				cnt++;
			}
			else {
				break;
			}
		}
	}

	int remain = S - num + 1;
	if (remain < M) {
		return bus[N];
	}
	else {
		return min(bus[N], arr[num + M - 1] - 1);
	}
}

string solution(int n, int t, int m, vector<string> timetable) {
	S = timetable.size();
	N = n, T = t, M = m;

	char str[10];
	for (int s = 1; s <= S; s++) {
		strcpy(str, timetable[s - 1].c_str());
		char* p = strtok(str, ":");
		int tm = stoi(p) * 60;
		p = strtok(NULL, ":");
		tm += stoi(p);
		arr[s] = tm;
	}
	sort(arr + 1, arr + 1 + S);

	int start = 9 * 60;
	for (int i = 1; i <= N; i++) {
		bus[i] = start;
		start += t;
	}

	int rst = solve();
	int hh = rst / 60;
	int mm = rst % 60;

	sprintf(str, "%02d:%02d", hh, mm);
	string answer = str;
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });

	return 0;
}
