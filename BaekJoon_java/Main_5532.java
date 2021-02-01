import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int L = scanner.nextInt();
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int C = scanner.nextInt();
		int D = scanner.nextInt();
		
		int count = L;
		
		while(true)
		{
			A -= C;
			B -= D;
			count--;
			if(A<=0 && B<=0)
				break;
		}
		
		System.out.print(count);
		
	scanner.close();
	}
}