/*
pro_42892_길 찾기 게임(난이도 : level3)
tree
트리의 각 노드를 입력받아 규칙에 맞게
트리를 생성하는 문제
실제 트리를 구현하는게 제일 빠르게 구현할 수 있음
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

vi vl;
vi vr;

typedef struct node {
	int idx, x, y;
	struct node* left;
	struct node* right;

	bool operator< (const node& b) const {
		if (y == b.y) {
			return x < b.x;
		}
		else return y > b.y;
	}

	node(int a, int b, int c) {
		idx = a; x = b; y = c;
		left = 0;
		right = 0;
	}

	node() {
		left = 0;
		right = 0;
	}

	void insert(node nd) {
		if (x < nd.x) {
			if (right == nullptr) {
				right = new node();
				*right = nd;
			}
			else {
				right->insert(nd);
			}
		}
		else {
			if (left == nullptr) {
				left = new node();
				*left = nd;
			}
			else {
				left->insert(nd);
			}
		}
	}

	void pre() {
		vl.push_back(idx);
		if (left != nullptr) {
			left->pre();
		}
		if (right != nullptr) {
			right->pre();
		}
	}

	void post() {
		if (left != nullptr) {
			left->post();
		}
		if (right != nullptr) {
			right->post();
		}
		vr.push_back(idx);
	}
}Node;

Node nodes[10001];
Node cpy[10001];
int N;
vi adj[10001];
int depth[1001];

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	N = nodeinfo.size();
	for (int n = 1; n <= N; n++) {
		nodes[n] = { n,nodeinfo[n - 1][0], nodeinfo[n - 1][1] };
		cpy[n] = { n,nodeinfo[n - 1][0], nodeinfo[n - 1][1] };
	}
	sort(cpy + 1, cpy + 1 + N);

	Node tree = cpy[1];
	for (int n = 2; n <= N; n++) {
		tree.insert(cpy[n]);
	}
	tree.pre();
	tree.post();

	vector<vector<int>> answer;
	answer.push_back(vl);
	answer.push_back(vr);
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });

	return 0;
}
