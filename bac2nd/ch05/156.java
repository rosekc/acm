import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	Map<String, Integer> m = new TreeMap<>();
	Vector<String> list =  new Vector<>();
	String ch(String in) {
		char[] a = in.toLowerCase().toCharArray();
		sort(a);
		return String.valueOf(a);
	}
	
	void run() {
		while (true) {
			String t = sc.next();
			if (t.equals("#")) break;
			list.add(t);
			t = ch(t);
			Integer tint = m.get(t);
			if (tint == null) m.put(t, 1);
			else m.put(t, tint + 1);
		}
		Vector<String> ans = new Vector<>();
		for (String i : list) {
			Integer tt = m.get(ch(i));
			if (tt != null && tt == 1) ans.add(i);
		}
		Collections.sort(ans);
		for (String i : ans) {
			System.out.println(i);
		}
		
	}


	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
				//System.setIn(new FileInputStream("in.txt"));
				//System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}