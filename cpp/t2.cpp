#include <iostream>
using namespace std;
class Solution
{
	public:
	bool isValid (string s)
	{
		string opens = "({[";
		string closes = ")}]";
		string retstr = "";
		for (int i=0;i<s.length(); i++ ) {
			size_t found;
			if (opens.find(s[i])!=string::npos) {
				retstr += s[i];
				cout <<"<"<< retstr << ">\n";
			} else if ((found = closes.find(s[i])) != string::npos) {
				cout << "<;;" << retstr << ">\n";
				if (retstr.back() != opens[found]) return false;
				retstr.pop_back();
				cout << "<" << retstr << ">\n";
			} else {
				return false;
			}
		}
		return retstr.length()==0?true:false;
	};
	bool isValid2(string s)
	{
		string opens = " [{(";
		string closes = " ]})";
		char *traval;
		const char *p = s.c_str();
		struct {
			int count;
			char array[128];
		} mycontainer = {0, {0,}};
		if (s.length() < 1 || s.length() > 128) {
			cout << "Out of range.\n";
			return false;
		}
		for (traval = (char*)p; *traval!='\0' ; traval++) {
			char val = *traval;
			cout<< val << endl;
			size_t ofound = opens.find(val);
			if ( ofound != string::npos) {
				cout << "Open bracket Found at: "<<ofound << '\n';
				mycontainer.array[mycontainer.count++] = val; //ofound;
			}
			size_t cfound = closes.find(val);
			if ( cfound != string::npos) {
				cout << "Close bracket Found at: "<<cfound << '\n';
				if (mycontainer.count < 1){
					cout << "Something wrong.. "<<endl;
					return false;
				}
				if (mycontainer.array[mycontainer.count-1] != val) {
					cout << mycontainer.array << endl;
					cout << "Last ("<<mycontainer.count-1<<") bracket: " 
						<< mycontainer.array[mycontainer.count-1] << endl;
					return false;
				}
				mycontainer.array[--mycontainer.count] = 0;
			}
			if (ofound == string::npos && cfound == string::npos) {
				cout << "Invalid character\n";
				return false;
			}
		}
		if (mycontainer.count > 0) return false;
		return true;
	};
};

int main()
{
	string input;
	cin >> input;
	Solution solution;
	if (solution.isValid(input))
		cout << "valid";
	else
		cout << "invalid";
	return 0;
}
