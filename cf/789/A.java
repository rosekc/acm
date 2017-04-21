import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	void run() {
		int n = sc.nextInt();
		int k = sc.nextInt();
		int d[] = new int [n];
		for (int i = 0; i < n; i++) {
			d[i] = sc.nextInt();
		}
		int re = 0;
		int k2 = k * 2;
		boolean f = false;
		for (int i = 0; i < n; i++) {
			re += d[i] / k2;
			d[i] = d[i] % k2;
			if (d[i] > k) re++;
			else if (d[i] != 0) {
				if (f) {
					re++;
					f = false;
				}else {
					f = true;
				}
			}
		}
		if (f) re++;
		System.out.println(re);
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
//				 System.setIn(new FileInputStream("in.txt"));
//				 System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}