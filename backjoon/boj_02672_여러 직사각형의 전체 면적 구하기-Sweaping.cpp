/*
boj_2672_여러 직사각형의 전체 면적 구하기(난이도 : 골드2)
Sweaping
좌표평면의 영역을 y좌표를 기준으로 각각 자름 (최대 30개 => 60개 좌표)
그러면 yn, yn+1 영역에 대해 이를 포함하는 직사각형들의
가로폭만 구하면 됨

가로폭은 여러 직사각형들이 서로 겹칠 수 있음
따라서 스위핑을 통해, 중복없이 포함되는 길이만 계산해야 함
(boj 2170 선 긋기 참고)
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

typedef struct square {
	double x, y, a, b;
}Square;
typedef pair<double, double> dd;

int N;
Square arr[30];
bool myCmp(Square a, Square b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

double None = 10000;

int main() {
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	double x, y, w, h;
	vector<double> y_values;
	for (int n = 0; n < N; n++) {
		cin >> x >> y >> w >> h;
		arr[n] = { x,y,x + w,y + h };
		y_values.push_back(arr[n].y);
		y_values.push_back(arr[n].b);
	}
	sort(arr, arr + N, myCmp);
	sort(y_values.begin(), y_values.end());

	int M = y_values.size();
	double rst = 0;
	for (int m = 0; m < M - 1; m++) {
		dd now = { y_values[m], y_values[m + 1] };
		dd range = { None,None };
		double len = 0;
		for (int n = 0; n < N; n++) {
			if (arr[n].y <= now.first && now.second <= arr[n].b) {
				if (range.first == None) {
					range = { arr[n].x, arr[n].a };
					len = range.second - range.first;
				}
				else {
					if (range.second >= arr[n].x) {
						if (range.second <= arr[n].a) {
							len += (arr[n].a - range.second);
							range.second = arr[n].a;
						}
					}
					else {
						range.second = arr[n].a;
						len += (arr[n].a - arr[n].x);
					}
				}
			}
		}
		rst += len * (now.second - now.first);
	}
	double temp = rst * 100;
	if (((ll)temp) % 100 == 0) {
		cout << (ll)rst << "\n";
	}
	else {
		printf("%.2lf\n", rst);
	}

	return 0;
}


