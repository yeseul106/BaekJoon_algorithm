import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		String s = scanner.next();
		String str[] = new String[5];
		
		//str 첫번째 줄 & 다섯번째 줄
		str[0] = "..#..";
		str[4] = "..#..";
		for(int i=1; i< s.length(); i++)
		{
			if(i%3==2) //3의 배수 위치는 웬디 프레임 (".*..")
				{
					str[0] += ".*..";
					str[4] += ".*..";	
				}
			else
				{
					str[0] += ".#..";
					str[4] += ".#..";
				}
		}
		//str 두번째 줄& 네번째 줄
		str[1] = ".#.#.";
		str[3] = ".#.#.";
		for(int i=1; i<s.length(); i++)
		{
			if(i%3==2)
			{
				str[1] += "*.*.";
				str[3] += "*.*.";	
			}
			else
			{
				str[1] += "#.#.";
				str[3] += "#.#.";	
			}
		}
		//str 세번쨰 줄 (문자 출력)
		str[2] = "#." + s.charAt(0) + ".#";
		for(int i=1; i<s.length(); i++)
		{
			if(i%3==1)
				{
				str[2] += "." + s.charAt(i);
				if(i == s.length()-1)
					str[2] += ".#";
				else
					str[2] += ".*";
				}
			else if(i%3==2)
				str[2] += "." + s.charAt(i) + ".*";
			else
				str[2] += "." + s.charAt(i)+ ".#";
		}
		
		for(int i=0; i<str.length; i++)
			System.out.println(str[i]);
	
	scanner.close();
	}
}