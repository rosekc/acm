import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	void run() {
		int kase = 1;
		while (true) {
			int n = sc.nextInt();
			int q = sc.nextInt();
			if (n == 0)
				return;
			int[] d = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = sc.nextInt();
			}
			System.out.printf("CASE# %d:\n", kase++);
			Arrays.sort(d);
			qu: while (q-- != 0) {
				int in = sc.nextInt();
				int re = lowerBound(d, 0, n - 1, in);
				if (d[re] == in) {
					System.out.printf("%d found at %d\n", in, re + 1);
				}
				else System.out.printf("%d not found\n", in);
			}
		}
	}

	public static int lowerBound(int[] nums, int l, int r, int v) {
		while (l < r) {
			int m = l + (r - l) / 2;
			if (nums[m] >= v)
				r = m;
			else if (nums[m] < v)
				l = m + 1;
		}
		return l;
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
				System.setIn(new FileInputStream("in.txt"));
				System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}