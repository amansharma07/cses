import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class cses1634 {
	public static int MAX = (int)10e6 + 2;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int X = Integer.parseInt(st.nextToken());

		/* Read the coin weights. */
		int[] coins = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) { coins[i] = Integer.parseInt(st.nextToken()); }

		/* Initialize DP. */
		int[] dp = new int[X + 1];
		for (int i = 0; i <= X; i++) { dp[i] = MAX; }
		dp[0] = 0;

		/* Loop through all coins and all weights
		If the state curWeight - coin[i] is possible
		DP[curWeight] = min(DP[curWeight], DP[curWeight - coin[i]] + 1). */
		for (int i = 1; i <= N; i++) {
			for (int sum = coins[i - 1]; sum <= X; sum++) {
				dp[sum] = Integer.min(dp[sum], dp[sum - coins[i - 1]] + 1);
			}
		}

		/* This state is not possible */
		if (dp[X] == MAX) {
			System.out.println(-1);
			System.exit(0);
		}

		System.out.println(dp[X]);
	}
}