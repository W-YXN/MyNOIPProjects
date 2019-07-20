import java.util.Scanner;

public class reversepair {
    public static int InversePairs(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        int[] copy = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            copy[i] = arr[i];
        }
        int count = InversePairsCore(arr, copy, 0, arr.length - 1);
        return count;
    }

    private static int InversePairsCore(int[] arr, int[] copy, int l, int r) {
        if (l == r) {
            return 0;
        }
        int mid = (l + r) >> 1;
        int leftCount = InversePairsCore(arr, copy, l, mid);
        int rightCount = InversePairsCore(arr, copy, mid + 1, r);
        int count = 0;
        int i = mid;
        int j = r;
        int indexC = r;
        while (i >= l && j > mid) {
            if (arr[i] > arr[j]) {
                count += j - mid;
                copy[indexC--] = arr[i--];
            } else {
                copy[indexC--] = arr[j--];
            }
        }
        for (; i >= l; i--) {
            copy[indexC--] = arr[i];
        }
        for (; j > mid; j--) {
            copy[indexC--] = arr[j];
        }
        for (int s = l; s <= r; s++) {
            arr[s] = copy[s];
        }
        return (leftCount + rightCount + count);
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=scn.nextInt();
        }
        int ans=InversePairs(a);
        System.out.println(ans);
        scn.close();
    }
}