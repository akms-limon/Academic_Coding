/*constructor : Constructor is a method of a class it is automatically called when an object is created.
 *every class has a default constructor. If we Declare a constructor then default constructor is deleted.
 *constructor is similier to method. Constructor name and the class name is same. we can override constructor
 *like method. usualy constructor and method are same.
 * constructor is need to pre-initialize data. for example if I go to
 * buy a car. when I buing the car ofcourse the car have to a colour and all other properties
 * by constructor we can pre-defined these properties.
 */

class MyEmployee{
    private int id;
    private String name;

    public MyEmployee(){  //initialize a employee limon and id 12. when every objects is created of the class
                            // MyEmployee it will be the employee limon and id 12.
        id = 12;
        name = "akms limon";
    }

    public String getName(){
        return name;
    }
    public void setName(String s){
        this.name = s;
    }
    public void setId(int i){
        this.id = i;
    }
    public int getId(){
        return id;
    }
}

public class Constractor {
    public static void main(String[] args) {
        MyEmployee limon = new MyEmployee();
        // limon.setName("mahmud");
        // limon.setId(200117);
        System.out.println(limon.getName());
        System.out.println(limon.getId());
    }
}
