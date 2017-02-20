import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		int t;
		Scanner s = new Scanner(System.in);
		t = s.nextInt();
		while (t-- != 0) {
			String a, b;
			a = s.next();
			b = s.next();
			long aa = Long.valueOf(a, 8);
			long  bb = Long.valueOf(b, 8);
			if (aa >= bb) System.out.println(Long.toOctalString(aa - bb));
			else System.out.println("-" + Long.toOctalString(bb - aa));
		}
	}
}
