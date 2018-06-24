package chapter_7_bitoperation;

public class Problem_06_KTimesOneTime {

	public static int onceNum(int[] arr, int k) {
		int[] eO = new int[32];
		for (int i = 0; i != arr.length; i++) {
			setExclusiveOr(eO, arr[i], k);
		}
		int res = getNumFromKSysNum(eO, k);
		return res;
	}

	public static void setExclusiveOr(int[] eO, int value, int k) {
		int[] curKSysNum = getKSysNumFromNum(value, k);
		for (int i = 0; i != eO.length; i++) {
			eO[i] = (eO[i] + curKSysNum[i]) % k;
		}
	}

	public static int[] getKSysNumFromNum(int value, int k) {
		int[] res = new int[32];
		int index = 0;
		while (value != 0) {
			res[index++] = value % k;
			value = value / k;
		}
		return res;
	}

	public static int getNumFromKSysNum(int[] eO, int k) {
		int res = 0;
		for (int i = eO.length - 1; i != -1; i--) {
			res = res * k + eO[i];
		}
		return res;
	}

	public static void main(String[] args) {
		int[] test1 = { 1, 1, 1, 2, 6, 6, 2, 2, 10, 10, 10, 12, 12, 12, 6, 9 };
		System.out.println(onceNum(test1, 3));

		int[] test2 = { -1, -1, -1, -1, -1, 2, 2, 2, 4, 2, 2 };
		System.out.println(onceNum(test2, 5));

	}

}