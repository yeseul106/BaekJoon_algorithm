import java.util.Scanner;

public class Main {

   static long save[][] = new long[31][31];

   static long pill(int w, int h) {
      if (save[w][h] > 0)
         return save[w][h];
      if (w == 0 && h == 0)
         return 1;
      if (w > 0)
         save[w][h] += pill(w - 1, h + 1);
      if (h > 0)
         save[w][h] += pill(w, h - 1);

      return save[w][h];

   }

   public static void main(String[] args) {
      Scanner s = new Scanner(System.in);
      int n;
      while (true) {
         n = s.nextInt();
         if (n == 0)
            break;
         System.out.println(pill(n, 0));
      }
      s.close();

   }
}