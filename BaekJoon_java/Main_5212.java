import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int c = sc.nextInt();

		char[][] map = new char[r + 2][c + 2];
		for (int i = 0; i < r+2; i++)
			for (int j = 0; j < c+2; j++)
				map[i][j] = '.';

		for (int i = 1; i < r + 1; i++) {
			String s = sc.next();
			for (int j = 1; j < c + 1; j++)
				map[i][j] = s.charAt(j - 1);
		}
		
		char[][] newmap = new char[r + 2][c + 2];
		for (int i = 0; i < r + 2; i++) {
			for (int j = 0; j < c + 2; j++)
				newmap[i][j] = map[i][j];
		}
		

		for (int i = 1; i < r + 1; i++) {
			for (int j = 1; j < c + 1; j++) {
				int count = 0;
				if (map[i][j] == 'X') {
					if (map[i - 1][j] == '.')
						count++;
					if (map[i][j - 1] == '.')
						count++;
					if (map[i + 1][j] == '.')
						count++;
					if (map[i][j + 1] == '.')
						count++;
					if (count >= 3)
						newmap[i][j] = '.';
				}
			}
		}
		
//		for (int i = 0; i < r+2; i++) {
//			for (int j = 0; j < c+2; j++)
//				System.out.print(newmap[i][j]);
//			System.out.println();
//		}

		int startr = r + 1;
		int lastr = 0;
		int startc = c + 1;
		int lastc = 0;

		for (int i = 0; i < r + 2; i++) {
			for (int j = 0; j < c + 2; j++) {
				if (newmap[i][j] == 'X') {
					startr = (i < startr) ? i : startr;
					startc = (j < startc) ? j : startc;
					lastr = (i > lastr) ? i : lastr;
					lastc = (j > lastc) ? j : lastc;
				}
			}
		}
		
//		System.out.println (startr + " " + lastr+ " " + startc + " " + lastc);

//		for (int i = startr; i <= lastr; i++) {
//			for (int j = startc; j <= lastc; j++)
//				System.out.print(newmap[i][j]);
//			System.out.println();
//		}
		
		for (int i = startr ; i <= lastr; i++) {
			for (int j = startc; j <= lastc; j++)
				System.out.print(newmap[i][j]);
			System.out.println();
		}
		sc.close();
	}
}
