import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();

		int hotel[][] = new int[n][2];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 2; j++)
				hotel[i][j] = scanner.nextInt();

		int candiD = 0;
		int candiC = 0;
		int count = 0;

		for (int i = 0; i < n; i++) {
			candiD = hotel[i][0];
			candiC = hotel[i][1];

			boolean bool = true;

			for (int j = 0; j < n; j++) {

				if (i == j)
					continue;

				if (candiD >= hotel[j][0]) {
					if (candiC >= hotel[j][1]) {
						bool = false;
						break;
					}
				}
			}

			if (bool)
				count++;
		}

		System.out.println(count);
		scanner.close();
	}
}