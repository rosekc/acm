import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String str;
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t-- != 0) {
            str = s.next();
            String[] tmp = str.split("-");
            int sec = s.nextInt();
            Calendar re = Calendar.getInstance();
            re.set(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]) - 1, Integer.parseInt(tmp[2]), 0, 0, sec);
            System.out.println((new SimpleDateFormat("yyyy-MM-dd")).format(re.getTime()));
            //System.out.println(c.get(c.DAY_OF_YEAR));
        }
    }
}