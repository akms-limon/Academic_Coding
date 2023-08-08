interface Bicycle{
    int a = 45;
    void applyBrake(int decrement);
    void speedUP(int increment);
}

interface Cyclename{
    void name();
}

class Base{
    Base(){
        System.out.println("I am Base class.");
    }
}

class AvonCycle extends Base implements Bicycle, Cyclename{
    int speed = 5;
    @Override
    public void applyBrake(int decrement){
        speed = speed - decrement;
        System.out.println("After speed down speed is : "+speed);
    }
    @Override
    public void speedUP(int increment){
        speed = speed + increment;
        System.out.println("After speed up speed is : "+speed);
    }
    @Override
    public void name(){
        System.out.println("I am a Bicycle");
    }
}

public class Interface {
    public static void main(String[] args) {
        AvonCycle c = new AvonCycle();
        c.applyBrake(2);
        c.speedUP(10);
        System.out.println(c.a);  //you can create properties in Interfaces
        //You cannot modify the properties in Interfaces as they are final
        //c.a = 143;
        c.name();
    }
}
