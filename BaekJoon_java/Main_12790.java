import java.util.Scanner;

public class Main {
	public static int total(int p, int newp){
		if(p+newp<1)
			return 1;
		else
			return p+newp;
	}
	
	public static int totalattack(int a, int newa){
		if(a+newa<0)
			return 0;
		else
			return a+newa;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int N = scanner.nextInt();
		int[] resultArray = new int[N];
		for(int i=0; i<N; i++)
		{
			int HP = scanner.nextInt();
			int MP = scanner.nextInt();
			int attack = scanner.nextInt();
			int defense = scanner.nextInt();
			
			int newHP = scanner.nextInt();
			int newMP = scanner.nextInt();
			int newAttack = scanner.nextInt();
			int newDefense = scanner.nextInt();
			
			int result = 1 * total(HP,newHP) + 5 * total(MP,newMP) + 2 * totalattack(attack,newAttack) + 2 * (defense+newDefense);
			resultArray[i] = result;
		}
		
		for(int i=0; i<N; i++)
			System.out.println(resultArray[i]);
		scanner.close();
	}
}