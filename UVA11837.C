/* by Tyler Davidson
 *
 * Musical Plagiarism: 		(Strings)
 *
 */

#include <cstdio>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<string, int> Scale;

void initMap()
{
	Scale["A"] = 1;
	Scale["A#"] = Scale["Bb"] = 2;
	Scale["B"] = 3;
	Scale["C"] = 4;
	Scale["C#"] = Scale["Db"] = 5;
	Scale["D"] = 6;
	Scale["D#"] = Scale["Eb"] = 7;
	Scale["E"] = 8;
	Scale["F"] = 9;
	Scale["F#"] = Scale["Gb"] = 10;
	Scale["G"] = 11;
	Scale["G#"] = Scale["Ab"] = 12;
}

// takes a string of notes as input, returns a string representing
// the intervals between the notes
string procIntervals(const string & song)
{
	stringstream intervals;
	stringstream songStream(song);
	string first, second;
	songStream >> first;
	while (songStream >> second){
		int result = (Scale[second] - Scale[first])%12;
		if (result < 0) result += 12;
		intervals << result << " ";
		first = second;
	}

	return intervals.str();
}

// reads from standard in, notes of the song or snippet, returns the
// string containing those notes
string readLine(const int M)
{
	string line;
	for (int i = 0; i < M; ++i){
		char tmp[2];
		scanf("%s", tmp);
		if (tmp[1]){
			line.push_back(tmp[0]);
			line.push_back(tmp[1]);
		}
		else
			line.push_back(tmp[0]);
		line.push_back(' ');
	}

	return line;
}

bool validInput(const int M, const int T)
{
	return ((M != 0) && (T != 0));
}

int main()
{
	int M, T;
	size_t result;
	string song, songInt;
	string snippet, snipInt;

	initMap();

	scanf("%d %d", &M, &T);
	while(validInput(M, T)){

		// read in song
		song = readLine(M);
		// transfer song into string of intervals
		songInt = procIntervals(song);
		// read in snippet
		snippet = readLine(T);
		// transfer snippet into string of intevals
		snipInt = procIntervals(snippet);

		result = songInt.find(snipInt);
		if (result != string::npos)
			printf("S\n");
		else printf("N\n");

		scanf("%d %d", &M, &T);
	}

	return 0;
}
