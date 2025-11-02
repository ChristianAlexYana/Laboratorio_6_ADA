public class Escalones{
    public static void main (String [] args){
    int n = 5;
    System.out.println("Numero de formas de subir "+n+" escalones: "+escalones(n));
    }

    public static int escalones(int n){
        if(n<0){
            System.out.println("No se puede subir escalones negativos");
            return -1;
        }
        if(n==0){
            return 0;
        }

        int [] tabla = new int[n+1];
        tabla[0] = 1; // ya esta en la cima
        if(n>=1)tabla[1] = 1;
        if(n>=2) tabla[2] = 2;
        for(int i =3; i <=n; i++){
            tabla[i] = tabla[i-1]+tabla[i-2]+tabla[i-3];
        }
        return tabla[n];
    }
}