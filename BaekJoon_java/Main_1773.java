import java.util.Scanner;

public class Main_1773 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int N = scanner.nextInt();
		int C = scanner.nextInt();

		int[] Array = new int[N];
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			Array[i] = scanner.nextInt();
		}
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k < Array.length; k++) {
				if (j % Array[k] == 0) {
					cnt++;
					break;
				}
			}
		}

		System.out.print(cnt);
		scanner.close();
	}
}