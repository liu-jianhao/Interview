package chapter_9_others;

public class Problem_18_PalindromeNumber {

	public static boolean isPalindrome(int n) {
		if (n == Integer.MIN_VALUE) {
			return false;
		}
		n = Math.abs(n);
		int help = 1;
		while (n / help >= 10) { // ·ÀÖ¹helpÒç³ö
			help *= 10;
		}
		while (n != 0) {
			if (n / help != n % 10) {
				return false;
			}
			n = (n % help) / 10;
			help /= 100;
		}
		return true;
	}

	public static void main(String[] args) {
		int test = -10001;
		System.out.println(isPalindrome(test));

	}

}
