import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	class Tree {
		public double L = 0, R = 0;
		public Tree() {
			L = 0; R = 0;
		}
	}
	
	final int maxn = 6;
	
	int n, vis[] = new int[1 << maxn];
	double r, w[] = new double[maxn], sum[] = new double[1 << maxn];
	Vector<Tree> tree[] = new Vector[1 << maxn];
	
	void dfs(int subset) {
		if (vis[subset] != 0) return;
		vis[subset] = 1;
		
		boolean have_children = false;
		for (int left = (subset - 1) & subset; left != 0; left = (left - 1) & subset) {
			have_children = true;
			int right = subset ^ left;
			double d1 = sum[right] / sum[subset];
			double d2 = sum[left] / sum[subset];
			
			dfs(left); dfs(right);
			
			for (int i = 0; i < tree[left].size(); i++) 
				for (int j = 0; j < tree[right].size(); j++) {
					Tree t = new Tree();
					t.L = max(tree[left].get(i).L + d1, tree[right].get(j).L - d2);
					t.R = max(tree[right].get(j).R + d2, tree[left].get(i).R - d1);
					if (t.L + t.R < r) tree[subset].add(t);
				}
		}
		if (!have_children) tree[subset].add(new Tree());
	}
	
	void run() {
		int T = sc.nextInt();
		while (T-- != 0) {
			r = sc.nextDouble(); n = sc.nextInt();
			for (int i = 0; i < n; i++) w[i] = sc.nextDouble();
			for (int i = 0; i < (1 << n); i++) {
				sum[i] = 0;
				tree[i] = new Vector<>();
				for (int j = 0; j < n; j++) 
					if ((i & (1 << j)) != 0) sum[i] += w[j];
			}
			
			int root = (1 << n) - 1;
			Arrays.fill(vis, 0);
			dfs(root);
			
			double ans = -1;
			for (int i = 0; i < tree[root].size(); i++) {
				ans = max(ans, tree[root].get(i).L + tree[root].get(i).R);
			}
			System.out.printf("%.10f\n", ans);
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