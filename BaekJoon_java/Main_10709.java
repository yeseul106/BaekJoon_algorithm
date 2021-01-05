import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String s = bf.readLine();
		StringTokenizer st = new StringTokenizer(s);

		int h = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());
		
		int[][] array = new int[h][w];
		
		boolean contain = false;
		int count = 0;

		for (int i = 0; i < h; i++) {
			String arr = bf.readLine();
			for (int j = 0; j < w; j++) {
				if (arr.charAt(j) == '.' && contain == false)
					array[i][j] = -1;
				else if (arr.charAt(j) == '.' && contain == true) {
					array[i][j] = count;
					count++;
				} else if (arr.charAt(j) == 'c') {
					array[i][j] = 0;
					contain = true;
					count = 1;
				}
			}
			count = 0;
			contain = false;
		}
		
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++)
				System.out.print(array[i][j] + " ");
			System.out.println();
		}
	}
}
