import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int alpha[] = new int[26];
		boolean check;
		String s;
		for (int i = 0; i < n; i++) {
			s = sc.next();
			check= true;

			for (int k = 0; k < 26; k++)
				alpha[k] = 0;

			for (int j = 0; j < s.length(); j++) {
				alpha[s.charAt(j) - 65]++;

				if (alpha[s.charAt(j) - 65] == 3)
					if (j + 1 < s.length() && s.charAt(j + 1) != (s.charAt(j))) {
						check = false;
						break;
					} else if (j == s.length() - 1) {
						check = false;
						break;
					} else if (j + 1 < s.length() && s.charAt(j + 1) == (s.charAt(j)))
						alpha[s.charAt(j) - 65]=-1;
			}

			if (check)
				System.out.println("OK");
			else
				System.out.println("FAKE");
		}

		sc.close();
	}
}
