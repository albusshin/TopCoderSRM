#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <unordered_map> 
using namespace std; 

class XorSequenceEasy 
{
private:
	int getCount(vector<int> C) {
		int res = 0;
		for (int i=0; i<C.size(); i++) {
			for (int j=i+1; j<C.size(); j++) {
				if (C[i] < C[j]) res++;
			}
		}
		return res;
	}
public: 
	int getmax(vector <int> A, int N) {
		int res = getCount(A);
		for (int b = N; b > 0; b >>= 1) {
			for (int i=0; i<A.size(); i++) {
				A[i] = A[i] ^ b;
			}
			int count = getCount(A);
			if (count > res) res = count;
			else {
				for (int i=0; i<A.size(); i++) {
					A[i] = A[i] ^ b;
				}
			}
		}
		return res;
	} 
};