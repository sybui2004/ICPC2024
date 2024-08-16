import java.util.*;
import java.math.*;

public class B {

    public static int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
    public static HashMap<Long, Long> map;
    public static BigInteger[][] powers;
    public static BigInteger[][] combo;

    public static void main(String[] args) {

        combo = new BigInteger[64][64];
        for (int i = 0; i < 64; i++) {
            combo[i][0] = new BigInteger("1");
            combo[i][i] = new BigInteger("1");
        }
        for (int i = 2; i < 64; i++)
            for (int j = 1; j < i; j++)
                combo[i][j] = combo[i - 1][j - 1].add(combo[i - 1][j]);

        powers = new BigInteger[primes.length][64];

        for (int i = 0; i < powers.length; i++) {
            powers[i][0] = new BigInteger("1");
            BigInteger prod = new BigInteger("" + primes[i]);
            for (int j = 1; j < powers[i].length; j++)
                powers[i][j] = powers[i][j - 1].multiply(prod);
        }

        map = new HashMap<Long, Long>();
        for (int i = 1; i <= 62; i++)
            Try(i, 0, new BigInteger("1"), new BigInteger("1"), i, 0);

        Scanner stdin = new Scanner(System.in);
        int t = stdin.nextInt();
        while (t-- > 0) {
            long val = stdin.nextLong();
            System.out.println(val + " " + map.get(val));
        }
        stdin.close();
    }

    public static boolean tooBig(BigInteger b) {
        return b.compareTo(powers[0][63]) >= 0;
    }

    public static void Try(int sum, int cur, BigInteger n, BigInteger next, int max, int k) {

        if (cur > sum)
            return;
        if (k > primes.length)
            return;

        if (sum == cur) {

            if (tooBig(n) || tooBig(next))
                return;

            if (!map.containsKey(next.longValue()))
                map.put(next.longValue(), n.longValue());

            else if (n.longValue() < map.get(next.longValue())) {
                map.put(next.longValue(), n.longValue());
            }
            return;
        }

        else if (k == primes.length)
            return;

        for (int i = 1; i <= max; i++) {

            BigInteger newNum = n.multiply(powers[k][i]);

            if (tooBig(newNum))
                break;

            Try(sum, cur + i, newNum, next.multiply(combo[cur + i][i]), i, k + 1);
        }
    }

}