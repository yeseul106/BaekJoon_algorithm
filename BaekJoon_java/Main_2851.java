import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] mushroom = new int[10];
		int score = 0;
		int result = 0;
		int temp = 0;

		for (int i = 0; i < 10; i++)
			mushroom[i] = sc.nextInt();

		score = mushroom[0];

		for (int i = 1; i < 10; i++) {
			score += mushroom[i];
			if (score > 100) {
				temp = score - mushroom[i];
				break;
			}
		}
		int subtemp = (int) Math.abs(temp - 100);
		int subscore = (int) Math.abs(score - 100);
		
		if (subtemp == subscore)
			result = (temp > score) ? temp : score;
		else
			result = (subtemp < subscore) ? temp : score;
		
		System.out.print(result);
		sc.close();
	}
}
