import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	Vector<Integer>[] v;
	int n, a, b;
	String op1, op2;
	int pa, pb, ha, hb;
	
	void run() {
		n = sc.nextInt();
		v = new Vector[n];
		for (int i = 0; i < n; i++) {
			v[i] = new Vector<Integer>();
			v[i].add(i);
		}
		for (;;) {
			op1 = sc.next();
			if (op1.equals("quit")) break;
			a = sc.nextInt();
			op2 = sc.next();
			b = sc.nextInt();
			findBlock(a, 0);
			findBlock(b, 1);
			if (pa == pb)
				continue;
			if (op2.equals("onto"))
				clearAbove(pb, hb);
			if (op1.equals("move"))
				clearAbove(pa, ha);
			pileOnto(pa, ha, pb);
		}
		print();
	}

	void print() {
		for (int i = 0; i < n; i++) {
			System.out.printf("%d:", i);
			for (Integer j : v[i]) {
				System.out.printf(" %d", j);
			}
			System.out.println();
		}
	}

	void findBlock(int a, int f) {
		for (int p = 0; p < n; p++) {
			for (int h = 0; h < v[p].size(); h++) {
				if (v[p].get(h) == a) {
					if (f == 0) {
						pa = p;
						ha = h;
					}
					else {
						pb = p;
						hb = h;
					}
					return;
				}
			}
		}
	}

	void clearAbove(int p, int h) {
		for (int i = h + 1; i < v[p].size(); i++) {
			int b = v[p].get(i);
			v[b].add(b);
		}
		v[p].setSize(h + 1);
	}

	void pileOnto(int p, int h, int p2) {
		for (int i = h; i < v[p].size(); i++) {
			v[p2].add(v[p].get(i));
		}
		v[p].setSize(h);
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
				System.setIn(new FileInputStream("in.txt"));
				//System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}