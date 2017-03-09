import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	void run() {
		final int[] coeff = {2, 3, 5};
		Set<Long> s = new HashSet<>();
		Queue<Long> q = new PriorityQueue<>();
		q.add((long) 1);
		s.add((long) 1);
		for (int i = 1;; i++) {
			long x = q.poll();
			if (i == 1500) {
				System.out.println("The 1500'th ugly number is " + x + ".");
				break;
			}
			for (int j = 0; j < 3; j++) {
				long x2 = x * coeff[j];
				if (!s.contains(x2)) {
					s.add(x2);
					q.add(x2);
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