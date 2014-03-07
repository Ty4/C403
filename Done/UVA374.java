/* by Tyler Davidson
 *
 * Big Mod: 		(Number Theory)
 *
 * This program uses the Java BigInteger class with the built-in modPow
 * function.
 */

import java.math.BigInteger;
import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(sc.hasNextInt()){
			BigInteger B = BigInteger.valueOf(sc.nextInt());
			BigInteger P = BigInteger.valueOf(sc.nextInt());
			BigInteger M = BigInteger.valueOf(sc.nextInt());

			BigInteger res = B.modPow(P, M);
			System.out.println(res);
		}
	}
}
