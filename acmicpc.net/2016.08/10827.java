import java.util.Scanner;
import java.math.BigDecimal;
public class Main {
  public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        String num=input.next();
        int n=input.nextInt();
        BigDecimal n1=new BigDecimal(num);
        System.out.println(n1.pow(n).toPlainString());
    }
}