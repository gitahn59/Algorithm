/*
boj_5536_물고기의 서식 범위(난이도 : 골드2)
Sweeping
각 구역을 구역의 좌표에따라 자르면
최대 100 * 100 * 100, 총 백만 개의 정육면체를 얻을 수 있음
각 정육면체를 포함하는 구역을 모두 검사하여
구역이 기준치 이상이면 그 부피를 모두 결과에 더하면 됨
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

typedef struct arer {
	ll a, b, c;
	ll x, y, z;
}Area;

int N, K;
Area arr[50];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vi cx, cy, cz;
	cin >> N >> K;
	for (int n = 0; n < N; n++) {
		cin >> arr[n].a;
		cx.push_back(arr[n].a);
		cin >> arr[n].b;
		cy.push_back(arr[n].b);
		cin >> arr[n].c;
		cz.push_back(arr[n].c);
		cin >> arr[n].x;
		cx.push_back(arr[n].x);
		cin >> arr[n].y;
		cy.push_back(arr[n].y);
		cin >> arr[n].z;
		cz.push_back(arr[n].z);
	}

	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());
	sort(cz.begin(), cz.end());

	ll rst = 0;
	int M = N << 1;
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			for (int k = 0; k < M - 1; k++) {
				Area now = { cx[i],cy[j], cz[k],
					cx[i + 1], cy[j + 1], cz[k + 1] };
				int cnt = 0;
				for (int n = 0; n < N; n++) {
					if (now.a >= arr[n].a && now.x <= arr[n].x &&
						now.b >= arr[n].b && now.y <= arr[n].y &&
						now.c >= arr[n].c && now.z <= arr[n].z)
						cnt++;
				}
				if (cnt >= K) {
					ll temp = (now.x - now.a) * (now.y - now.b) * (now.z - now.c);
					rst += temp;
				}
			}
		}
	}

	cout << rst << "\n";
	return 0;
}


