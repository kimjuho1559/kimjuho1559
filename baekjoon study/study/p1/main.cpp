#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}


int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	int total = v[0].first + v[0].second;
	for (int i = 1; i < N; i++)
	{
		if (total < v[i].first) {
			total = v[i].first;
			total += v[i].second;
		}
		else
			total += v[i].second;
	}
	cout << total;
}