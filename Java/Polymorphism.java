/*polymorphism means one name different actions. polymorphism is same as generalization.*/
interface Camera2{
    void takesnap();
    void recordvideo();
    private void greet(){
        System.out.println("Good morning.");
    }
    default void record4kVideo2(){
        greet();
        System.out.println("Recording 4k video.");
    }
}

interface Wifi2{
    String[] getNetworks();
    void connectToNetwork(String network);
}

class MyCellPhone2{
    void callNumber(int phoneNumber){
        System.out.println("Calling "+ phoneNumber);
    }
    void pickCall(){
        System.out.println("Connecting...");
    }
}

class MySmartPhone2 extends MyCellPhone2 implements Wifi2, Camera2{
    @Override
    public void takesnap(){
        System.out.println("Taking snap.");
    }
    @Override
    public void recordvideo(){

    }
    @Override
    public String[] getNetworks(){
        System.out.println("Geting list of Networks.");
        String[] networkList = {"Limon", "Mahmud"};
        return networkList;
    }
    @Override
    public void connectToNetwork(String network){
        System.out.println("Connecting to "+network);
    }
    // @Override
    // public void record4kVideo(){
    //     System.out.println("Taking snap and recording 4k videos.");
    // }
}
public class Polymorphism {
    public static void main(String[] args) {
        Camera2 c = new MySmartPhone2(); // c is a smartphone but use it as a camera
        c.takesnap();
        c.record4kVideo2();
        // c.getNetworks(); Not allowed
    }
}
