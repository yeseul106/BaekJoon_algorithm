import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);

		int n = scanner.nextInt();
		int count = 1;
		int len = 10;

		double result = 0;

		for (int i = 1; i <= n; i++)
		{
			if (i == len) {
				count++;
				len = len * 10;
			}
			result += count;
		}
		System.out.format("%.0f", result);
		scanner.close();
	}
}