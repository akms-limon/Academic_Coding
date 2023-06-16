class Employee{
    int id; 
    String name;
    public void printDetails(){
        System.out.println("My ID is : "+ id);
        System.out.println("My name is : "+ name);
    }
}

public class CustomClass {
    public static void main(String[] args) {

        Employee limon = new Employee();
        limon.id = 200117;
        limon.name = "A K M S Limon";
        
        Employee harry = new Employee();
        harry.id = 12345; 
        harry.name = "CodeWithHarry";

        limon.printDetails();
        harry.printDetails();
    }
}
