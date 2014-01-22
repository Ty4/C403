/* by Tyler Davidson
 *
 * Musical Plagiarism: 		(Strings)
 *
 */

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<string, int> Scale;

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
		if (result < 0)	result += 12;
		intervals << result << " ";
		first = second;
	}

	return intervals.str();
}

// reads from standard in, notes of the song or snippet, returns the
// string containing those notes
string readLine(const int M)
{
	char input[3];
	string line;

	for (int i = 0; i < M; ++i){
		scanf("%s", input);
	 	line.push_back(input[0]);
		if (input[1])
			line.push_back(input[1]);
		line.push_back(' ');
	}

	return line;
}

bool stillReading(const int M, const int T)
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
	while(stillReading(M, T)){

		// read in song
		song = readLine(M);
		// transfer song into string of intervals
		songInt = procIntervals(song);
		// // read in snippet
		snippet = readLine(T);
		// // transfer snippet into string of intevals
		snipInt = procIntervals(snippet);

		result = songInt.find(snipInt);
		if (result != string::npos)
			printf("S\n");
		else printf("N\n");

		scanf("%d %d", &M, &T);
		// printf("M: %d T: %d\n", M, T);
	}

	return 0;
}
