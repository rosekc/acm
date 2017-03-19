import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	final int maxv = 10000 + 10;
	int in_order[] = new int[maxv],
		post_order[] = new int[maxv],
		lnode[] = new int[maxv],
		rnode[] = new int[maxv],
		sum[] = new int[maxv],
		ans[] = new int[maxv];
		
	int build(int L1, int R1, int L2, int R2) {
		if (L1 > R1) {
			return 0;
		}
		for (int i = L1; i <= R1; i++) {
			if (in_order[i] == post_order[R2]) {
				lnode[in_order[i]] = build(L1, i - 1, L2, L2 + (i - 1 - L1));
				rnode[in_order[i]] = build(i + 1, R1, L2 + (i - L1), R2 - 1);
				if (lnode[in_order[i]] != 0 && rnode[in_order[i]] != 0) {
					if (sum[lnode[in_order[i]]] < sum[rnode[in_order[i]]]) {
						sum[in_order[i]] = sum[lnode[in_order[i]]] + in_order[i];
						ans[in_order[i]] = ans[lnode[in_order[i]]];
					}else if (sum[lnode[in_order[i]]] == sum[rnode[in_order[i]]]) {
						sum[in_order[i]] = sum[lnode[in_order[i]]] + in_order[i];
						ans[in_order[i]] = min(ans[lnode[in_order[i]]], ans[rnode[in_order[i]]]);
					}if (sum[lnode[in_order[i]]] > sum[rnode[in_order[i]]]) {
						sum[in_order[i]] = sum[rnode[in_order[i]]] + in_order[i];
						ans[in_order[i]] = ans[rnode[in_order[i]]];
					}
				}else if (lnode[in_order[i]] == 0 && rnode[in_order[i]] == 0){
					sum[in_order[i]] = in_order[i];
					ans[in_order[i]] = in_order[i];
				}else if (lnode[in_order[i]] == 0){
					sum[in_order[i]] = sum[rnode[in_order[i]]] + in_order[i];
					ans[in_order[i]] = ans[rnode[in_order[i]]];
				}else if (rnode[in_order[i]] == 0){
					sum[in_order[i]] = sum[lnode[in_order[i]]] + in_order[i];
					ans[in_order[i]] = ans[lnode[in_order[i]]];
				}
				return post_order[R2];
			}
		}
		return -1;
	}
	
	void run() {
		while (sc.hasNext()) {
			String in[] = sc.nextLine().split(" ");
			String post[] = sc.nextLine().split(" ");
			for (int i = 0; i < in.length; i++) {
				in_order[i] = Integer.parseInt(in[i]);
				post_order[i] = Integer.parseInt(post[i]);
			}
			sum[0] = Integer.MAX_VALUE;
			int root = build(0, in.length - 1, 0, in.length - 1);
			System.out.println(ans[root]);
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