package chapter_9_others;

public class Problem_21_EnglishExpression {

	public static String num1To19(int num) {
		if (num < 1 || num > 19) {
			return "";
		}
		String[] names = { "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
				"Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
				"Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Sixteen ",
				"Eighteen ", "Nineteen " };
		return names[num - 1];
	}

	public static String num1To99(int num) {
		if (num < 1 || num > 99) {
			return "";
		}
		if (num < 20) {
			return num1To19(num);
		}
		int high = num / 10;
		String[] tyNames = { "Twenty ", "Thirty ", "Forty ", "Fifty ",
				"Sixty ", "Seventy ", "Eighty ", "Ninety " };
		return tyNames[high - 2] + num1To19(num % 10);
	}

	public static String num1To999(int num) {
		if (num < 1 || num > 999) {
			return "";
		}
		if (num < 100) {
			return num1To99(num);
		}
		int high = num / 100;
		return num1To19(high) + "Hundred " + num1To99(num % 100);
	}

	public static String getNumEngExp(int num) {
		if (num == 0) {
			return "Zero";
		}
		String res = "";
		if (num < 0) {
			res = "Negative, ";
		}
		if (num == Integer.MIN_VALUE) {
			res += "Two Billion, ";
			num %= -2000000000;
		}
		num = Math.abs(num);
		int high = 1000000000;
		int highIndex = 0;
		String[] names = { "Billion", "Million", "Thousand", "" };
		while (num != 0) {
			int cur = num / high;
			num %= high;
			if (cur != 0) {
				res += num1To999(cur);
				res += names[highIndex] + (num == 0 ? " " : ", ");
			}
			high /= 1000;
			highIndex++;
		}
		return res;
	}

	public static int generateRandomNum() {
		boolean isNeg = Math.random() > 0.5 ? false : true;
		int value = (int) (Math.random() * Integer.MIN_VALUE);
		return isNeg ? value : -value;
	}

	public static void main(String[] args) {
		System.out.println(getNumEngExp(0));
		System.out.println(getNumEngExp(Integer.MAX_VALUE));
		System.out.println(getNumEngExp(Integer.MIN_VALUE));
		int num = generateRandomNum();
		System.out.println(num);
		System.out.println(getNumEngExp(num));

	}

}
