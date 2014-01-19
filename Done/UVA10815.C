/* by Tyler Davidson
 *
 * Andy's First Dictionary:		(Data Structures)
 *
 * Input: a file containing text consisting of words and other symbols.
 * Ouput: a list of words that make up the newly formed dictionary.
 *
 * Instead of reading in and parsing an entire line, this program reads in the
 *   file a token at a time (delimited by a space). It then parses that token,
 *   looking for alphabet character strings of at least one character. Once
 *   an non-alpha character is found, the word that was being formed is added
 *   to the dictionary.
 * Since STL sets maintain a (in this case, alphabetical) sorted order, there
 *   is no need to sort the set before outputting it.
 */

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
