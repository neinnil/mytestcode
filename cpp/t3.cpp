#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
	public:
			int calPoints(vector<int> &arr){
				int res = -1;
				struct myv { int key, freq ;};

				vector <struct myv> mm;

				for (int i=0; i<arr.size(); i++) {
					int j = 0;
					for (j=0; j<mm.size(); j++) {
						if (mm[j].key == arr[i]) {
							mm[j].freq++ ;
							cout << "> " << mm[j].key <<", "<<mm[j].freq << endl;
							break;
						}
					}
					if (j==mm.size()){
						struct myv _m = {arr[i], 1};
						mm.push_back(_m);
					}
				}

				for (int i=0; i<mm.size(); i++) {
					cout << ">> " << mm[i].key <<", "<<mm[i].freq << endl;
					if ( mm[i].key == mm[i].freq ) {
						if (mm[i].key > res) {
							res = mm[i].key;
						}
					}
				}

				return res;
			};
};

int main() {
	vector < int > items;
	int item;

	string line;
	getline(cin, line);
	istringstream is(line);

	while (is >> item) {
		items.push_back(item);
	}

	Solution solution;

	cout << endl << "Luckey: " << solution.calPoints(items) << endl;
}
