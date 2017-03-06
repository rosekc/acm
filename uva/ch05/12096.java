import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	Map<Set<Integer>, Integer> IdCache;
	Vector<Set<Integer>> SetCache;
	Stack<Integer> s;
	void run() {
		int t, n;
		String op;
		t = sc.nextInt();
		while (t-- != 0) {
			IdCache = new HashMap<>();
			SetCache = new Vector<>();
			s = new Stack<>();
			n = sc.nextInt();
			while (n-- != 0) {
				op = sc.next();
				if (op.charAt(0) == 'P') {
					s.push(ID(new HashSet<>()));
				}else if (op.charAt(0) == 'D'){
					s.push(s.peek());
				}else {
					Set<Integer> x1 = SetCache.get(s.pop());
					Set<Integer> x2 = SetCache.get(s.pop());
					Set<Integer> x = null;
					if (op.charAt(0) == 'U'){
						x = SetUnion(x1, x2);
					}else if (op.charAt(0) == 'I'){
						x = SetIntersection(x1, x2);
					}else if (op.charAt(0) == 'A'){
						x = new HashSet<>(x2);
						x.add(ID(x1));
					}
					s.push(ID(x));
				}
				System.out.println(SetCache.get(s.peek()).size());
			}
			System.out.println("***");
		}
	}
	
	private Set<Integer> SetIntersection(Set<Integer> x1, Set<Integer> x2) {
		Set<Integer> x = new HashSet<>();
		for (Integer i : x1) {
			for (Integer j : x2) {
				if (i == j) x.add(i);
			}
		}
		return x;
	}

	private Set<Integer> SetUnion(Set<Integer> x1, Set<Integer> x2) {
		Set<Integer> x = new HashSet<>(x1);
		for (Integer i : x2) {
			if (!x.contains(i)) x.add(i);
		}
		return x;
	}

	Integer ID(Set<Integer> x) {
		if (IdCache.get(x) != null) return IdCache.get(x);
		debug("233");
		SetCache.add(x);
		IdCache.put(x, SetCache.size() - 1);
		return SetCache.size() - 1;
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