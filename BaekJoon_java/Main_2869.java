import java.util.*;
import java.io.*;

public class Main {
	static int listSize;

	static int binarySearch(int low, int high, int reach, int sub, int up) {

		int day = 0;
		int mid = reach / 2;
		while (low <= high) {

			day = mid / sub;

			if (reach - (sub * day) > up)
				low = mid;
			else if (reach - (sub * day) == up) {
				break;
			} else {
				if (mid + up - reach >= sub)
					high = mid;
				else
					break;
			}
			mid = (low + high) / 2;
		}

		return day+1;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int V = Integer.parseInt(st.nextToken());

		int result = binarySearch(0, V, V, A - B, A);

		System.out.print(result);
	}

}