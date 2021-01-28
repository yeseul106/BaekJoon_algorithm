import java.util.Scanner;

public class Main {

	static int min = 1000000;
	static int N;
	static int sArray[] = new int[11];
	static int bArray[] = new int[11];
	static int used[] = new int[11];

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();

		for (int i = 0; i < N; i++) {
			sArray[i] = scanner.nextInt();
			bArray[i] = scanner.nextInt();
		}

		int idx = (int)Math.pow(2, N)-1;
		
		cooking(idx);

		System.out.print(min);
		
		scanner.close();
	}

	static void cooking(int usedIdx) {
		int x=1; int y=0;
		if (usedIdx > 0) {
			int temp = usedIdx;
			for (int i = N - 1; i >= 0; i--) {
				used[i] = temp % 2;
				temp /= 2;
			}
			
			for (int j = 0; j < N; j++) {
				if (used[j] == 1) {
					 x = x * sArray[j];
					 y = y + bArray[j];
				}
			}
			
			int result = Math.abs(x- y);
			min = min > result ? result : min;
			
			cooking(--usedIdx);
		}
	}
}
