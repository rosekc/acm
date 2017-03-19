import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	final int maxn = 260;
	String s;
	boolean failed = false;
	Node root;
	Vector<Integer> ans;
	
	class Node {
		boolean have_value;
		int v;
		Node left, rigth;
		public Node() {
			have_value = false;
			left = rigth = null;
		}
	}
	
	boolean read_input() {
		failed = false;
		root = new Node();
		for (;;) {
			if (!sc.hasNext()) return false;
			s = sc.next();
			if (s.equals("()")) break;
			addnode(s);
		}
		return true;
	}
	
	void addnode(String s) {
		Node u = root;
		for (int i = s.indexOf(","); i < s.length() - 1; i++) {
			if (s.charAt(i) == 'L') {
				if (u.left == null) u.left = new Node();
				u = u.left;
			}else if (s.charAt(i) == 'R') {
				if (u.rigth == null) u.rigth = new Node();
				u = u.rigth;
			}
		}
		if (u.have_value) failed = true;
		u.v = Integer.parseInt(s.substring(1, s.indexOf(",")));
		u.have_value = true;
	}
	
	boolean bfs() {
		Queue<Node> q = new LinkedList<>();
		ans = new Vector<>();
		q.add(root);
		while (!q.isEmpty()) {
			Node u = q.poll();
			if (!u.have_value) return false;
			ans.add(u.v);
			if (u.left != null) q.add(u.left);
			if (u.rigth != null) q.add(u.rigth);
		}
		return true;
	}
	
	void run() {
		for(;;) {
			if (!read_input()) return;
			if (failed || !bfs()) {
				System.out.println("not complete");
				continue;
			}
			boolean first = true;
			for (Integer i : ans) {
				if (first) first = false;
				else System.out.print(" ");
				System.out.print(i);
			}
			System.out.println();
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