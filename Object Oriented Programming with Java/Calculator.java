class NormalCalculator{
    void calculate(int a, int b){
        System.out.println(a+b);
    }
}

class ScientificCalculator {
    void calculate(int a, int b) {
        System.out.println(Math.sin(a+b));
    }
}

class HybridCalculator{
    void calculate(int a, int b){
        System.out.println(a+b);
        System.out.println(Math.sin(a+b));
    }
}

public class Calculator {
    public static void main(String[] args) {
        System.out.println("I am main class.");
    }
}