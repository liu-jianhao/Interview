package chapter_9_others;

public class Problem_07_ReservoirSampling {

	// 一个简单的随机函数，决定一个事情做还是不做
	public static int rand(int max) {
		return (int) (Math.random() * max) + 1;
	}

	public static int[] getKNumsRand(int k, int max) {
		if (max < 1 || k < 1) {
			return null;
		}
		int[] res = new int[Math.min(k, max)];
		for (int i = 0; i != res.length; i++) {
			res[i] = i + 1; // 前k个数直接进袋子
		}
		for (int i = k + 1; i < max + 1; i++) {
			if (rand(i) <= k) { // 决定i进不进袋子
				res[rand(k) - 1] = i; // i随机替掉袋子中的一个
			}
		}
		return res;
	}

	public static void printArray(int[] arr) {
		for (int i = 0; i != arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		int[] res = getKNumsRand(10, 10000);
		printArray(res);
	}

}
