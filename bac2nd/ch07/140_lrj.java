import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	int id[] = new int[256], letter[] = new int[10];
	int P[] = new int[10], bestP[] = new int[10], pos[] = new int[10], ans, n;
	Vector<Integer> u, v;
	void dfs(int cur) {
		if (cur == n) {
			for (int i = 0; i < n; i++) pos[P[i]] = i;
			int bandwidth = 0;
			for (int i = 0; i < u.size(); i++)
					bandwidth = max(bandwidth, abs(pos[u.get(i)] - pos[v.get(i)]));
			if (bandwidth < ans) {
				ans = bandwidth;
				bestP = Arrays.copyOf(P, P.length);
			}
			return;
		}
		qu:for (int i = 0; i < n; i++) {
			for (int j = 0; j < cur; j++) {
				if (P[j] == i) continue qu;
			}
			P[cur] = i;
			dfs(cur + 1);
		}
	}
	
	void run() {
		while (true) {
			String input = sc.next();
			if (input.charAt(0) == '#') return;
			n = 0;
			for (char ch = 'A'; ch <= 'Z'; ch++) {
				if (input.indexOf(ch) != -1) {
					id[ch] = n++;
					letter[id[ch]] = ch;
				}
			}
			
			int len = input.length(), p = 0, q = 0;
			u = new Vector<>(); v = new Vector<>();
			for (;;) {
				while (p < len && input.charAt(p) != ':') p++;
				if (p == len) break;
				while (q < len && input.charAt(q) != ';') q++;
				for (int i = p + 1; i < q; i++) {
					u.add(id[input.charAt(p - 1)]);
					v.add(id[input.charAt(i)]);
				}
				p++; q++;
			}
			
			//for (int i = 0; i < n; i++) P[i] = i;
			ans = n;
			dfs(0);
			
			for (int i = 0; i < n; i++) {
				System.out.print((char) letter[bestP[i]] + " ");
			}
			System.out.println("-> " + ans);
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