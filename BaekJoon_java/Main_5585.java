import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int money= scanner.nextInt();
		int change = 1000-money;
		int num=0;
		
		int mon[] = {500, 100, 50, 10, 5, 1};
		
		while (change !=0)
		{
			for(int i=0; i<mon.length; i++)
				{
				num += change/mon[i];
				change=change%mon[i];
				}
		}
		System.out.print(num);
		scanner.close();
	}

}
