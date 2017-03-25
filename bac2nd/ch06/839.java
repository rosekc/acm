import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	int check() {
		int lw = sc.nextInt(),
			ld = sc.nextInt(),
			rw = sc.nextInt(),
			rd = sc.nextInt();
		if (lw == 0) lw = check();
		if (rw == 0) rw = check();
		if (lw != -1 && rw != -1 && lw * ld == rw * rd) return lw + rw;
		else return -1;
	}
	
	void run() {
		int T = sc.nextInt();
		boolean first = true;
		while (T-- != 0) {
			if (first) first = false;
			else System.out.println();
			if (check() != -1) System.out.println("YES");
			else System.out.println("NO");
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