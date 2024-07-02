interface sampleInterface{
    void method1();
    void method2();
}

interface child extends sampleInterface{ 
    void method3();
    void method4();
}

class MySampleClass implements child{
    @Override
    public void method1() {
        System.out.println("Mehtod1.");
    }
    @Override
    public void method2() {
        System.out.println("Method2");
    }
    @Override
    public void method3() {
        System.out.println("Method3.");
    }
    @Override
    public void method4() {
        System.out.println("Method4.");
    }
}
public class InheritanceInInterfaces {
    public static void main(String[] args) {
        
    }
}
