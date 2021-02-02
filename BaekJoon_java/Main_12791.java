import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
	
		String array[][] = {{"1967","DavidBowie"}, {"1969","SpaceOddity"}, {"1970", "TheManWhoSoldTheWorld"},
				{"1971", "HunkyDory"}, {"1972", "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"}, {"1973", "AladdinSane"}
				, {"1973", "PinUps"}, {"1974", "DiamondDogs"}, {"1975", "YoungAmericans"}, {"1976", "StationToStation"},
				{"1977", "Low"}, {"1977", "Heroes"}, {"1979", "Lodger"}, {"1980", "ScaryMonstersAndSuperCreeps"}, 
				{"1983", "LetsDance"}, {"1984", "Tonight"}, {"1987", "NeverLetMeDown"}, {"1993", "BlackTieWhiteNoise"},
				{"1995", "1.Outside"}, {"1997", "Earthling"}, {"1999", "Hours"}, {"2002", "Heathen"}, {"2003", "Reality"},
				{"2013", "TheNextDay"}, {"2016", "BlackStar"}};
		
		int Q = scanner.nextInt();
		    while (Q!=0)
		    {
		        int ans = 0;
		        int S = scanner.nextInt();
		        int E = scanner.nextInt();
		        
		        for (int i = 0; i < 25; i++)
		            if (Integer.parseInt(array[i][0]) >= S && Integer.parseInt(array[i][0]) <= E)
		                ans++;
		        System.out.println(ans);
		        
		        for (int i = 0; i < 25; i++)
		            if (Integer.parseInt(array[i][0]) >= S && Integer.parseInt(array[i][0]) <= E)
		                System.out.println(array[i][0]+ " "+ array[i][1]);
		        Q--;
		 
		    }
		scanner.close();
	}
}