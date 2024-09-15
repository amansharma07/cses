import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.stream.LongStream;

public class ArrayDivision {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) { arr[i] = Long.parseLong(st.nextToken()); }
		br.close();

		long l = Arrays.stream(arr).max().getAsLong();
		long r = Arrays.stream(arr).sum();
		while (l < r) {
			long mid = (l + r) / 2;
			if (is_possible(arr, k, mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		System.out.println(l);
	}

	/**
	 * true if the given `arr` can be divided into `k` subarrays where the sum
	 * of each subarray is at most `max_sum`
	 */
	private static boolean is_possible(long[] arr, int k, long max_sum) {
		// # of subarrays needed if sum of each subarray is at most max_sum
		int subarr_count = 0;
		// sum of the current subarray
		long cur_sum = 0;
		for (long x : arr) {
			if (x > max_sum) { return false; }

			if (cur_sum + x > max_sum) {
				subarr_count++;
				cur_sum = 0;
			}
			cur_sum += x;
		}
		if (cur_sum > 0) { subarr_count++; }

		return subarr_count <= k;
	}
}