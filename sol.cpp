#include <bits/stdc++.h>
using namespace std;

void perform_test() {
	int n;
	cin >> n;
	int sz = n * 2 + 1;
	int center = sz / 2;
	//0 -> [center, center]
	//1 -> [center - 1, center + 1]
	//2 -> [center - 2, center + 2]
	//...
	//sz - i - 1, [center - sz, center + sz]
	int a[sz][sz];
	bool visit_number[sz][sz];
	bool visit_space[sz][sz];
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz; j++) {
			a[i][j] = 0;
			visit_number[i][j] = false;
			visit_space[i][j] = false;
		}
	}
	int ending[sz];
	for(int i = 0; i < sz; i++) {
		ending[i] = -1;
	}
	for(int i = 0; i < sz; i++) {
		int start = center;
		int end = center;
		if(i <= center) {
			start = start - i;
			end = end + i;
		} else {
			start = start - (sz - i - 1);
			end = end + (sz - i - 1);
		}
		ending[i] = end;
		// visit numbers
		int val = 0;
		for(int j = start; j <= end; j++) {
			a[i][j] = val;
			if(j < sz / 2) {
				val++;
			} else {
				val--;
			}
			visit_number[i][j] = true;
		}
		// visit spaces
		for(int j = 0; j <= end; j++) {
			visit_space[i][j] = true;
		}
	}
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz; j++) {
			if(visit_number[i][j]) {
				cout << a[i][j];
				if(j < ending[i]) {
					cout << " ";
				}
			} else if(visit_space[i][j]) {
				cout << "  ";
			}
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	//cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}

