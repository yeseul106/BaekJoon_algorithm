import java.util.*;
import java.io.*;

public class Main_11399 {
	public static void main(String args[]) throws IOException {

	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine());
		StringTokenizer st = new StringTokenizer(bf.readLine());
		
		Vector ATM = new Vector();
		
		for(int i=0; i<n; i++) {
			int tmp = Integer.parseInt(st.nextToken());
			ATM.add(tmp);
		}
		
		Object[] obj = ATM.toArray();
		Arrays.sort(obj);
		
		int result=0;
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<=i;j++){
				result += (int)obj[j];
			}
		}
		
		System.out.println(result);
	}
}
