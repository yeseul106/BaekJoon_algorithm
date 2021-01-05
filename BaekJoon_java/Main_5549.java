import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(bf.readLine());
		
		int[][][] map = new int[m+1][n+1][3];

		String s;
		for (int i = 1; i <= m; i++) {
			s = bf.readLine();
			for(int)
		}
			
			
		int[][] result = new int[k][3];
		int[] point = new int[4];
		
		for (int i = 0; i < k; i++) {
			StringTokenizer ss = new StringTokenizer(bf.readLine());
			for (int j = 0; j < 4; j++)
				point[j] = Integer.parseInt(ss.nextToken());

			result[i][0] = 0;
			result[i][1] = 0;
			result[i][2] = 0;
			
			for (int e = point[0] - 1; e < point[2]; e++)
				for (int f = point[1] - 1; f < point[3]; f++) {
					char ch = map[e].charAt(f);
					switch (ch) {
					case 'J':
						result[i][0]++;
						break;
					case 'O':
						result[i][1]++;
						break;
					case 'I':
						result[i][2]++;
						break;
					}
				}
		}

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 3; j++)
				System.out.print(result[i][j] + " ");
			System.out.println();
		}
	}
}
