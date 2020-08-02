/*
boj__(난이도 : )
트리 순회
포스트 오더와 인오더의 성질을 이용하여
트리의 구조를 추리

포스트 오더
4 5 1 6 3 (2) 포스트 오더의 성질로 인해 2가 부모 노드임이 명확함
4 5 1 6 3 은 왼쪽 또는 오른쪽 자식노드가 됨

인오더
4 1 5 (2) 6 3 : 포스트오더의 성질로 2가 부모노드임을 알수 있음
4 1 5 는 외쪽 자식노드
6 3 은 오른쪽 자식노드

따라서 포스트 오더, 인오더의 두 순서를 결합하면 일정 영역의
노드들의 부모 자식 관계를 알 수 있음

이를 분할 정복하면 됨
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

int post[100001];
int post_idx_of_num[100001];
int in[100001];
int in_idx_of_num[100001];
int N;

int iilen(ii a) {
	return a.second - a.first + 1;
}

string solve() {
	stack<ii> q;
	vi rst;
	q.push({ 0,N - 1 });
	q.push({ 0,N - 1 });
	while (!q.empty()) {
		ii postnow = q.top(); q.pop();
		ii innow = q.top(); q.pop();

		int len = iilen(postnow);
		if (len < 1) continue;
		rst.push_back(post[postnow.second]);

		int inmididx = in_idx_of_num[post[postnow.second]];
		ii inleft = { innow.first, inmididx - 1 };
		ii inright = { inmididx + 1, innow.second };

		ii postleft = { postnow.first, postnow.first + iilen(inleft) - 1 };
		ii postright = { postnow.first + iilen(inleft), postnow.second - 1 };

		q.push(inright);
		q.push(postright);

		q.push(inleft);
		q.push(postleft);
	}

	string str = "";
	for (auto i : rst) {
		str += to_string(i) + ' ';
	}

	return str;

}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num = 0;
	for (int n = 0; n < N; n++) {
		cin >> num;
		in_idx_of_num[num] = n;
		in[n] = num;
	}

	for (int n = 0; n < N; n++) {
		cin >> num;
		post_idx_of_num[num] = n;
		post[n] = num;
	}

	cout << solve() << "\n";

	return 0;
}
