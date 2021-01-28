import java.io.*;
import java.util.*;


public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String fruit = bf.readLine();
		StringTokenizer st = new StringTokenizer(fruit);
	    
		double orange, apple, pineapple;
		orange = Double.parseDouble(st.nextToken());
		apple = Double.parseDouble(st.nextToken());
		pineapple = Double.parseDouble(st.nextToken());

		String number= bf.readLine();
		StringTokenizer stn = new StringTokenizer(number);
		
		double numOfOrange, numOfApple, numOfPineapple;
		numOfOrange = Double.parseDouble(stn.nextToken());
		numOfApple = Double.parseDouble(stn.nextToken());
		numOfPineapple = Double.parseDouble(stn.nextToken());
		
		double o1, a1, p1;
	    o1 = orange / numOfOrange;
	    a1 = apple / numOfApple;
	    p1 = pineapple / numOfPineapple;

	    double cnt = Math.min(o1, Math.min(a1, p1));

	    double o2, a2, p2;
	    o2 = cnt * numOfOrange;
	    a2 = cnt * numOfApple;
	    p2 = cnt * numOfPineapple;

	   System.out.printf("%.6f %.6f %.6f\n", orange-o2, apple-a2, pineapple-p2);
	}
}
