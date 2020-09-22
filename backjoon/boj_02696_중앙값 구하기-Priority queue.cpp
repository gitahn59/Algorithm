/*
boj_2896_중앙값 구하기(난이도 : 골드3)
Priority queue
우선순위 큐를 활용한 중앙값 탐색
두 개의 우선순위 큐를 활용하여
big, small 큐를 두고 값을 이동시키면서
실시간 쿼리에 대해 O(1)시간에 중앙값 탐색
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

int T;
int M;

void task() {
	priority_queue<int> big, small;

	cin >> M;
	cout << (M + 1) / 2 << "\n";
	int num;
	if (M == 1) {
		cin >> num;
		cout << num << "\n";
		return;
	}
	else if (M == 2) {
		cin >> num;
		cout << num << "\n";
		cin >> num;
		return;
	}
	else {
		cin >> num;
		cout << num << " ";
		int snd;
		cin >> snd;
		if (num < snd) {
			small.push(num);
			big.push(-snd);
		}
		else {
			small.push(snd);
			big.push(-num);
		}
	}

	int cnt = 1;
	for (int m = 2; m < M; m++) {
		cin >> num;
		if (m % 2 == 0) {
			if (num >= -big.top()) {
				big.push(-num);
				cout << -big.top() << " ";
			}
			else if (num <= small.top()) {
				small.push(num);
				int temp = small.top();
				small.pop();
				big.push(-temp);
				cout << -big.top() << " ";
			}
			else {
				big.push(-num);
				cout << -big.top() << " ";
			}
			cnt++;
			if (cnt == 10) {
				cnt = 0;
				cout << "\n";
			}
		}
		else {
			if (num >= -big.top()) {
				big.push(-num);
				int temp = -big.top();
				big.pop();
				small.push(temp);
			}
			else if (num <= small.top()) {
				small.push(num);
			}
			else {
				small.push(num);
			}
		}
	}

	cout << "\n";
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		task();
	}

	return 0;
}


