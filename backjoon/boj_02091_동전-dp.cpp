/*
boj_2091_동전(난이도 : 골드5)
bottomup dp
앞서 사용된 동전의 종류와 갯수를 저장해 두어야 하는 dp
나머지는 일반적인 동전 bottomup dp와 동일함
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

typedef struct node
{
	int arr[5];
	bool updated;

	int getSum() {
		return arr[1] + arr[2] + arr[3] + arr[4];
	}
}Node;

int X, A, B, C, D;
Node mem[10001];
int cnt[5];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> X;
	for (int n = 1; n <= 4; n++) {
		cin >> cnt[n];
	}

	int coin[] = { 0,1,5,10,25 };

	mem[0].updated = 1;
	Node next[10001];
	for (int n = 1; n <= 4; n++) {
		memset(next, 0, sizeof(next));
		for (int c = 1; c <= cnt[n]; c++) {
			int v = coin[n] * c;
			for (int i = 0; i <= X; i++) {
				if (i + v > X) continue;
				if (mem[i].updated) {
					Node temp = mem[i];
					temp.arr[n] += c;
					if (next[i + v].getSum() < temp.getSum()) {
						next[i + v] = temp;
					}
				}
			}
		}
		for (int i = 0; i <= X; i++) {
			if (mem[i].getSum() < next[i].getSum()) {
				mem[i] = next[i];
			}
		}
	}

	if (mem[X].updated == 0) {
		cout << "0 0 0 0\n";
	}
	else {
		for (int n = 1; n <= 4; n++) {
			cout << mem[X].arr[n] << " ";
		}
		cout << "\n";
	}

	return 0;
}
