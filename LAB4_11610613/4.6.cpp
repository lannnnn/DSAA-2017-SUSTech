#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int AtPos = 1e3;
const int maxn = 5e5;
const int maxk = 5e5;
int maxs[maxn], mins[maxn], a[maxn];
int num[AtPos*2+1];
int MAX, MIN;

int main() {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		int n, k, temp;
		queue<int> q;
		scanf("%d %d", &n, &k);
		while (!q.empty()) {
				q.pop();
			}
		memset(num, 0, sizeof(num));
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
			a[i] += AtPos;
			num[a[i]]++;
			q.push(a[i]);
		}
		MAX = AtPos*2;
		MIN = 0;
		while (num[MIN] == 0) {
			++MIN;
		}
		while (num[MAX] == 0) {
			--MAX;
		}
		maxs[k - 1] = MAX;
		mins[k - 1] = MIN;
		for (int i = k ; i < n; i++) {
			scanf("%d", &a[i]);
			a[i] += AtPos;
			num[a[i]]++;
			temp = q.front();
			num[temp]--;
			q.pop();
			q.push(a[i]);

			if (a[i] < MIN) {
				MIN = a[i];
			}
			else { 
				while (num[MIN] == 0) 
					MIN++; 
			}
			if (a[i] > MAX) {
				MAX = a[i];
			}
			else { 
				while (num[MAX] == 0)
					MAX--;
			}
			maxs[i] = MAX;
			mins[i] = MIN;
		}
		for (int i = k - 1 ; i < n; i++) {
			printf("%d ", mins[i] - AtPos);
		}
		printf("\n");
		for (int i = k - 1 ; i < n; i++) {
			printf("%d ", maxs[i] - AtPos);
		}
		printf("\n");
	}
}
