#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iterator>
#include <numeric>
using namespace std;

	long long gcd(long long a, long long b) {
		while (true) {
			if (!a) return b;
			b %= a;
			if (!b) return a;
			a %= b;
		}
	}

	long long lcm(long long a, long long b) {
		long long l = gcd(a, b);
		return l ? (a / l * b) : 0;
	}

class ThePermutationGameDiv2{
public: 

	long long findMin(int N) {
		long long res = 1L;
		/*for (long long i = 1L; i <= N; i++) {
			res = lcm(res, i);
		}
		*/
		long long ans = 1L;
		for (long int i = 1; i <= N; i++) {
			ans = ans / gcd(ans, i);
			ans = i * ans;
		}
		//return res;
		return ans;
	}
};

int main() {
	ThePermutationGameDiv2 s;
	cout << s.findMin(25);
}