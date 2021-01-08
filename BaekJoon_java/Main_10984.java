import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(bf.readLine());

		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(bf.readLine());
			int c=0; float g=0;
			
			for(int j=0; j<n; j++) {
				String s = bf.readLine();
				StringTokenizer st = new StringTokenizer(s);
				int subject = Integer.parseInt(st.nextToken());
				float score = Float.parseFloat(st.nextToken());
				
				g += subject*score;
				c += subject;
			}
			
			System.out.println(c + " " + Math.round(g/c*10)/10.0);

		}
	}
}
