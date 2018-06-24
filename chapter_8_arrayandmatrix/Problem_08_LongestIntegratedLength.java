package chapter_8_arrayandmatrix;

import java.util.Arrays;
import java.util.HashSet;

public class Problem_08_LongestIntegratedLength {

	public static int getLIL1(int[] arr) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		int len = 0;
		for (int i = 0; i < arr.length; i++) {
			for (int j = i; j < arr.length; j++) {
				if (isIntegrated(arr, i, j)) {
					len = Math.max(len, j - i + 1);
				}
			}
		}
		return len;
	}

	public static boolean isIntegrated(int[] arr, int left, int right) {
		int[] newArr = Arrays.copyOfRange(arr, left, right + 1); // O(N)
		Arrays.sort(newArr); // O(N*logN)
		for (int i = 1; i < newArr.length; i++) {
			if (newArr[i - 1] != newArr[i] - 1) {
				return false;
			}
		}
		return true;
	}

	public static int getLIL2(int[] arr) {
		if (arr == null || arr.length == 0) {
			return 0;
		}
		int len = 0;
		int max = 0;
		int min = 0;
		HashSet<Integer> set = new HashSet<Integer>(); // 判断重复
		for (int i = 0; i < arr.length; i++) {
			max = Integer.MIN_VALUE;
			min = Integer.MAX_VALUE;
			for (int j = i; j < arr.length; j++) {
				if (set.contains(arr[j])) {
					break;
				}
				set.add(arr[j]);
				max = Math.max(max, arr[j]);
				min = Math.min(min, arr[j]);
				if (max - min == j - i) { // 新的检查方式
					len = Math.max(len, j - i + 1);
				}
			}
			set.clear();
		}
		return len;
	}

	public static void main(String[] args) {
		int[] arr = { 5, 5, 3, 2, 6, 4, 3 };
		System.out.println(getLIL1(arr));
		System.out.println(getLIL2(arr));

	}

}
