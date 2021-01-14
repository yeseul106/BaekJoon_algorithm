import java.util.Scanner;

public class Main {

	public static void main(String[] args)  {
		// TODO Auto-generated method stub
        Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		int one = 0;
		int two = 0;
		int three = 1;
		
		if(Math.abs(N) <= 1) {
			System.out.println(Math.abs(N));
			System.out.println(Math.abs(N));
			return;
		}
		
		boolean minus = false;
		if(N < 0)
			minus = true;
		N = Math.abs(N);
		
		for(int i = 2 ; i <= N ; i++) {
			one = two;
			two = three;
			three = (one + two) % 1000000000;
		}
		
		if(minus && N % 2 == 0)
			System.out.println(-1);
		else
			System.out.println(1);
		System.out.println(three);
	}
}
