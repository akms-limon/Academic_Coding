interface Camera{
    void takesnap();
    void recordvideo();
    private void greet(){
        System.out.println("Good morning.");
    }
    default void record4kVideo(){
        greet();
        System.out.println("Recording 4k video.");
    }
}

interface Wifi{
    String[] getNetworks();
    void connectToNetwork(String network);
}

class MyCellPhone{
    void callNumber(int phoneNumber){
        System.out.println("Calling "+ phoneNumber);
    }
    void pickCall(){
        System.out.println("Connecting...");
    }
}

class MySmartPhone extends MyCellPhone implements Wifi, Camera{
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

public class DefaultMethodinInterface {
    public static void main(String[] args) {
        MySmartPhone ms;
        ms = new MySmartPhone();
        String[] ar = ms.getNetworks();
        for(String s : ar){
            System.out.println(s);
        }
        ms.record4kVideo();
    }   
}
