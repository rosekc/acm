import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	Map<Character, Set<Character>> g;
	Set<Character> id;
	char A[] = new char[10], re[] = new char[10];
	int n;
	Vector<Character> u, v;
	int mn;

	void build(String tmp) {
		int len = tmp.length(), p = 0, q = 0;
		n = 0;
		for (char ch = 'A'; ch <= 'Z'; ch++) {
			if (tmp.indexOf(ch) != -1) {
				n++;
			}
		}
		u = new Vector<>(); v = new Vector<>();
		id = new TreeSet<>();
		for (;;) {
			while (p < len && tmp.charAt(p) != ':') p++;
			if (p == len) break;
			while (q < len && tmp.charAt(q) != ';') q++;
			id.add(tmp.charAt(p - 1));
			for (int i = p + 1; i < q; i++) {
				u.add(tmp.charAt(p - 1));
				v.add(tmp.charAt(i));
				id.add(tmp.charAt(i));
			}
			p++; q++;
		}
	}

	void dfs(int cur) {
		if (cur == n) {
			int t = 0;
			Map<Character, Integer> pos = new HashMap<>();
			for (int i = 0; i < n; i++) pos.put(A[i], i);
			for (int i = 0; i < u.size(); i++) {
				t= max(t, abs(pos.get(u.get(i)) - pos.get(v.get(i))));
			}
			if (t < mn) {
				mn = t;
				re = Arrays.copyOf(A, id.size());
			}
			return;
		}
		q: for (char i : id) {
			for (int j = 0; j < cur; j++) {
				if (i == A[j])
					continue q;
			}
			A[cur] = i;
			dfs(cur + 1);
		}
	}

	void printre() {
		for (int i = 0; i < n; i++) {
			System.out.print(re[i] + " ");
		}
		System.out.println("-> " + mn);
	}

	void run() {
		while (true) {
			String tmp = sc.next();
			if (tmp.charAt(0) == '#')
				return;
			build(tmp);
			//A = new char[id.size()];
			//re = new char[id.size()];
			mn = id.size();
			dfs(0);
			printre();
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