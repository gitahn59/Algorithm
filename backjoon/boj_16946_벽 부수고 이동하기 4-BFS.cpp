/*
boj_16946_�� �μ��� �̵��ϱ� 4(���̵� : ��� 2)
BFS
�����ҵ��� ã�� �� �������� ������ Ž��
��,��,��,�� �� �Ҵ�� �±װ��� Ȯ���ϰ�
�� �±׿� �ش��ϴ� �������� �տ� 1�� ���ؼ� ���
��, �±��� �ߺ����� ���� �� �����Ƿ� set���� 
�ߺ��� �����ؼ� ���ؾ� ��
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
typedef set<int> si;

int N, M;
int arr[1002][1002];
int group[1002][1002];
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

int cnt[1000010];
int findConnected(int h, int w, int tag) {
	int num = 1;
	queue<ii> q;
	q.push({ h,w });
	group[h][w] = tag;

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			ii now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int i = now.first + ni[k];
				int j = now.second + nj[k];
				if (i<1 || i> N || j< 1 || j>M) continue;
				if (arr[i][j]) continue;
				if (group[i][j] != tag) {
					group[i][j] = tag;
					num++;
					q.push({ i,j });
				}
			}
		}
	}
	return num;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string str;
	for (int n = 1; n <= N; n++) {
		cin >> str;
		for (int m = 1; m <= M; m++) {
			arr[n][m] = str[m - 1] - '0';
		}
	}

	int tag = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] || group[i][j]) continue;
			int rst = findConnected(i, j, tag);
			cnt[tag] = rst;
			tag++;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) cout << "0";
			else {
				int sum = 0;
				si candidate;
				for (int k = 0; k < 4; k++) {
					int h = ni[k] + i;
					int w = nj[k] + j;
					candidate.insert(group[h][w]);
				}
				for (int i : candidate) {
					sum += cnt[i];
				}
				cout << ((sum + 1) % 10);
			}
		}
		cout << "\n";
	}

	return 0;
}
