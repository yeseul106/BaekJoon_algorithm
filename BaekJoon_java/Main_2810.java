import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		int i = 0;

		int cup = n + 1;

		while (i + 2 <= s.length()) {
			if (s.substring(i, i + 2).equals("LL")) {
				cup--;
				i += 2;
			} else
				i++;
		}

		if (cup > n)
			System.out.println(n);
		else
			System.out.println(cup);
		sc.close();
	}
}
