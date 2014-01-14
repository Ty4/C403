#include <algorithm>	// for transform
#include <cctype>		// for tolower
#include <iostream>
#include <set>
#include <string>

using namespace std;

void findWords(string buffer, set<string> & dic)
{
	string tmp;
	string::iterator it = buffer.begin();

	for (; it != buffer.end(); ++it){
		if (isalpha(*it)) tmp.push_back(*it);
		else if (!isalpha(*it) && tmp.size() > 0){
			// convert to lower
			transform(tmp.begin(), tmp.end(),
				tmp.begin(), ::tolower);
			// add to dictionary
			dic.insert(tmp);
			tmp.clear();
		}
	}
	if (tmp.size() > 0){
		transform(tmp.begin(), tmp.end(),
			tmp.begin(), ::tolower);
		dic.insert(tmp);
	}
}

int main()
{
	string buffer, tmp;
	set<string> dictionary;

	while(cin >> buffer){
		findWords(buffer, dictionary);
	}

	// print out dictionary
	for (set<string>::iterator it = dictionary.begin(); 
			it != dictionary.end(); ++it)
		cout << *it << endl;

	return 0;
}
