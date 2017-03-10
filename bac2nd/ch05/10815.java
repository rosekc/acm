import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	Set<String> s = new TreeSet<>();
	void run() {
		String t = new String();
		while (sc.hasNext()) {
			t = sc.next();
			String []tmp = t.toLowerCase().split("[^a-z]");
			for (String i : tmp) {
				s.add(i);
			}
		}
		for (String i : s) {
			if (!i.equals("")) System.out.println(i);
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