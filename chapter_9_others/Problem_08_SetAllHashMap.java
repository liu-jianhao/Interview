package chapter_9_others;

import java.util.HashMap;

public class Problem_08_SetAllHashMap {

	public static class MyValue<V> {
		private V value;
		private long time;

		public MyValue(V value, long time) {
			this.value = value;
			this.time = time;
		}

		public V getValue() {
			return this.value;
		}

		public long getTime() {
			return this.time;
		}
	}

	public static class MyHashMap<K, V> {
		private HashMap<K, MyValue<V>> baseMap;
		private long time;
		private MyValue<V> setAll;

		public MyHashMap() {
			this.baseMap = new HashMap<K, MyValue<V>>();
			this.time = 0;
			this.setAll = new MyValue<V>(null, -1);
		}

		public boolean containsKey(K key) {
			return this.baseMap.containsKey(key);
		}

		public void put(K key, V value) {
			this.baseMap.put(key, new MyValue<V>(value, this.time++));
		}

		public void setAll(V value) {
			this.setAll = new MyValue<V>(value, this.time++);
		}

		public V get(K key) {
			if (this.containsKey(key)) {
				if (this.baseMap.get(key).getTime() > this.setAll.getTime()) {
					return this.baseMap.get(key).getValue();
				} else {
					return this.setAll.getValue();
				}
			} else {
				return null;
			}
		}
	}

	public static void main(String[] args) {
		MyHashMap<String, Integer> test = new MyHashMap<String, Integer>();
		test.put("Tom", 1);
		test.put("James", 2);
		System.out.println(test.containsKey("Tom"));
		System.out.println(test.get("Tom"));
		System.out.println(test.containsKey("James"));
		System.out.println(test.get("James"));
		test.setAll(3);
		test.put("Rose", 4);
		System.out.println(test.get("Tom"));
		System.out.println(test.get("James"));
		System.out.println(test.get("Rose"));
		test.setAll(5);
		System.out.println(test.get("Tom"));
		System.out.println(test.get("James"));
		System.out.println(test.get("Rose"));

	}

}
