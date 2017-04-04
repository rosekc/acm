import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	final int maxn = 100000;
	int a, b;
	int maxd =  1000000;
	long[] ans = new long[maxn];

	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	int get_first(long a, long b) {
		return (int) (((b - 1) / a) + 1);
	}

	int dfs(int t, long aa, long bb) {
		if (bb > maxd) return -1;
		if (aa == 1) {
			ans[t] = bb;
			return t;
		}
		int re = -1;
		for (int i = get_first(aa, bb); i <= maxd; i++) {
			long b2 = bb * i;
			long a2 = aa * i - bb;
			long g = gcd(a2, b2);
			ans[t] = i;
			re = dfs(t + 1, a2 / g, b2 / g);
			if (re != -1) return re;
		}
		return re;
	}

	void run() {
		while (sc.hasNext()) {
			a = sc.nextInt();
			b = sc.nextInt();
			if (b == 0) return;
			fill(ans, -1);
			int d = dfs(0, a, b);
			for (int i = 0;; i++) {
				System.out.printf("%d", ans[i]);
				if (i != d) {
					System.out.printf(" ");
				}else break;
			}
			System.out.println();
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
				// System.setIn(new FileInputStream("in.txt"));
				// System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}