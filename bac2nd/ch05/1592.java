import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	class node {
		Integer a, b;
		public node(Integer a, Integer b) {
			this.a = a; this.b = b;
		}
		@Override
		public boolean equals(Object o) {
			node cmp = (node) o;
			return cmp.a.equals(a) && cmp.b.equals(b);
		}
		@Override
		public int hashCode() {
			return a.hashCode();
		}
	}
	
	void run() {
		while (sc.hasNext()) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int[][] d = new int[r][c];
			Map<String, Integer> stringCache = new HashMap<>();
			sc.nextLine();
			for (int i = 0; i < r; i++) {
				String[] t = sc.nextLine().split(",");
				for (int j = 0; j < c; j++) {
					if (stringCache.containsKey(t[j])) {
						d[i][j] = stringCache.get(t[j]);
					}else {
						d[i][j] = stringCache.size();
						stringCache.put(t[j], d[i][j]);
					}
				}
			}
			Integer g = 0;
			boolean find = false;
			scan:for (int i = 0; i < c; i++) {
				for (int j = i + 1; j < c; j++) {
					Map<node, Integer> m = new HashMap<>();
					for (int k = 0; k < r; k++) {
						if ((g = m.get(new node(d[k][i], d[k][j]))) != null) {
							System.out.println("NO");
							System.out.println((g + 1) + " " + (k + 1));
							System.out.println((i + 1) + " " + (j + 1));
							find = true;
							break scan;
						}else {
							m.put(new node(d[k][i], d[k][j]), k);
						}
					}
				}
			}
			if (!find) System.out.println("YES");
		}
	}
	
	
	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
				//System.setIn(new FileInputStream("in.txt"));
				//System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}