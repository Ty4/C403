/* by Tyler Davidson
 *
 * Musical Plagiarim: (Strings)
 *
 */

 #include <cstdio>
 #include <cstdlib>
 #include <iostream>

 using namespace std;

 bool stillReading(const int & M, const int & T)
 {
 	return ((M == 0) && (T == 0));
 }

 int main()
 {
 	int songLen, snipLen;

 	scanf("%d %d", &songLen, &snipLen);
 	while (stillReading(songLen, snipLen)){

 		// read in song
 		// compute progression of notes
 		//    store in array
 		// read in snippet
 		// compute progression of notes
 		//    store in aray
 		// find if second is substring of first

 		scanf("%d %d", &songLen, &snipLen);
 	}

 	return 0;
 }