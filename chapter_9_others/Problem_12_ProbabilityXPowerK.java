package chapter_9_others;

public class Problem_12_ProbabilityXPowerK {

	public static double randXPower2() {
		return Math.max(Math.random(), Math.random());
	}

	public static double randXPowerK(int k) {
		if (k < 1) {
			return 0;
		}
		double res = -1;
		for (int i = 0; i != k; i++) {
			res = Math.max(res, Math.random());
		}
		return res;
	}

	public static void main(String[] args) {
		double range = 0.5;
		int times = 5000000;
		int count = 0;
		for (int i = 0; i != times; i++) {
			if (randXPowerK(2) < range) {
				count++;
			}
		}
		double p = (double) count / (double) times;
		System.out.println("range [0," + range + "), probability: " + p);
	}
}
