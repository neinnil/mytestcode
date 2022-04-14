#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
	public:
			int calPoints(vector<string>ops) {
				vector<int> scores;
				for (vector<string>::iterator it = ops.begin();
						it != ops.end();
						it++) {
					cout << *it << endl;
					if ( *it == "c") {
						cout << "-----" << endl;
					}
					size_t lenScores = scores.size();
					const char *ts = (*it).c_str();
					if (isalpha(*ts)) {
						cout << ">>> isalpha <<< " << endl;
						if (lenScores < 1) {
							cout << "Invalid... Ignored" << endl;
							continue;
							//return -1;
						}
						if (toupper(*ts) == 'C') {
							scores.pop_back();
						} else if (toupper(*ts) == 'D') {
							scores.push_back(scores.back()*2);
						}
					} else if (isnumber(*ts)) {
						cout << ">>> isnumber <<< " << endl;
						scores.push_back(stol(*it));
					} else {
						if (*ts == '+') {
							if (lenScores <2) { 
								cout << "Invalid.. "<<endl;
								return -1;
							}
							int tmpSumValue = scores[lenScores-1] + scores[lenScores-2];
							scores.push_back(tmpSumValue);
						}
					}
				}
				cout << "==== scores ====" << endl;
				int sumScores = 0;
				while (!scores.empty()) {
					sumScores += scores.back();
					cout << scores.back()<< ", ";
					scores.pop_back();
				}
				cout << endl;
				return sumScores;
			}
};

int main() {
	vector < string > items;
	string item;

	string line;
	getline(cin, line);
	istringstream is(line);

	while (is >> item) {
		items.push_back(item);
	}

	Solution solution;

	cout << endl << "SUM: " << solution.calPoints(items) << endl;
}
