import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	int sum[];
	
	int check(int pos) {
		int root = sc.nextInt();
		if (root != -1) {
			sum[pos] += root;
			check(pos - 1);
			check(pos + 1);
		}
		return root;
	}
	
	void run() {
		int kase = 1;
		for (;;) {
			sum = new int[10000];
			if (check(5000) == -1) return;
			System.out.printf("Case %d:\n", kase++);
			boolean first = true;
			for (int i : sum) {
				if (i != 0) {
					if (first) first = false;
					else System.out.print(" ");
					System.out.print(i);
				}
			}
			System.out.println();
			System.out.println();
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