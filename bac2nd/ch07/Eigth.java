import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	int mr[] = new int[] {-1, 0, 1, 0};
	int mc[] = new int[] {0, 1, 0, -1};
	char dir[] = new char[] {'d', 'l', 'u', 'r'};
	Queue<St> queue;
	class St {
		int[] d;
		public St() {
			d = new int[9];
		}
		
		@Override
		public boolean equals(Object obj) {
			//if (obj == this) return true;
			St t = (St) obj;
			for (int i = 0; i < 9; i++) {
				if (t.d[i] != d[i]) return false;
			}
			return true;
		}
		@Override
		public int hashCode() {
			int t = 0;
			for (int i = 0; i < 9; i++) {
				t = t * 10 + d[i];
			}
			return Integer.hashCode(t);
		}
	}
	void bfs(St st) {
		int xpos = -1;
		int ypos = -1;
		for (int i = 0; i < 9; i++) 
			if (st.d[i] == 0) {
				xpos = i / 3; ypos = i % 3;
			}
		for (int i = 0; i < 4; i++) {
			int tx = xpos + mr[i];
			int ty = ypos + mc[i];
			if (tx >= 0 && tx < 3 
					&& ty >=0 && ty < 3) {
				St next = new St();
				next.d = Arrays.copyOf(st.d, 9);
				int t = next.d[3 * tx + ty];
				next.d[3 * tx + ty] = next.d[3 * xpos + ypos];
				next.d[3 * xpos + ypos] = t;
				if (!map.containsKey(next)) {
					map.put(next, dir[i] + map.get(st));
					queue.add(next);
				}
			}
		}
	}
	Map<St, String> map;
	void run() {
		map = new HashMap<>();
		queue = new LinkedList<>();
		St st = new St();
		for (int i = 0; i < 8; i++) {
			st.d[i] = i + 1;
		}
		st.d[8] = 0;
		map.put(st, "");
		queue.add(st);
		while (!queue.isEmpty()) {
			bfs(queue.poll());
		}
		while (sc.hasNext()) {
			St find = new St();
			for (int i = 0; i < 9; i++) {
				try {
					find.d[i] = sc.nextInt();
				}catch (Exception e) {
					find.d[i] = 0;
					sc.next();
				}
			}
			if (map.containsKey(find)) {
				System.out.println(map.get(find));
			}else System.out.println("unsolvable");
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