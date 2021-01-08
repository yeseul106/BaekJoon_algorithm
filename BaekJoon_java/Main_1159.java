import java.util.Scanner;

public class Main_1159 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		int n = scanner.nextInt();
		int array[]= new int[26]; //알파벳 개수
		
		for(int i=0; i<n; i++)
		{
		String s = scanner.next();
		array[s.charAt(0)-'a']++;
		}
		
		boolean bool = false;
		
		for(int i=0; i<26; i++)
		{
			if(array[i] >=5 )
				{
				System.out.print((char)(i+'a'));
				bool = true;
				}
		}
		if(!bool)
			System.out.print("PREDAJA");
		scanner.close();
	}
}