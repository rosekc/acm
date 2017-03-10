import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	int l, n, cnt;
	char[] d = new char[85];
	int dfs(int cur) {
		if (cnt++ == n) {
			for (int i = 0; i < cur; i++) {
				System.out.print(d[i]);
				if (i % (4 * 16) == (4 * 16) - 1 && i + 1 != cur) System.out.println();
				else if (i % 4 == 3 && i + 1 != cur) System.out.print(' ');
			}
			System.out.println("\n" + cur);
			return 0;
		}
		for (char i = 'A'; i < 'A' + l; i++) {
			boolean ok = true;
			d[cur] = i;
			for (int j = 1; j * 2 <= cur + 1; j++) {
				boolean equal = true;
				for (int k = 0; k < j; k++) {
					if (d[cur - k] != d[cur - j - k]) {
						equal = false;
						break;
					}
				}
				if (equal) {
					ok = false;
					break;
				}
			}
			if (ok) {
				if (dfs(cur + 1) == 0) return 0;
			}
		}
		return 1;
	}
	void run() {
		while (true) {
			n = sc.nextInt();
			l = sc.nextInt();
			if (l == 0) break;
			cnt = 0;
			dfs(0);
		}
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