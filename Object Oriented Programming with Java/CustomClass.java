class Employee{
    int id;
    String name;
    public void printdetails(){
        System.out.println("Name : "+name);
        System.out.println("ID : "+id);
    }
}

public class CustomClass{
    public static void main(String[] args) {
        Employee limon = new Employee();
        limon.id = 384;
        limon.name = "Limon";
        limon.printdetails();
        Employee Harry = new Employee();
        Harry.id = 457;
        Harry.name = "Harry";
        Harry.printdetails();
    }
}