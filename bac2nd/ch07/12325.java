import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);

	void run() {
		int T = sc.nextInt();
		int kase = 1;
		while (T-- != 0) {
			int n = sc.nextInt();
			int s1 = sc.nextInt();
			int v1 = sc.nextInt();
			int s2 = sc.nextInt();
			int v2 = sc.nextInt();
			if (s1 < s2) {
				int t = s1;
				s1 = s2;
				s2 = t;
				t = v1;
				v1 = v2;
				v2 = t;
			}
			long bestv = -1;
			if (n / s1 < max(s1, s2)) {
				for (long i = 0; i * s1 <= n; i++) {
					bestv = max(bestv, (n - s1 * i) / s2 * v2 + i * v1);
				}
			} else {
				/*
				 * 枚举方法B分析 
				 * 使宝物1数量为s2宝物2数量s1，此时两种宝物的大小一样，这里称之为一份宝物
				 * 当n大于一份宝物大小时，易知选价值最高的一份 这样不停放宝物，直到剩余空间少于一份宝物
				 * 这时两种宝物能放的数量绝对不大于s2，s1 综上两种情况，直接枚举两种宝物使其分别不大于s2，s1，即得到最大价值
				 */
				if (v1 / s1 >= v2 / s2)
					for (long i = 0; i <= s1; i++) {
						bestv = max(bestv, v2 * i + (n - s2 * i) / s1 * v1);
					}
				if (v1 / s1 <= v2 / s2)
					for (long i = 0; i <= s2; i++) {
						bestv = max(bestv, v1 * i + (n - s1 * i) / s2 * v2);
					}
			}
			System.out.printf("Case #%d: %d\n", kase++, bestv);
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