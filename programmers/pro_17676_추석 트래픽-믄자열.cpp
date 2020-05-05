/*
pro_17676_추석 트래픽(난이도 : level 3)
문자열

처리량의 변화는 task의 시작, 끝시간에서만 변화함
따라서 각 시간의 전후 1000ms로 후보를 선정하고(최대 4000)
모든 작업에 대해 최대 처리량을 계산
O(8000 * 2000)시간에 처리 가능
주의)
시간 계산시 시작시간과 끝시간을 포함하기 때문에 
계산과정에서 1ms 를 빼야 함


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

int N;
ii arr[2001];
vii timetable;

ii getTime(char* time, char* spand) {
	char* p = strtok(time, ":");
	int h = stoi(p);
	p = strtok(NULL, ":");
	int m = stoi(p);
	p = strtok(NULL, ":");
	double s = stod(p);

	p = strtok(spand, "s");
	double st = stod(p);

	int left = (h * 3600 + m * 60) * 1000 + s * 1000;
	int right = st * 1000;
	return { left - right + 1,left };
}

int solution(vector<string> lines) {
	N = lines.size();

	char str[100];
	char* tm, * spand;

	for (int n = 1; n <= N; n++) {
		strcpy(str + 1, lines[n - 1].c_str());
		char* p = strtok(str + 1, " ");
		tm = strtok(NULL, " ");
		spand = strtok(NULL, " ");
		arr[n] = getTime(tm, spand);
		timetable.push_back({ arr[n].first - 1000 + 1, arr[n].first });
		timetable.push_back({ arr[n].first, arr[n].first + 1000 - 1 });
		timetable.push_back({ arr[n].second - 1000 + 1, arr[n].second });
		timetable.push_back({ arr[n].second, arr[n].second + 1000 - 1 });
	}

	int myMax = 1;
	for (ii now : timetable) {
		int cnt = 0;
		for (int n = 1; n <= N; n++) {
			if (arr[n].first > now.second || now.first > arr[n].second)
				continue;
			else cnt++;
		}
		myMax = max(myMax, cnt);
	}

	int answer = myMax;
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution({ "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s" });

	return 0;
}