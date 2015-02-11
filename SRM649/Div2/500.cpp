#include <algorithm>
#include <iostream>
using namespace std;

class CartInSupermarketEasy {
private:
	int m[101][101];
public: 
	CartInSupermarketEasy() {
		for (int i=0; i<101; i++) for (int j=0; j<101; j++) m[i][j] = 0;
	}
	int calc(int N, int K) {
		if (m[N][K] != 0) return m[N][K];
		int res = N;
		for (int i=1; i<=N/2; i++) {
			for (int j=0; j<K; j++) {
				res = min(res, max(calc(i, j), calc(N-i, K-j-1)) + 1);
			}
		}
		m[N][K] = res;
		return res;
	}
};