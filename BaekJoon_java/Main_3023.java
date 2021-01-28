import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int R = scanner.nextInt();
		int C = scanner.nextInt();
		
		char card[][] = new char[R*2][C*2];
		
		for(int i=0; i<R; i++)
		{
			String s =scanner.next(); //char을 스캐너로 받기 어려워서..
			for(int j=0; j<C; j++)
			 card[i][j]= s.charAt(j);
		}	
		
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
				card[i][C+j] = card[i][C-(j+1)];
		}
		
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C*2; j++)
				card[R+i][j] = card[R-(i+1)][j];
		}
		
		int errorx = scanner.nextInt();
		int errory = scanner.nextInt();
		char ch = card[errorx - 1][errory - 1];
		if(ch == '#') {
			card[errorx - 1][errory - 1] = '.';
		}
		else {
			card[errorx - 1][errory - 1] = '#';
		}
		
		for(int i=0; i<R*2; i++)
		{
			for(int j=0; j<C*2;j++)
				System.out.print(card[i][j]);
			System.out.println();
		}
		scanner.close();
	}
}