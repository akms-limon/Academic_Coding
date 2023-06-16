class Mythread1 extends Thread{
    @Override
    public void run(){
        int i = 1;
        while(i<40000){
            System.out.println("I am cooking.");
            System.out.println("I am happy.");
            i++;
        }
    }
}

class Mythread2 extends Thread{
    @Override
    public void run(){
        int i = 1;
        while(i<40000){
            System.out.println("AAAAAAAAAAA");
            System.out.println("BBBBBBBBBBB");
            i++;
        }
    }
}

public class Threading {
    public static void main(String[] args) {
        Mythread1 t1 = new Mythread1();
        Mythread2 t2 = new Mythread2();
        t1.start();
        t2.start();
    }
}
