import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int T = sc.nextInt();
		while (T-- != 0) {
			long x1, x2, x3, x4, y1, y2, y3,y4;
			x1 = sc.nextLong();
			y1 = sc.nextLong();
			x2 = sc.nextLong();
			y2 = sc.nextLong();
			x3 = sc.nextLong();
			y3 = sc.nextLong();
			x4 = sc.nextLong();
			y4 = sc.nextLong();
			BigDecimal a, b, c, d,e, f;
			a = BigDecimal.valueOf(x2).subtract(BigDecimal.valueOf(x1)).multiply(BigDecimal.valueOf(2));
			b = BigDecimal.valueOf(y2).subtract(BigDecimal.valueOf(y1)).multiply(BigDecimal.valueOf(2));
			c = BigDecimal.valueOf(x2).pow(2)
					.add(BigDecimal.valueOf(y2).pow(2))
					.subtract(BigDecimal.valueOf(x1).pow(2))
					.subtract(BigDecimal.valueOf(y1).pow(2));
			d = BigDecimal.valueOf(x3)
					.subtract(BigDecimal.valueOf(x2))
					.multiply(BigDecimal.valueOf(2));
			e = BigDecimal.valueOf(y3)
					.subtract(BigDecimal.valueOf(y2))
					.multiply(BigDecimal.valueOf(2));
			f = BigDecimal.valueOf(x3).pow(2)
					.add(BigDecimal.valueOf(y3).pow(2))
					.subtract(BigDecimal.valueOf(x2).pow(2))
					.subtract(BigDecimal.valueOf(y2).pow(2));
			BigDecimal x, y, l, r;
			x = b.multiply(f).subtract(e.multiply(c)).divide(b.multiply(d).subtract(e.multiply(a)));
			y = d.multiply(c).subtract(a.multiply(f)).divide(b.multiply(d).subtract(e.multiply(a)));
			l = BigDecimal.valueOf(x4).subtract(x).pow(2).add(BigDecimal.valueOf(y4).subtract(y).pow(2));
			r = BigDecimal.valueOf(x1).subtract(x).pow(2).add(BigDecimal.valueOf(y1).subtract(y).pow(2));
			//debug(x.toString(), y.toString());
			//debug(l.toString(), r.toString());
			if (l.compareTo(r) == 1) {
				System.out.println("Accepted");
			}else {
				System.out.println("Rejected");
			}
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
				// System.setIn(new FileInputStream("in.txt"));
				// System.setOut(new PrintStream("out.txt"));
			} catch (Throwable e) {
				LOCAL = false;
			}
		}
		new Main().run();
	}
}