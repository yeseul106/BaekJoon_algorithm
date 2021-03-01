/*
 * 문자열 연습
 */

import java.util.*;
import java.io.*;

public class Main_2941 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int count = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'c' && i + 1 < s.length()) {
				if (s.charAt(i + 1) == '=' || s.charAt(i + 1) == '-') {
					i = i + 1;
				}
			} else if (s.charAt(i) == 'd' && i + 1 < s.length()) {
				if (s.charAt(i + 1) == '-') {
					i = i + 1;
				} else if (i + 2 < s.length()) {
					if (s.charAt(i + 1) == 'z' && s.charAt(i + 2) == '=') {
						i = i + 2;
					}
				}
			} else if (s.charAt(i) == 'l' && i + 1 < s.length()) {
				if (s.charAt(i + 1) == 'j') {
					i = i + 1;
				}
			} else if (s.charAt(i) == 'n' && i + 1 < s.length()) {
				if (s.charAt(i + 1) == 'j') {
					i = i + 1;
				}
			} else if (s.charAt(i) == 's' && i + 1 < s.length()) {
				if (s.charAt(i + 1) == '=') {
					i = i + 1;
				}
			} else if (s.charAt(i) == 'z' && i + 1 < s.length()) {
				if (s.charAt(i + 1) == '=') {
					i = i + 1;
				}
			}
			count++;
		}

		System.out.println(count);
	}
}
