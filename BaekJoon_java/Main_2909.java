import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int price = scanner.nextInt();
		int k = scanner.nextInt();
		
		int money = (int)(Math.pow(10, k));
		int mod = price % money;
		int result=0;
		
		if(mod>=money/2)
			result = (price/money)*money + money;
		else
			result = (price/money)*money;
		
		System.out.println(result);
	scanner.close();
	}
}