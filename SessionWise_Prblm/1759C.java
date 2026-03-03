import java.util.*;

public class Main {

    static boolean canJump(long from, long to, long x) {
        return Math.abs(from - to) >= x;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {

            long l = sc.nextLong();
            long r = sc.nextLong();
            long x = sc.nextLong();
            long a = sc.nextLong();
            long b = sc.nextLong();

            if (a == b) {
                System.out.println(0);
                continue;
            }

            if (canJump(a, b, x)) {
                System.out.println(1);
                continue;
            }

            boolean twoSteps =
                    (canJump(a, l, x) && canJump(l, b, x)) ||
                    (canJump(a, r, x) && canJump(r, b, x));

            if (twoSteps) {
                System.out.println(2);
                continue;
            }

            boolean threeSteps =
                    (canJump(a, l, x) && canJump(l, r, x) && canJump(r, b, x)) ||
                    (canJump(a, r, x) && canJump(r, l, x) && canJump(l, b, x));

            if (threeSteps) {
                System.out.println(3);
            } else {
                System.out.println(-1);
            }
        }
    }
}
