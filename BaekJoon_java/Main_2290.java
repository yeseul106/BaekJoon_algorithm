import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String ss = bf.readLine();
		StringTokenizer st = new StringTokenizer(ss);

		int s = Integer.parseInt(st.nextToken());
		String n = st.nextToken();

		for (int h = 0; h < 2 * s + 3; h++) {
			for (int i = 0; i < n.length(); i++) {
				char ch = n.charAt(i);

				// 첫번째 줄 출력
				if (h == 0) {
					if (ch == '1' || ch == '4') {
						for (int k = 0; k < s + 2; k++)
							System.out.print(" ");
					} else {
						System.out.print(" ");
						for (int k = 0; k < s; k++)
							System.out.print("-");
						System.out.print(" ");
					}
				}
				// 위 몸통 부분 출력
				else if (1 <= h && h <= s) {
					if (ch == '1' || ch == '2' || ch == '3' || ch == '7') {
						for (int w = 0; w < s + 1; w++)
							System.out.print(" ");
						System.out.print("|");
					}

					else if (ch == '5' || ch == '6') {
						System.out.print("|");
						for (int w = 0; w < s + 1; w++)
							System.out.print(" ");
					} else {
						System.out.print("|");
						for (int w = 0; w < s; w++)
							System.out.print(" ");
						System.out.print("|");
					}
				}
				// 가운데 부분 출력
				else if (h == s + 1) {
					if (ch == '1' || ch == '7' || ch == '0') {
						for (int k = 0; k < s + 2; k++)
							System.out.print(" ");
					} else {
						System.out.print(" ");
						for (int k = 0; k < s; k++)
							System.out.print("-");
						System.out.print(" ");
					}
				}

				// 밑 몸통 부분 출력
				else if (s + 2 <= h && h <= s * 2 + 1) {
					if (ch == '1' || ch == '3' || ch == '4' || ch == '5' || ch == '7' || ch == '9') {
						for (int w = 0; w < s + 1; w++)
							System.out.print(" ");
						System.out.print("|");
					} else if (ch == '2') {
						System.out.print("|");
						for (int w = 0; w < s + 1; w++)
							System.out.print(" ");
					} else {
						System.out.print("|");
						for (int w = 0; w < s; w++)
							System.out.print(" ");
						System.out.print("|");
					}
				}
				// 마지막 줄 출력
				else {
					if (ch == '1' || ch == '4' || ch=='7') {
						for (int k = 0; k < s + 2; k++)
							System.out.print(" ");
					} else {
						System.out.print(" ");
						for (int k = 0; k < s; k++)
							System.out.print("-");
						System.out.print(" ");
					}
				}
				System.out.print(" ");
			}
			System.out.print('\n');
		}

	}
}
