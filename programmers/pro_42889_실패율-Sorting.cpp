/*
pro_42889_실패율(난이도 : level2)
정렬
각 Stage 별로 도달자 수와, 플레이 중인 수를 계산하여
실패율을 계산
주의) 도달한 사람 수가 0이면 실패율은 0으로 처리
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

typedef struct node {
	int stage;
	double rate;
}Node;

int Sta;
int M;
int arr[502];
int reached[502];
Node nodes[502];

bool myCmp(Node a, Node b) {
	if (a.rate == b.rate) {
		return a.stage < b.stage;
	}
	else {
		return a.rate > b.rate;
	}
}

vector<int> solution(int N, vector<int> stages) {
	Sta = N;
	M = stages.size();

	for (int now : stages) {
		arr[now]++;
		for (int i = 1; i <= now; i++) {
			reached[i]++;
		}
	}

	for (int i = 1; i <= Sta; i++) {
		if (reached[i] == 0) {
			nodes[i] = { i,0 };
		}
		else {
			nodes[i] = { i,(double)arr[i] / (double)reached[i] };
		}
	}
	sort(nodes + 1, nodes + 1 + Sta, myCmp);
	vector<int> answer;
	for (int i = 1; i <= Sta; i++) {
		answer.push_back(nodes[i].stage);
	}

	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution(4, { 4,4,4,4,4 });


	return 0;
}
