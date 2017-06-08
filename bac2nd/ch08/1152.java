import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	ArrayList<Long> l1, l2, l3, l4;
	Map<Long, Integer> m1;
	void run() {
		int T = sc.nextInt();
		int n;
		while (T-- != 0) {
			m1 = new HashMap<Long, Integer>();
			l1 = new ArrayList<Long>();
			l2 = new ArrayList<Long>();
			l3 = new ArrayList<Long>();
			l4 = new ArrayList<Long>();
			n = sc.nextInt();
			for (int i = 0; i < n; i++) {
				l1.add(sc.nextLong());
				l2.add(sc.nextLong());
				l3.add(sc.nextLong());
				l4.add(sc.nextLong());
				
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					long a = l3.get(i) + l4.get(j);
					if (!m1.containsKey(a)) {
						m1.put(a, 1);
					}else m1.put(a, m1.get(a) + 1);
				}
			}
			int ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					Integer re = m1.get(-(l1.get(i) + l2.get(j)));
					if (re != null) ans += re;
				}
			}
			System.out.println(ans);
			if (T != 0) System.out.println();
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