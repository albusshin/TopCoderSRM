#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class FoxAndSouvenirTheNext {
public:
	string ableToSplit(vector <int> value) {
		if (value.size() % 2) return "Impossible";
		sort(value.begin(), value.end());
		int sum = 0;
		for (auto ite = value.begin(); ite != value.end(); ++ite) {
			sum += *ite;
		}
		if (sum % 2) return "Impossible";
		int desired = sum / 2;
		for (int i=0; i<=value.size()/2; i++) {
			sum = 0;
			for (int j=i; j<i+value.size()/2; j++) {
				sum += value[j];
			}
			if (sum == desired) return "Possible";
		}
		return "Impossible";
	}
};