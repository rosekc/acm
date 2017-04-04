import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	final int maxs = 20;
	final int maxn = 150;
	int dx[] = {1, -1, 0, 0, 0};
	int dy[] = {0, 0, 1, -1, 0};
	int ID(int a, int b, int c) {
		return (a << 16) | (b << 8) | c;
	}
	int s[] = new int[3], t[] = new int[3];
	int deg[] = new int[maxn];
	int g[][] = new int[maxn][5];
	boolean conflict(int a, int b, int a2, int b2) {
		return a2 == b2 || (a2 == b && b2 == a);
	}
	int d[][][] =  new int[maxn][maxn][maxn],
		vis[][][] = new int[maxn][maxn][maxn];
	Queue<Integer> q[] = new ArrayDeque[2];
	int bfs() {
		q[0] = new ArrayDeque<Integer>();
		q[1] = new ArrayDeque<Integer>();
		for (int i = 0; i < maxn; i++) {
			for (int j = 0; j < maxn; j++) {
				Arrays.fill(d[i][j], -1);
				//Arrays.fill(vis[i][j], -1);
			}
		}
		q[0].add(ID(s[0], s[1], s[2]));
		q[1].add(ID(t[0], t[1], t[2]));
		d[s[0]][s[1]][s[2]] = d[t[0]][t[1]][t[2]] = 0;
		vis[s[0]][s[1]][s[2]] = 0;
		vis[t[0]][t[1]][t[2]] = 1;
		int ans = -1;
		while (!q[0].isEmpty() && !q[1].isEmpty()) {
			if (q[0].size() < q[1].size()) {
				ans = expand(0);
			}else {
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
		int u = q[ind].poll();
		int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;
		for (int i = 0; i < deg[a]; i++) {
			int a2 = g[a][i];
			for (int j = 0; j < deg[b]; j++) {
				int b2 = g[b][j];
				if (conflict(a, b, a2, b2)) continue;
				for (int k = 0; k < deg[c]; k++) {
					int c2 = g[c][k];
					if (conflict(a, c, a2, c2)) continue;
					if (conflict(b, c, b2, c2)) continue;
					if (d[a2][b2][c2] != -1) {
						if (vis[a2][b2][c2] != ind) {
							return d[a2][b2][c2] + d[a][b][c] + 1;
						}
						continue;
					}
					d[a2][b2][c2] = d[a][b][c] + 1;
					vis[a2][b2][c2] = ind;
					q[ind].add(ID(a2, b2, c2));
				}
			}
		}
		return -1;
	}
	

	void run() {
		int w, h, n;
		for (;;) {
			w = sc.nextInt();
			h = sc.nextInt();
			n = sc.nextInt();
			if (n == 0) return;
			sc.nextLine();
			String maze[] = new String[20];
			for (int i = 0; i < h; i++) {
				maze[i] = sc.nextLine();
			}
			int cnt = 0, x[], y[], id[][];
			x = new int[maxn];
			y = new int[maxn];
			id = new int[maxs][maxs];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (maze[i].charAt(j) != '#') {
						x[cnt] = i; y[cnt] = j; id[i][j] = cnt;
						if (Character.isLowerCase(maze[i].charAt(j))) s[maze[i].charAt(j) - 'a'] = cnt;
						else if (Character.isUpperCase(maze[i].charAt(j))) t[maze[i].charAt(j) - 'A'] = cnt;
						cnt++;
					}
				}
			}
			for (int i = 0; i < cnt; i++) {
				deg[i] = 0;
				for (int dir = 0; dir < 5; dir++) {
					int nx = x[i] + dx[dir], ny = y[i] + dy[dir];
					if (maze[nx].charAt(ny) != '#')
						g[i][deg[i]++] = id[nx][ny];
				}
			}
			
			if (n <= 2) {
				deg[cnt] = 1;
				g[cnt][0] = cnt;
				s[2] = t[2] = cnt++;
			}
			if (n <= 1) {
				deg[cnt] = 1;
				g[cnt][0] = cnt;
				s[1] = t[1] = cnt++;
			}
			System.out.println(bfs());
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