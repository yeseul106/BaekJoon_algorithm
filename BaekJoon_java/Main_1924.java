import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		String[] days = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
		int[] inMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		
		int total= y;
		
		for(int i=0; i< x-1;i++)
		{
			total += inMonth[i];
		}
		
		System.out.println(days[(total%7)]);
	scanner.close();
	}
}