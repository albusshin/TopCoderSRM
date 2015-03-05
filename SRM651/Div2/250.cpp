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

class RobotOnMoonEasy {
public:
	pair<int, int> getij(vector<string> &board) {
		for (int i=0; i<board.size(); i++) {
			for (int j=0; j<board[0].length(); j++) {
				if (board[i][j] == 'S')
					return pair<int, int>(i, j);
			}
		}
		return make_pair(-1, -1);
	}
	string isSafeCommand(vector <string> board, string S) {
		for (char c : S) {
			pair<int, int> ij = getij(board);
			int i = ij.first, j = ij.second;
			int newi = i, newj = j;
			switch (c) {
			case 'U':
				newi = i - 1; break;
			case 'L':
				newj = j - 1; break;
			case 'D':
				newi = i + 1; break;
			case 'R':
				newj = j + 1; break;
			default: break;
			}
			if (newi < 0 || newi >= board.size() || newj < 0 || newj >= board[0].size())
				return "Dead";
			else if (board[newi][newj] == '#') continue;
			else if (board[newi][newj] == '.') {
				board[newi][newj] = 'S';
				board[i][j] = '.';
			}
		}
		return "Alive";
	}
};
/*
int main() {
	RobotOnMoonEasy r;
	vector<string> vs;
	vs.push_back( ".....");
	vs.push_back(".###.");
	vs.push_back("..S..");
	vs.push_back("...#.");
	r.isSafeCommand(vs, "URURURURUR");
}
*/