import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

public class Main {

	static int size, count = 0;
	static HashMap<String, Integer> hm = new HashMap<>();
	static Stack<String> stack = new Stack<>();

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		size = input.nextInt();
		for (int i = 1; i <= size; i++) {
			hm.put(input.next(), i);
		}
		for (int i = 0; i < size; i++) {
			stack.add(input.next());
		}
		
		calc();
		System.out.println(count);
	}

	private static void calc() {
		int target = stack.size();
		while (!stack.isEmpty()) {
			String temp = stack.pop();
			int num = hm.get(temp);

			if (target >= num) {
				target = Math.min(stack.size(), num);
			} else {
				count++;
			}
		}
	}
}

