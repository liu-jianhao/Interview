package chapter_9_others;

public class Problem_20_SortedRatateArrayFindNum {

	public static boolean isContains(int[] arr, int num) {
		int low = 0;
		int high = arr.length - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (arr[mid] == num) {
				return true;
			}
			if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
				while (low != mid && arr[low] == arr[mid]) {
					low++;
				}
				if (low == mid) {
					low = mid + 1;
					continue;
				}
			}
			if (arr[low] != arr[mid]) {
				if (arr[mid] > arr[low]) {
					if (num >= arr[low] && num < arr[mid]) {
						high = mid - 1;
					} else {
						low = mid + 1;
					}
				} else {
					if (num > arr[mid] && num <= arr[high]) {
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				}
			} else {
				if (arr[mid] < arr[high]) {
					if (num > arr[mid] && num <= arr[high]) {
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				} else {
					if (num >= arr[low] && num < arr[mid]) {
						high = mid - 1;
					} else {
						low = mid + 1;
					}
				}
			}
		}
		return false;
	}

	public static void main(String[] args) {
		int[] arr = { 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 1, 2, 3, 4, 5 };
		int num = 10;
		System.out.println(isContains(arr, num));

	}
}
