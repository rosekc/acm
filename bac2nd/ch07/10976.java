import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;
 
public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	void run() {
		while (sc.hasNext()) {
			int k = sc.nextInt();
			int con = 0;
			StringBuilder sb = new StringBuilder();
			for (int y = k + 1; y <= 2 * k; y++) {
				if (k * y % (y - k) == 0) {
					con++;
					sb.append(String.format("1/%d = 1/%d + 1/%d\n", k, k * y / (y - k) , y));
				}
			}
			System.out.println(con);
			System.out.print(sb);
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