import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	Map<Integer, Integer> m;
	Queue<Integer> lq;
	Queue<Integer>[] q;
	void run() {
		int kase = 1;
		int n = 0;
		while (true) {
			int t = sc.nextInt();
			if (t == 0) return;
			m = new HashMap<>();
			for (int i = 0; i < t; i++) {
				n = sc.nextInt();
				for (int j = 0; j < n; j++) {
					m.put(sc.nextInt(), i);
				}
			}
			lq = new LinkedList<>();
			q = new LinkedList[n];
			for (int i = 0; i < n; i++) {
				q[i] = new LinkedList<>();
			}
			String in;
			System.out.printf("Scenario #%d\n", kase++);
			while (true) {
				in = sc.next();
				if (in.charAt(0) == 'E') {
					int next = sc.nextInt();
					int ln = m.get(next);
					if (q[ln].size() == 0) {
						lq.add(ln);
					}
					q[ln].add(next);
				}else if (in.charAt(0) == 'D') {
					int cur = lq.peek();
					System.out.println(q[cur].poll());
					if (q[cur].size() == 0) lq.poll();
						
				}else if (in.charAt(0) == 'S') {
					System.out.println();
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
				//System.setIn(new FileInputStream("in.txt"));
				//System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}