import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		String n = scanner.next();
		int b = scanner.nextInt();
		
		char c;
		double num=0;
		double sum=0;
		
		for(int i=0; i< n.length() ; i++)
		{
			c = n.charAt(i);
			if(('A' <= c) && (c <='Z'))
				{
				num = ((double)(c-'A')+ 10)* Math.pow(b, n.length()-1-i);
				sum += num;
				}
			else if(('0' <= c) && (c <= '9'))
			{
				num = ((double)(c-'0'))* Math.pow(b, n.length()-1-i);
				sum += num;
			}
			else
				return;
		}
		
		System.out.format("%.0f", sum);
		scanner.close();
	}
}