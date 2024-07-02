class Circle{
    public int radius; 
    Circle(){
        System.out.println("I am non paramiterize circle.");
    }
    Circle(int r){
        System.out.println("I am circle parameterized constructor.");
        this.radius = r;
    }
    public double area(){
        return Math.PI*this.radius*this.radius;
    }
}

class Cylinder extends Circle{
    Cylinder(int r, int h){
        super(r);
        System.out.println("I am cylinder parameterized constructor.");
        this.height = h;
    }
    public int height;
    public double volume(){
        return Math.PI*this.radius*this.radius*this.height;
    }
}

public class Exercise {
    public static void main(String[] args) {
        Cylinder obj = new Cylinder(1, 2);
        // Circle c = new Circle(12);
    }
}