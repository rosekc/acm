import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	boolean check(int a, int b) {
		char[] t = (String.valueOf(a) + String.valueOf(b)).toCharArray();
		sort(t);
		String tt = String.copyValueOf(t);
		return tt.equals("123456789") || tt.equals("0123456789");
	}
	
	void run() {
		boolean first = true;
		while (true) {
			int n = sc.nextInt();
			if (n == 0) return;
			if (first) first = false;
			else System.out.println();
			boolean f = false;
			for (int b = 1234;; b++) {
				int a = b * n;
				if (a >= 100000) break;
				if (check(a, b)) {
					System.out.printf("%05d / %05d = %d\n", a, b, n);
					f = true;
				}
			}
			if (!f) System.out.println("There are no solutions for " + n + ".");
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