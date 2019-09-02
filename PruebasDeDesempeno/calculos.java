import java.util.*;
import java.math.*;

public class calculos {
	public static void main(String[] args) {
		double MAX = 1e8;

		double i = 1;
		double seno = 0;
		double coseno = 0;
		double tangente = 0;
		double logaritmo = 0;
		double raizCuadrada = 0;

		while (i < MAX) {
			seno += Math.sin(i);
			coseno += Math.cos(i);
			tangente += Math.tan(i);
			logaritmo += Math.log(i);
			raizCuadrada += Math.sqrt(i);
			i++;
		}
	}
}
