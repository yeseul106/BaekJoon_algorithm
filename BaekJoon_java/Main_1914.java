import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static int n;
	static int count = 0;

	static void hanoi(int n, int from, int mid, int to) {
		if (n == 1) {
			System.out.println(from + " " + to);
		}

		else {
			hanoi(n - 1, from, to, mid);
			System.out.println(from + " " + to);
			hanoi(n - 1, mid, from, to);
			
		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		BigInteger pow = new BigInteger("2");
		BigInteger a = pow.pow(n).subtract(BigInteger.ONE);
		System.out.println(a);
		if(n<=20)
			hanoi(n, 1, 2, 3);
		scanner.close();

	}

}
