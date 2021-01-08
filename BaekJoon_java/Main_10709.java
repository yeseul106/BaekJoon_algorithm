import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String s = bf.readLine();
		StringTokenizer st = new StringTokenizer(s);

		int h = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());

		boolean contain = false;
		int count = 0;

		for (int i = 0; i < h; i++) {
			String arr = bf.readLine();
			for (int j = 0; j < w; j++) {
				if (arr.charAt(j) == '.' && contain == false)
					System.out.print("-1 ");
				else if (arr.charAt(j) == '.' && contain == true) {
					System.out.print(count + " ");
					count++;
				} else if (arr.charAt(j) == 'c') {
					System.out.print("0 ");
					contain = true;
					count = 1;
				}
			}
			System.out.println();
			count = 0;
			contain = false;
		}
	}
}
