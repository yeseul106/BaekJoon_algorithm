import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p = sc.nextInt();
		int w = sc.nextInt();
		sc.nextLine();
		String s = sc.nextLine();
		int result = 0;

		int[] botton = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
		int[] time = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };

		char now;
		char before;

		for (int i = 0; i < s.length(); i++) {

			if (i == 0) {
				now = s.charAt(i);
				result += time[now - 'A'] * p;
				continue;
			}
			now = s.charAt(i);
			before = s.charAt(i - 1);
			if (now >= 'A' && now <= 'Z' && before >= 'A' && before <= 'Z') {
				if (botton[now - 'A'] == botton[before - 'A'])
					result += w;
			} 
			if(now >= 'A' && now <= 'Z' )result += time[now - 'A'] * p;
			else
				result += p;
		}
		System.out.print(result);
		sc.close();
	}
}