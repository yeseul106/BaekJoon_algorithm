import java.util.Scanner;

public class Main_1075 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int f = scanner.nextInt();
		boolean result = false;
	
		int num = n / 100;
		n = num * 100;
		
		while(!result)
		{
			if(n%f==0)
				{
				result = true;
				break;
				}
			n++;
		}
		
		n = n % 100;
		String s = String.format("%02d", n);
		System.out.print(s);
		scanner.close();
	}
}