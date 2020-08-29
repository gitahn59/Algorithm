/*
pro_67256_키패드 누르기(난이도 : level 1)
완전탐색
키패드의 간격에 따라 cost 배열을 전부 계산하고
모든 반복 수행
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

vi l = { 1,4,7,'*' };
vi m = { 2,5,8,0 };
vi r = { 3,6,9,'#' };
int cost[120][120];
int type[10];

void preprocessing() {
	for (int i : l) {
		type[i] = 0;
	}
	for (int i : r) {
		type[i] = 1;
	}
	for (int i : m) {
		type[i] = 2;
	}

	vvi cst = { { 1,2,3,4 }, {2,1,2,3},{3,2,1,2},{4,3,2,1} };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// 왼손
			cost[l[i]][m[j]] = cst[i][j];
			cost[m[j]][l[i]] = cst[i][j];
			// 오른손
			cost[r[i]][m[j]] = cst[i][j];
			cost[m[j]][r[i]] = cst[i][j];
		}
	}

	cost[2][5] = 1;
	cost[2][8] = 2;
	cost[2][0] = 3;

	cost[5][2] = 1;
	cost[5][8] = 1;
	cost[5][0] = 2;

	cost[8][2] = 2;
	cost[8][5] = 1;
	cost[8][0] = 1;

	cost[0][2] = 3;
	cost[0][5] = 2;
	cost[0][8] = 1;

	for (int i = 0; i <= 9; i++) {
		cost[i][i] = 0;
	}
}


string solution(vector<int> numbers, string hand) {
	string answer = "";

	preprocessing();
	int h;
	if (hand == "left") h = 0;
	else h = 1;
	int left_hand = '*';
	int right_hand = '#';

	for (int num : numbers) {
		int rst = 0;
		if (type[num] == 0) rst = 0;
		else if (type[num] == 1) rst = 1;
		else {
			int len_left = cost[left_hand][num];
			int len_right = cost[right_hand][num];
			if (len_left == len_right) {
				if (h == 0) rst = 0;
				else rst = 1;
			}
			else if (len_left < len_right) rst = 0;
			else rst = 1;
		}

		if (rst == 0) {
			left_hand = num;
			answer += 'L';
		}
		else {
			right_hand = num;
			answer += 'R';
		}
	}

	return answer;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << solution({ 1,1,1,1,1,1 }, "left") << "\n";

	return 0;
}


