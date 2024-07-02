abstract class Pen{
    abstract void write();
    abstract void refill();
}

class FountainPen extends Pen{
    @Override
    void write() {
        System.out.println("Write");
    }
    @Override
    void refill() {
        System.out.println("Refill");
    }
    void changeNib(){
        System.out.println("Changing the name.");
    }
}

class Monkey{
    void jump(){
        System.out.println("jump");
    }
    void bite(){
        System.out.println("Bite");
    }
}

interface BasicAnimal{
    void eat();
    void sleep();
}

class Human extends Monkey implements BasicAnimal{
    void speak(){
        System.out.println("Speaking...");
    }
    @Override
    public void eat() {
        System.out.println("Eating...");
    }
    @Override
    public void sleep() {
        System.out.println("Sleeping...");
    }
}

public class ExerciseAbstruction {
    public static void main(String[] args) {
        //Q1+Q2
        FountainPen pen = new FountainPen();
        pen.changeNib();
        //Q3
        Human limon = new Human();
        limon.sleep();
        limon.bite();
        //Q5
        Monkey m = new Human();
        m.jump();
        BasicAnimal a = new Human();
        a.eat();
        a.sleep();
        
    }
}
