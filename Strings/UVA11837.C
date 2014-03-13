#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<string, int> Scale;
int M, T;

/* SETUP ********************************************************************/
void initMap()
{
	Scale["A"] = 0;
	Scale["A#"] = Scale["Bb"] = 1;
	Scale["B"] = 2;
	Scale["C"] = 3;
	Scale["C#"] = Scale["Db"] = 4;
	Scale["D"] = 5;
	Scale["D#"] = Scale["Eb"] = 6;
	Scale["E"] = 7;
	Scale["F"] = 8;
	Scale["F#"] = Scale["Gb"] = 9;
	Scale["G"] = 10;
	Scale["G#"] = Scale["Ab"] = 11;
}

bool stillReading(const int M, const int T)
{
	return (M != 0 && T != 0) ? true : false;
}

string readLine(const int length)
{
	string song, note;
	for (int i = 0; i < length; ++i){
		cin >> note;
		song.append(note);
		song.append(" ");
	}
	return song;
}

// takes a string of notes as input, returns a string representing
// the intervals between the notes
string procDifs(const string & song)
{
	stringstream intervals;
	stringstream songStream(song);
	string first, second;

	songStream >> first;
	while (songStream >> second){
		int result = ((Scale[second] - Scale[first]) + 12) %12;
		intervals << result;
		first = second;
	}

	return intervals.str();
}
/* ENDSETUP *****************************************************************/

int main()
{
	string song, snippet;
	cin >> M >> T;

	initMap();
	while(stillReading(M, T)){
		song = readLine(M);
		snippet = readLine(T);

		song = procDifs(song);
		snippet = procDifs(snippet);

		cout << song << endl;
		cout << snippet << endl;

		int result = song.find(snippet);
		if (result >= 0) cout << "S";
		else cout << "N";
		cout << endl;

		cin >> M >> T;
	}

	return 0;
}
