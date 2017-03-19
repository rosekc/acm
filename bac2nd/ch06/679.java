import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	int d, i, ans;
	
	void run() {
		int t = sc.nextInt();
		while (t-- != 0) {
			d = sc.nextInt(); i = sc.nextInt();
			ans = 1;
			for (int j = 1; j < d; j++) {
				if (i % 2 == 1) {
					ans *= 2;
					i = (i + 1) / 2;
				}else {
					ans = ans * 2 + 1;
					i /= 2;
				}
			}
			System.out.println(ans);
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