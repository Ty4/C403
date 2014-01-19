/* by Tyler Davidson
 *
 * Army Buddies:	NONTRIVIAL	(Data Structures)
 *
 * This program keeps a list of soldiers, and each soldier is aware of who is
 *    to the left and right of him. For each L R pair, it updates the values
 *    of the left and right neighbours of each of L and R.
 *
 * Lesson Learned in this problem: C++ cin is considerably slower than scanf.
 *    switching took my program from > 1 second runtime to 0.168 seconds.
 */

#include <cstdio>
#include <iostream>

using namespace std;

struct soldier
{
	int left, right;
};

soldier line[100001];

int main()
{
	int S, B; // soldiers and loss reports, respectively

	scanf("%d %d", &S, &B);

	while ((S != 0) && (B != 0)){
		soldier *line = new soldier[S+1];
		int L, R;

		// for each soldier, init who his left and right neighbours are
		for (int i = 1; i <= S; ++i){
			line[i].left = i-1;
			line[i].right = i+1;
		}
		line[S].right = 0;

		for (int report = 1; report <= B; ++report){
			scanf("%d %d", &L, &R);

			// check left buddy
			if (line[L].left == 0)	printf("* ");
			else printf("%d ", line[L].left);
			// check right buddy
			if (line[R].right == 0)	printf("*\n");
			else printf("%d\n", line[R].right);

			// update the buddys
			line[line[L].left].right = line[R].right;
			line[line[R].right].left = line[L].left;
		}

		printf("-\n");

		delete [] line;
		scanf("%d %d", &S, &B);
	}

	return 0;
}