/*
boj_9019_DSLR(난이도 : 골드5)
BFS
문제의 조건에 맞게 노드의 이동을 계산하는 BFS 문제
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
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int T;
int A, B;
std::function<int(int)> operations[4];
string op = { 'D','S','L','R' };

int getDouble(int src) {
	return (src << 1) % 10000;
}

int getSubject(int src) {
	if (src == 0) return 9999;
	else return src - 1;
}

int getLeft(int src) {
	int temp = src / 1000;
	src = (src % 1000) * 10;
	return src + temp;
}

int getRight(int src) {
	int temp = src % 10;
	src = src / 10;
	return src + temp * 1000;
}

typedef struct node {
	int num;
	string str;
}Node;

string solve() {
	bool visited[10000];
	for (int i = 0; i < 10000; i++) visited[i] = 0;

	queue<Node> q;
	q.push({ A, "" });
	visited[A] = 1;

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			Node now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int num = operations[k](now.num);
				if (num == B)
					return now.str + op[k];
				if (visited[num] == 0) {
					visited[num] = 1;
					q.push({ num, now.str + op[k] });
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	operations[0] = getDouble;
	operations[1] = getSubject;
	operations[2] = getLeft;
	operations[3] = getRight;

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> A >> B;
		cout << solve() << "\n";
	}

	return 0;
}
