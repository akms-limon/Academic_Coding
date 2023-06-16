/*Inheritance means create a new object or class using the existing class 
re-using the existing class. It is a prossess of acuring the features of an existing class 
into a new class.*/
class circle{
    public int redius; 
}

class cylinder extends circle{
    public int height; 
}

public class Inheritance {
    public static void main(String[] args) {
        cylinder cl = new cylinder();
        cl.redius = 5;
        cl.height = 3;
    }
}
