import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine());
		String s = bf.readLine();
		StringTokenizer st = new StringTokenizer(s);

		int[] array = new int[n];

		for (int i = 0; i < n; i++)
			array[i] = Integer.parseInt(st.nextToken());

		int start = array[0];
		int end = 0;

		int max = 0;
		int result = 0;

		for (int i = 1; i < n; i++) {
			if (array[i - 1] >= array[i]) {
				end = array[i - 1];
				result = end - start;
				if (max < result)
					max = result;
				start = array[i];
				end = 0;
			}
			if (i == n - 1 && end == 0) {
				end = array[i];
				result = end - start;
				if (max < result)
					max = result;
			}

		}
		System.out.print(max);
	}
}
//8
//12 20 1 3 4 4 11 1
//10
