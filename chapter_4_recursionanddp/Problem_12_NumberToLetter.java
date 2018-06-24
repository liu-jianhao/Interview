package chapter_4_recursionanddp;

public class Problem_12_NumberToLetter {

	public static int num1(String str) {
		if (str == null || str.equals("")) {
			return 0;
		}
		char[] chs = str.toCharArray();
		return process(chs, 0);
	}

	public static int process(char[] chs, int i) {
		if (i == chs.length) {
			return 1;
		}
		if (chs[i] == '0') {
			return 0;
		}
		int res = process(chs, i + 1);
		if (i + 1 < chs.length && (chs[i] - '0') * 10 + chs[i + 1] - '0' < 27) {
			res += process(chs, i + 2);
		}
		return res;
	}

	public static int num2(String str) {
		if (str == null || str.equals("")) {
			return 0;
		}
		char[] chs = str.toCharArray();
		int cur = chs[chs.length - 1] == '0' ? 0 : 1;
		int next = 1;
		int tmp = 0;
		for (int i = chs.length - 2; i >= 0; i--) {
			if (chs[i] == '0') {
				next = cur;
				cur = 0;
			} else {
				tmp = cur;
				if ((chs[i] - '0') * 10 + chs[i + 1] - '0' < 27) {
					cur += next;
				}
				next = tmp;
			}
		}
		return cur;
	}

	public static void main(String[] args) {
		String str = "781231783161018231";
		System.out.println(num1(str));
		System.out.println(num2(str));

	}
}
