import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        BigInteger ans[] = new BigInteger[260];
        ans[0] = BigInteger.valueOf(0);
        ans[1] = BigInteger.valueOf(1);
        ans[2] = BigInteger.valueOf(3);
        for (int i = 3; i < 252; i++) {
            ans[i] = ans[i - 1].add(ans[i - 2].multiply(BigInteger.valueOf(2)));
        }
        int tmp;
        while (sn.hasNext()) {
            tmp = sn.nextInt();
            System.out.println(ans[tmp]);
        }
        sn.close();
    }
}