import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int kase = 1;
		while (sc.hasNext()) {
			int n = sc.nextInt();
			int[] d = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = sc.nextInt();
			}
			long re = -1;
			for (int st = 0; st < n; st++) {
				for (int ed = st; ed < n; ed++) {
					long t = 1;
					for (int i = st; i <= ed; i++) {
						t *= d[i];
					}
					if (t > re) re = t;
				}
			}
			if (re < 0) re = 0;
			System.out.printf("Case #%d: The maximum product is %d.\n\n", kase++, re);
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