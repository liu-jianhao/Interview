package chapter_9_others;

public class Problem_19_SortedRatateArrayFindMin {

	public static int getMin(int[] arr) {
		int low = 0;
		int high = arr.length - 1;
		int mid = 0;
		while (low < high) {
			if (low == high - 1) {
				break;
			}
			if (arr[low] < arr[high]) {
				return arr[low];
			}
			mid = (low + high) / 2;
			if (arr[low] > arr[mid]) {
				high = mid;
				continue;
			}
			if (arr[mid] > arr[high]) {
				low = mid;
				continue;
			}
			while (low < mid) {
				if (arr[low] == arr[mid]) {
					low++;
				} else if (arr[low] < arr[mid]) {
					return arr[low];
				} else {
					high = mid;
					break;
				}
			}
		}
		return Math.min(arr[low], arr[high]);
	}

	public static void main(String[] args) {
		int[] test = { 4, 5, 5, 5, 1, 2, 3 };
		System.out.println(getMin(test));

	}

}
