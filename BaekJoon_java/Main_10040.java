import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		
		int[] money = new int[N];
		int[] result = new int[N];
		
		for(int i=0; i<N; i++)
		{
			money[i] = scanner.nextInt();
			result[i] = 0;
		}
		for(int i=0; i<M; i++)
		{
			int B = scanner.nextInt();
			for(int j=0;j<N;j++)
			{
				if(money[j]<=B)
					{
					result[j]++;
					break;
					}
			}
		}
		int max = 0; int index=0;
		
		for(int i=0; i<N;i++)
			{
			if(result[i]>max)
				{
				max = result[i];
				index =i+1;
				}
			}
		System.out.print(index);
	scanner.close();
	}
}