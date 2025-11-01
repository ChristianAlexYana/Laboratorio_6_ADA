public class Fibonacci {
    public static void main(String[] args) {
    int n = -1;
    System.out.println("Fibonacci de la posicion "+n+" es: "+fibonacci(n));
    }
    public static int fibonacci(int n){
        if (n < 0) {
            System.out.println("Error: la posicion no puede ser negativa.");
            return -1;
        }

        if (n <= 1) {
            return n;
        }

        int []tabla =  new int[n+1];
        tabla[0] = 0;
        tabla[1] = 1;
        for(int i = 2; i <= n; i++){
            tabla[i] = tabla[i - 1] + tabla[i-2];
        }
        return tabla[n];
    }
}