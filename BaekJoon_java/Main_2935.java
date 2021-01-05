import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BigInteger A = new BigInteger(bf.readLine());
		String s = bf.readLine();
		char op = s.charAt(0);
		BigInteger B = new BigInteger(bf.readLine());

		switch (op) {
		case '*':
			System.out.println(A.multiply(B));
			break;
		case '+':
			System.out.println(A.add(B));
			break;
		}
	}
}
