class Modifiers{
    public int x = 5;
    protected int y = 45;
    int z = 6;
    private int a = 78;
    public void meth1(){
        System.out.println(x);
        System.out.println(y);
        System.out.println(z);
        System.out.println(a);
    }
}

public class AccessModifier {
    public static void main(String[] args) {
        Modifiers m = new Modifiers();
        m.meth1();
        System.out.println(m.x);
        System.out.println(m.y);
        System.out.println(m.z);
        // System.out.println(m.a); //Not allowed private modifier in another class
    }
}
