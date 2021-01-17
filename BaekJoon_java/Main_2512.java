import java.util.*;
import java.io.*;

public class Main {
	

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[] array = new int[n];

		String mc = br.readLine();
		StringTokenizer st = new StringTokenizer(mc);
		int sum = 0;

		for (int i = 0; i < n; i++) {
			array[i] = Integer.parseInt(st.nextToken());
			sum += array[i];
		}

		Arrays.sort(array);
		
		int total = Integer.parseInt(br.readLine());
		int cnt=array.length;
		int result=0;
		
		for(int i=0; i<array.length;i++) {
			if(total-array[i]*(cnt-i)<0)
			{
				result = total/(cnt-i);
				break;
			}
			else
				total-= array[i];
		}
		
		if(result==0)
			System.out.print(array[n-1]);
		else
			System.out.print(result);
		
	}
}
