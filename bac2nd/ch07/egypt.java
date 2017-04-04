import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	final int maxn = 105;
	int maxd, a, b;
	long[] v = new long[maxn]; 
	long[] ans = new long[maxn];

	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	int get_first(long a, long b) {
		return (int) ((b / a) + 1);
	}

	boolean better(int d) {
		for (int i = d; i >= 0; i--)
			if (v[i] != ans[i]) {
				return ans[i] == -1 || v[i] < ans[i];
			}
		return false;
	}

	boolean dfs(int d, int from, long aa, long bb) {
		if (d == maxd) {
			if (bb % aa != 0) return false;
			v[d] = bb / aa;
			if (better(d)) ans = copyOf(v, v.length);
			return true;
		}
		boolean ok = false;
		from = max(from, get_first(aa, bb));
		for (int i = from;; i++) {
			if (bb * (maxd + 1 - d) <= i * aa) break;
			v[d] = i;
			long b2 = bb * i;
			long a2 = aa * i - bb;
			long g = gcd(a2, b2);
			if (dfs(d + 1, i + 1, a2 / g, b2 / g)) ok = true;
		}
		return ok;
	}

	void run() {
		while (sc.hasNext()) {
			a = sc.nextInt();
			b = sc.nextInt();
			if (b == 0) return;
			int ok = 0;
			for (maxd = 1; maxd <= 100; maxd++) {
				fill(ans, -1);
				if (dfs(0, get_first(a, b), a, b)) {
					ok = 1;
					break;
				}
			}
			for (int i = 0; i <= maxd; i++) {
				System.out.printf("%d ", ans[i]);
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