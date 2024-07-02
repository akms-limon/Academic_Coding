/*Method overloading is called if we make method with same name.
we can overload method depending on parameters. and it works also
depending on parameters.
*/

public class MethodOverloading {

    static void sum(){
        System.out.println("Hello friend. Sum is not always the ultimate goal.");
    }

    static int sum(int a, int b){
        int z = a+b;
        return z;
    }
    static double sum(double a, double b){
        double z = a-b;
        return z;
    }
    public static void main(String[] args) {

        sum();

        int a= 10, b = 20;
        System.out.println(sum(a, b));

        double x = 11, y = 10;
        System.out.println(sum(x, y));
    }
}
