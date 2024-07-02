class Overriding{
    public void math(){
        System.out.println("I am a method of parent class.");
    }
}
class ChildOver extends Overriding{
    @Override
    public void math(){
        System.out.println("I am a method of child class.");
    }
}

public class MethodOverriding {
    public static void main(String[] args) {
        Overriding o = new Overriding();
        o.math();
        ChildOver c = new ChildOver();
        c.math();
    }
}
