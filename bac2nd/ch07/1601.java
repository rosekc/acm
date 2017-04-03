import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	int w, h, n;
	String[] map;
	Vector<Vector<Integer>> g;
	Queue<St>[] q;
	int[][][] visSt;
	int[][][] dis;
	int[][] vis;
	int[] dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };
	int[] st = new int[3], ed = new int[3];

	class St {
		int[] pos = new int[3];

		public St(int a, int b, int c) {
			pos[0] = a;
			pos[1] = b;
			pos[2] = c;
		}

		@Override
		public boolean equals(Object obj) {
			St t = (St) obj;
			return Arrays.equals(pos, t.pos);
		}

		@Override
		public int hashCode() {
			return Arrays.hashCode(pos);
		}
	}

	void buildGraph() {
		g = new Vector<Vector<Integer>>();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i].charAt(j) != '#') {
					dfs(i, j);
					if (Character.isUpperCase(map[i].charAt(j))) {
						st[map[i].charAt(j) - 'A'] = dfs(i, j);
					} else if (map[i].charAt(j) != ' '){
						ed[map[i].charAt(j) - 'a'] = dfs(i, j);
					}
				}
			}
		}
		if (n <= 2) {
			g.add(new Vector<Integer>());
			g.get(g.size() - 1).add(g.size() - 1);
			st[2] = ed[2] = g.size() - 1;
		}
		if (n <= 1) {
			g.add(new Vector<Integer>());
			g.get(g.size() - 1).add(g.size() - 1);
			st[1] = ed[1] = g.size() - 1;
		}
	}

	int dfs(int x, int y) {
		if (vis[x][y] >= 0)
			return vis[x][y];
		vis[x][y] = g.size();
		g.add(new Vector<Integer>());
		g.get(vis[x][y]).add(vis[x][y]);
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx >= 0 && tx < h && ty >= 0 && ty < w && map[tx].charAt(ty) != '#') {
				g.get(vis[x][y]).add(dfs(tx, ty));
			}
		}
		return vis[x][y];
	}

	int bfs() {
		q = new ArrayDeque[2];
		visSt = new int[g.size()][g.size()][g.size()];
		dis = new int[g.size()][g.size()][g.size()];
		q[0] = new ArrayDeque<Main.St>();
		q[1] = new ArrayDeque<Main.St>();
		q[0].add(new St(st[0], st[1], st[2]));
		setVis(q[0].peek(), 1);
		dis[st[0]][st[1]][st[2]] = 0;
		q[1].add(new St(ed[0], ed[1], ed[2]));
		setVis(q[1].peek(), 2);
		dis[ed[0]][ed[1]][ed[2]] = 0;
		int ans = -1;
		while (!q[0].isEmpty() && !q[1].isEmpty()) {
			if (q[0].size() < q[1].size()) {
				ans = expand(0);
			} else {
				ans = expand(1);
			}
			if (ans != -1) return ans;
		}
		while (!q[0].isEmpty()) {
			ans = expand(0);
			if (ans != -1) return ans;
		}
		while (!q[1].isEmpty()) {
			ans = expand(1);
			if (ans != -1) return ans;
		}
		return ans;
	}

	int expand(int ind) {
		St cur = q[ind].poll();
		for (Integer i : g.get(cur.pos[0])) {
			for (Integer j : g.get(cur.pos[1])) {
				for (Integer k : g.get(cur.pos[2])) {
					St next = new St(i, j, k);
					if (!check(cur, next))
						continue;
					if (getVis(next) == 0) {
						setVis(next, ind + 1);
						setDis(next, getDis(cur) + 1);
						//dis.put(next, dis.get(cur) + 1);
						q[ind].add(next);
					} else if (getVis(next) != ind + 1) {
						return getDis(next) + getDis(cur) + 1;
					}
				}
			}
		}
		return -1;
	}
	
	void setDis(St state, int statepos) {
		dis[state.pos[0]][state.pos[1]][state.pos[2]] = statepos;
	}
	int getDis(St state) {
		return dis[state.pos[0]][state.pos[1]][state.pos[2]];
	}
	void setVis(St state, int num) {
		visSt[state.pos[0]][state.pos[1]][state.pos[2]] = num;
	}
	int getVis(St state) {
		return visSt[state.pos[0]][state.pos[1]][state.pos[2]];
	}
	boolean check(St cur, St next) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (next.pos[i] == next.pos[j] || (next.pos[i] == cur.pos[j] && next.pos[j] == cur.pos[i]))
					return false;
			}
		}
		return true;
	}

	void run() {
		while (sc.hasNext()) {
			w = sc.nextInt();
			h = sc.nextInt();
			n = sc.nextInt();
			if (w == 0) return;
			map = new String[h];
			vis = new int[h][w];
			for (int i = 0; i < vis.length; i++) {
				Arrays.fill(vis[i], -1);
			}
			sc.nextLine();
			for (int i = 0; i < h; i++) {
				map[i] = sc.nextLine();
			}
			buildGraph();
			int ans = bfs();
			System.out.println(ans);
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