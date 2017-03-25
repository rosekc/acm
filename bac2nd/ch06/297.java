import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	int sum[];

	String tmp1, tmp2;
	int p, q;

	int check(int cur, char fa1, char fa2) {
		char rt1 = fa1, rt2 = fa2;
		int sum = 0;
		if (fa1 == 'p') {
			rt1 = tmp1.charAt(p++);
		}
		if (fa2 == 'p') {
			rt2 = tmp2.charAt(q++);
		}
		if (rt1 != 'p' && rt2 != 'p') {
			if (rt1 == 'f' || rt2 == 'f')
				return 1024 / (int) pow(4, cur - 1);
			return 0;
		}else {
			for (int i = 0; i < 4; i++) {
				sum += check(cur + 1, rt1, rt2);
			}
		}
		return sum;
	}

	void run() {
		int T = sc.nextInt();
		while (T-- != 0) {
			tmp1 = sc.next();
			tmp2 = sc.next();
			p = q = 0;
			System.out.println("There are " + check(1, 'p', 'p') + " black pixels.");
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