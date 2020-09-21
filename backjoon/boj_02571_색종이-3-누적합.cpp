/*
boj_2571_색종이 - 3(난이도 : 골드5)
누적합
누적합을 이용해 직사각형 판별
영역의 

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

int N;
int arr[101][101];
int acc[101][101];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int a, b;
	for (int n = 0; n < N; n++) {
		cin >> a >> b;
		for (int i = a + 1; i <= a + 10; i++) {
			for (int j = b + 1; j <= b + 10; j++) {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1] + arr[i][j];
		}
	}

	int myMax = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int a = 1; a <= i; a++) {
				for (int b = 1; b <= j; b++) {
					int rst = acc[i][j] - acc[i][b - 1] - acc[a - 1][j] + acc[a - 1][b - 1];
					if (rst == 0) continue;
					if (rst == (i - a + 1) * (j - b + 1))
						myMax = max(myMax, rst);
				}
			}
		}
	}

	cout << myMax << "\n";

	return 0;
}


