import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	void print(String in, int wid) {
		System.out.print(in);
		for (int i = 0; i < wid - in.length(); i++) {
			System.out.print(" ");
		}
	}
	
	void run() {
		int n;
		while (sc.hasNext()) {
			n = sc.nextInt();
			String[] list = new String[n];
			int max = 0;
			for (int i = 0;i < n; i++) {
				list[i] = sc.next();
				max = list[i].length() > max ? list[i].length() : max;
			}
			sort(list);
			int w = max + 2;
			int c = (int) floor(62.0 / w);
			int r = (int) ceil((double) n / c);
			System.out.println("------------------------------------------------------------");
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (i + j * r < n)
					print(list[i + j * r], j == c - 1 ? w - 2 : w);
				}
				System.out.println();
			}
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