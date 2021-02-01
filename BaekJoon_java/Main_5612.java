import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int in;
		int out;
		int max = m;

		for (int i = 0; i < n; i++) {
			in = sc.nextInt();
			out = sc.nextInt();
			m = m + in - out;

			if (m < 0) {
				max = 0;
				break;
			}
			if (max < m)
				max = m;
		}

		System.out.print(max);
		sc.close();
	}
}
