package chapter_9_others;

public class Problem_21_ChineseExpression {

	public static String num1To9(int num) {
		if (num < 1 || num > 9) {
			return "";
		}
		String[] names = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
		return names[num - 1];
	}

	public static String num1To99(int num, boolean hasBai) {
		if (num < 1 || num > 99) {
			return "";
		}
		if (num < 10) {
			return num1To9(num);
		}
		int shi = num / 10;
		if (shi == 1 && (!hasBai)) {
			return "十" + num1To9(num % 10);
		} else {
			return num1To9(shi) + "十" + num1To9(num % 10);
		}
	}

	public static String num1To999(int num) {
		if (num < 1 || num > 999) {
			return "";
		}
		if (num < 100) {
			return num1To99(num, false);
		}
		String res = num1To9(num / 100) + "百";
		int rest = num % 100;
		if (rest == 0) {
			return res;
		} else if (rest >= 10) {
			res += num1To99(rest, true);
		} else {
			res += "零" + num1To9(rest);
		}
		return res;
	}

	public static String num1To9999(int num) {
		if (num < 1 || num > 9999) {
			return "";
		}
		if (num < 1000) {
			return num1To999(num);
		}
		String res = num1To9(num / 1000) + "千";
		int rest = num % 1000;
		if (rest == 0) {
			return res;
		} else if (rest >= 100) {
			res += num1To999(rest);
		} else {
			res += "零" + num1To99(rest, false);
		}
		return res;
	}

	public static String num1To99999999(int num) {
		if (num < 1 || num > 99999999) {
			return "";
		}
		int wan = num / 10000;
		int rest = num % 10000;
		if (wan == 0) {
			return num1To9999(rest);
		}
		String res = num1To9999(wan) + "万";
		if (rest == 0) {
			return res;
		} else {
			if (rest < 1000) {
				return res + "零" + num1To999(rest);
			} else {
				return res + num1To9999(rest);
			}
		}
	}

	public static String getNumChiExp(int num) {
		if (num == 0) {
			return "零";
		}
		String res = num < 0 ? "负" : "";
		int yi = Math.abs(num / 100000000);
		int rest = Math.abs((num % 100000000));
		if (yi == 0) {
			return res + num1To99999999(rest);
		}
		res += num1To9999(yi) + "亿";
		if (rest == 0) {
			return res;
		} else {
			if (rest < 10000000) {
				return res + "零" + num1To99999999(rest);
			} else {
				return res + num1To99999999(rest);
			}
		}
	}

	// for test
	public static int generateRandomNum() {
		boolean isNeg = Math.random() > 0.5 ? false : true;
		int value = (int) (Math.random() * Integer.MIN_VALUE);
		return isNeg ? value : -value;
	}

	public static void main(String[] args) {
		System.out.println(0);
		System.out.println(getNumChiExp(0));

		System.out.println(Integer.MAX_VALUE);
		System.out.println(getNumChiExp(Integer.MAX_VALUE));

		System.out.println(Integer.MIN_VALUE);
		System.out.println(getNumChiExp(Integer.MIN_VALUE));

		int num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumChiExp(num));

		num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumChiExp(num));

		num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumChiExp(num));

		num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumChiExp(num));

		System.out.println(getNumChiExp(10));
		System.out.println(getNumChiExp(110));
		System.out.println(getNumChiExp(1010));
		System.out.println(getNumChiExp(10010));
		System.out.println(getNumChiExp(1900000000));
		System.out.println(getNumChiExp(1000000010));
		System.out.println(getNumChiExp(1010100010));

	}
}
