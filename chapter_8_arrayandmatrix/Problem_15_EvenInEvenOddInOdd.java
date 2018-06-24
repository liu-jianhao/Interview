package chapter_8_arrayandmatrix;

public class Problem_15_EvenInEvenOddInOdd {

	public static void modify(int[] arr) {
		if (arr == null || arr.length < 2) {
			return;
		}
		int even = 0;
		int odd = 1;
		int end = arr.length - 1;
		while (even <= end && odd <= end) {
			printArray(arr);
			if ((arr[end] & 1) == 0) {
				swap(arr, end, even);
				even += 2;
			} else {
				swap(arr, end, odd);
				odd += 2;
			}
		}
	}

	public static void swap(int[] arr, int index1, int index2) {
		int tmp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = tmp;
	}

	public static void printArray(int[] arr) {
		for (int i = 0; i != arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		int[] arr = { 1, 8, 3, 2, 4, 6 };
		printArray(arr);
		modify(arr);
		printArray(arr);

	}

}
