import java.util.*;

public class GPSeries {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the nth index term of the series: ");
        int n = sc.nextInt();

        if (n > 30) {
            System.out.println("You can only find the number below 30 in the series");
            return;
        }

        if (n % 2 == 0) {
            System.out.println((int)(Math.pow(3, n / 2 - 1)));
        } else {
            System.out.println((int)(Math.pow(2, (n - 1) / 2)));
        }

    }
}