package chapter_9_others;

public class Problem_17_PrintRandomM {

	public static void printRandM(int[] arr, int m) {
		if (arr == null || arr.length == 0 || m < 0) {
			return;
		}
		m = Math.min(arr.length, m);
		int count = 0;
		int i = 0;
		while (count < m) {
			i = (int) (Math.random() * (arr.length - count));
			System.out.println(arr[i]);
			swap(arr, arr.length - count++ - 1, i);
		}
	}

	public static void swap(int[] arr, int index1, int index2) {
		int tmp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = tmp;
	}

	public static void main(String[] args) {
		int[] arr = { 6, 2, 3, 5, 1, 4 };
		int m = 1;
		printRandM(arr, m);

	}

}
