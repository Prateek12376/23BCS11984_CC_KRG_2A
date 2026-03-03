import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long k = Long.parseLong(br.readLine());
        String s = br.readLine();
        int n = s.length();
        long ans = 0;

        if (k == 0) {
            long count = 0;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '0') {
                    count++;
                } else {
                    ans += count * (count + 1) / 2;
                    count = 0;
                }
            }
            ans += count * (count + 1) / 2;
        } else {
            int left = 0;
            long sum = 0;
            long[] prefix = new long[n + 1];
            prefix[0] = 1;

            for (int right = 0; right < n; right++) {
                sum += s.charAt(right) - '0';
                if (sum >= k) {
                    ans += prefix[(int)(sum - k)];
                }
                prefix[(int)sum]++;
            }
        }

        System.out.println(ans);
    }
}
