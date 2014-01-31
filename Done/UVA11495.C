/* by Tyler Davidson (algorithm found online)
 *
 * Bubbles and Buckets: 	(Sorting)
 *
 * This algorithm works by counting inversions on the game board.
 * Since the problem says the game consists of permutations of 1,2,...,N
 *    all indeces start at 1. It then tests to see if that number is in
 *    it's correct position. If it is, it moves to the next number, if not
 *    it's swapped into the correct position, moving what was there into the
 *    current position. After the swap, it rechecks the current position to
 *    see if the new number is correct.
*/

#include <cstdio>

int game[100001];

int main(void){
	int N;

    scanf("%d", &N);

    while(N != 0){
		bool CarlosWins = true;

        for(int i = 1; i <= N; ++i)
        	scanf("%d", &game[i]);

        for(int i = 1; i <= N;){
        	int tmp;

            if(game[i] != i){
                tmp = game[i];
                game[i] = game[game[i]];
                game[tmp] = tmp;
                CarlosWins = !CarlosWins;
            }
            else
            	++i;
        }

        if(CarlosWins) printf("Carlos\n");
        else printf("Marcelo\n");

        scanf("%d",&N);
    }
    return 0;
}