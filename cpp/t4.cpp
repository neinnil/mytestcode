#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;
static int depth = 0;
class Solution
{
	public:
		string buildParen(int z)
		{
			string ret = "";
			for (int j =0 ;j<z; j++) {
				ret += '(';
			}
			for (int j =0 ;j<z; j++) {
				ret += ')';
			}
			return ret;
		};
		vector<string> calPoints (int n)
		{
			struct _pattern {char pp[2];} pattern = {'(',')'};
			vector <string> ret;
			if (n==0) return ret;
			depth++;
			//cout <<depth<<" [ "<<n<< " ]- Enter --------------------------\n";
			string rr = buildParen(n);
			//cout <<n<<": "<< rr << endl;
			ret.push_back(rr);
			for (int i=n-1; i>0; i--) {
				rr = buildParen(i);
				for (int j=n-i; j>0 ; j--) {
					if (i+j < n) break;
					//cout <<"[ "<<n<<", "<<i<<", "<<j<<", "<< rr<< " ]\n";
					vector <string> subp = calPoints(j);
					while(!subp.empty()){
						ret.push_back(rr+subp.back());
						//cout <<"[ "<<n<<", "<<i<<", "<<j<<"subp : "<< rr<<", "<<subp.back() << endl;
						subp.pop_back();
					}
				}
			}
			//for (int i=0;i<ret.size(); i++){
				//cout << ret[i] << endl;
			//}
			//cout << depth <<"--- Leave ----------[ "<<n<< " ]--\n";
			depth--;
			return ret;
		};
	
};

int main() {
	int item;

	string line;
	getline(cin, line);
	istringstream is(line);
	is >> item;

	Solution solution;

	vector <string> ret = solution.calPoints(item) ;
	cout << endl << "[\n" << ret.size() << "\n"; 
	for (int i=0; i<ret.size(); i++) {
		cout << ret[i] << ", ";
	}
	cout << "\n]"<<endl;
}
