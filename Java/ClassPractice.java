/*Everythins in the real world is a object. Object has two things : 1. properties 2.behaviors
Write a essay and find the noun and adjective they are the properties or attributes. and find verbs, verbs is
the behaviours or method.

Difference between class and objects :
            class                                                objects
class is a design of a house and car            Objects is the house we make. we can make many house by the
                                                design.
*/
class Teacher {
    int salary;
    String name;
    String location;
    String mobile;
    public void setMobile(String s){
        mobile = s;
    }
    public void setLocation(String s){
        location = s;
    }
    public int getSalary(){
        return salary;
    }
    public String getName(){
        return name;
    }
    public void setName(String s){
        name = s;
    }
    public void getDetails(){
        System.out.println("Name : "+name);
        System.out.println("mobile no : "+mobile);
        System.out.println("Salary : " +salary);
        System.out.println("Location : "+location);
    }
}

public class ClassPractice{
    public static void main(String[] args) {

        Teacher nipa = new Teacher();
        nipa.salary = 500;
        nipa.setName("Nusrat Jahan Nipa");
        nipa.setLocation("Mirzapara");
        nipa.setMobile("01518464154");

        Teacher nishi = new Teacher();
        nishi.setName("Jannatun Nahar Nishi");
        nishi.salary = 600;
        nishi.setLocation("Kortimari");
        nishi.setMobile("01916652699");

        Teacher limon = new Teacher();
        limon.setName("A K M S Limon");
        limon.salary = 700;
        limon.setLocation("Roumari");
        limon.setMobile("0195624824");

        limon.getDetails();
        System.out.println();
        nipa.getDetails();
        System.out.println();
        nishi.getDetails();
    }
}