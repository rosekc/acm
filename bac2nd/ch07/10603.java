import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.time.Duration;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	Queue<St> queue;
	Set<St> vis;
	class St implements Comparable<St>{
		int d[] = new int[3], pos;
		public St fill(int from, int to) {
			St next = new St(this);
			next.d[to] += next.d[from];
			if (next.d[to] > lim[to]) {
				next.pos += (lim[to] - d[to]);
				next.d[from] = next.d[to] - lim[to];
				next.d[to] = lim[to];
			}else {
				next.pos += d[from];
				next.d[from] = 0;
			}
			return next;
		}
		public int findD() {
			int re = Integer.MAX_VALUE;
			for (int i : d) {
				if (di >= i) re = min(re, di - i);
			}
			return re;
		}
		@Override
		public boolean equals(Object obj) {
			St t = (St) obj;
			return Arrays.equals(d, t.d);
		}
		@Override
		public int hashCode() {
			return Integer.valueOf(d[0] + d[1] * 10 + d[2] * 100).hashCode();
		}
		@Override
		public int compareTo(St o) {
			return pos - o.pos;
		}
		public St() {
			super();
		}
		public St(St st) {
			d = Arrays.copyOf(st.d, 3);
			pos = st.pos;
		}
	}
	
	St dfs() {
		bestd = Integer.MAX_VALUE;
		while (!queue.isEmpty()) {
			St cur = queue.poll();
			int curd = cur.findD();
			if (curd == 0) return cur;
			if (bestd > curd) {
				bestd = curd;
				best = cur;
			}
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					if (i == j) continue;
					St next = cur.fill(i, j);
					if (!vis.contains(next)) {
						queue.add(next);
						vis.add(next);
					}
				}
		}
		return null;
	}
	
	int lim[] = new int[3], di, bestd;
	St best;
	void run() {
		int T = sc.nextInt();
		while (T-- != 0) {
			lim[0] = sc.nextInt();
			lim[1] = sc.nextInt();
			lim[2] = sc.nextInt();
			di = sc.nextInt();
			queue = new PriorityQueue<St>();
			St st = new St();
			st.d[0] = st.d[1] = 0;
			st.d[2] = lim[2];
			queue.add(st);
			vis = new HashSet<St>();
			vis.add(st);
			St ans = dfs();
			if (ans == null) {
				int re = 0;
				for (int i : best.d) {
					if (di - i == bestd) re = i;
				}
				System.out.println(best.pos + " " + re);
			}
			else System.out.println(ans.pos + " " + di);
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
//				System.setIn(new FileInputStream("in.txt"));
//				System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}