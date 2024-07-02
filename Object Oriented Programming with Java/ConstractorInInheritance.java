class Parent{
    Parent(){
        System.out.println("I am a Parent class constructor.");
    }
    Parent(int x){
        System.out.println("I am an overloded constructor of Parent class with value of x as : "+x);
    }
}

class Child extends Parent{
    Child(){
        //super(4);
        System.out.println("I am a Child class constructor.");
    }
    Child(int x, int y){
        super(x);
        System.out.println("I am an overloded constructor of Child class with value of x and y as : "+ x + " and " + y);
    }
}

class GrandChild extends Child{
    GrandChild(){
        System.out.println("I am a constructor of GrandChild class.");
    }
    GrandChild(int x, int y, int z){
        super(x, y);
        System.out.println("I am an overloded constructor of GrandChild class.");
    }
}

public class ConstractorInInheritance {
    public static void main(String[] args) {
        //Parent b = new Parent();
        //Child d = new Child();
        //Child d = new Child(47, 29);
        GrandChild g = new GrandChild(3, 5, 6);
    }
}
