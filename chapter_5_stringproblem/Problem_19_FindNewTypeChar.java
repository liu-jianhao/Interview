package chapter_5_stringproblem;

public class Problem_19_FindNewTypeChar {

	public static String pointNewchar(String s, int k) {
		if (s == null || s.equals("") || k < 0 || k >= s.length()) {
			return "";
		}
		char[] chas = s.toCharArray();
		int uNum = 0;
		for (int i = k - 1; i >= 0; i--) {
			if (!isUpper(chas[i])) {
				break;
			}
			uNum++;
		}
		if ((uNum & 1) == 1) {
			return s.substring(k - 1, k + 1);
		}
		if (isUpper(chas[k])) {
			return s.substring(k, k + 2);
		}
		return String.valueOf(chas[k]);
	}

	public static boolean isUpper(char ch) {
		return !(ch < 'A' || ch > 'Z');
	}

	public static void main(String[] args) {
		String str = "aaABCDEcBCg";
		System.out.println(pointNewchar(str, 7));
		System.out.println(pointNewchar(str, 4));
		System.out.println(pointNewchar(str, 10));

	}

}
