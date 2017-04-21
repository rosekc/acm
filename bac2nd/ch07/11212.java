import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	final int maxn = 10;
	int a[] = new int[maxn], n = 1;
	final int max_d = 8;
	
	int h() {
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] + 1 != a[i + 1]) cnt++;
		}
		if (a[n - 1] != n) cnt++;
		return cnt;
	}

	boolean dfs(int d, int maxd) {
		if (3 * d + h() > 3 * maxd) return false;
		if (d == maxd) {
			for (int i = 0; i < n; i++) {
				if (a[i] != i + 1) return false;
			}
			return true;
		}
		int olda[] = copyOf(a, a.length);
		int b[] = new int[a.length];
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if (k < i || k > j) b[cnt++] = olda[k];
				}
				for (int k = 0; k <= cnt; k++) {
					int ind = 0;
					for (int p = 0; p < k; p++) {
						a[ind++] = b[p];
					}
					for (int p = i; p <= j; p++) {
						a[ind++] = olda[p];
					}
					for (int p = k; p < cnt; p++) {
						a[ind++] = b[p];
					}
					if (dfs(d + 1, maxd)) return true;
				}
			}
		}
		a = copyOf(olda, a.length);
		return false;
	}

	void run() {
		int kase = 1;
		while (sc.hasNext()) {
			n = sc.nextInt();
			if (n == 0) return;
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
			}
			boolean ok = true;
			for (int i = 0; i < n; i++) {
				if (a[i] != i + 1) ok = false;
			}
			if (ok) System.out.printf("Case %d: %d\n", kase++, 0);
			else for (int d = 1; d < max_d; d++) {
				if (dfs(0, d)) {
					System.out.printf("Case %d: %d\n", kase++, d);
					break;
				}
			}
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