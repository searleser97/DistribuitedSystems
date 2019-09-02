import java.util.Random;
import java.util.Scanner;

public class Cadena {

  public static void main(String[] args) {
    String cadenota = "";
    int n = 17576 * 10;
    int k = 0, m = 3;
    Random rnd = new Random();
    while (k < n) {
      String cadena = "";
      for (int i = k; i < k + m; i++) {
        cadena += ((char)(rnd.nextDouble() * 26 + 65)) + "";
      }
      if (k != 0)
        cadenota += " ";
      k += m;

      cadenota += cadena;
    }
    System.out.println(cadenota);

    String strFind = "IPN";
    int count = 0, fromIndex = 0;

    while ((fromIndex = cadenota.indexOf(strFind, fromIndex)) != -1) {

      count++;
      fromIndex++;
    }
    System.out.println("cadena IPN encontrada " + count + " veces.");
  }
}