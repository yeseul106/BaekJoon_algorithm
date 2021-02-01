import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] array = new int[n][3];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				array[i][j] = sc.nextInt();
		
		int score[] = new int[n];

		for (int i = 0; i < n; i++)
			score[i] = 0;

		for (int j = 0; j < n; j++)
			for (int i = 0; i < 3; i++) {
				boolean check = true;
				for (int k = 0; k < n; k++) {
					if (k == j)
						continue;
					if (array[j][i] == array[k][i]) {
						check = false;
						break;
					}
				}
				if (check)
					score[j] += array[j][i];
			}

		for (int i = 0; i < n; i++)
			System.out.println(score[i]);
		sc.close();
	}
}
