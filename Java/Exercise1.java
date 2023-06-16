import java.util.Scanner;

class Library{
    Library(){
        System.out.println("********Welcome to eLibrary********");
        System.out.println("Please select any option from below : \n1.addBook\n2.issueBook\n3.returnBook\n4.showAvailableBooks\n5.showIssuedBooks\n6.Exit");
    }
    Scanner sc = new Scanner(System.in);
    int input(){
        int n = sc.nextInt();
        return n;
    }
    int [] arr = new int[] {4, 2, 5, 3, 5, 6, 4, 4, 2, 7};
    int [] issue = new int[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    void addBook(){
        System.out.println("How many books you wants to add : ");
        int cnt = sc.nextInt();
        System.out.println("Enter your Book serial no and Quantity of those books : ");
        for(int i = 0; i<cnt; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            arr[x-1]+=y;
        }
    }
    void issueBook(){
        System.out.println("How many books you wants to issue : ");
        int cnt = sc.nextInt();
        System.out.println("Enter your Book serial no and Quantity of those books : ");
        for(int i = 0; i<cnt; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            arr[x-1]-=y;
            issue[x-1]+=y;
        }
    }
    void returnBook(){
        System.out.println("How many books you wants to Return : ");
        int cnt = sc.nextInt();
        System.out.println("Enter your Book serial no and Quantity of those books : ");
        for(int i = 0; i<cnt; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            arr[x-1]+=y;
            issue[x-1]-=y;
        }
    }
    void showAvailableBooks(){
        for(int i : arr){
            System.out.print(i+" ");
        }
        System.out.println();
    }
    void showIssuedBooks(){
        for(int i : issue){
            System.out.print(i+" ");
        }
        System.out.println();
    }
    void Exit(){
        System.out.println("************Thanks for using eLaibrary.*************");
    }
}

public class Exercise1 {
    public static void main(String[] args) {
        Library l = new Library();
        while(true){
            int p = l.input();
            if(p==1) l.addBook();
            else if(p==2) l.issueBook();    
            else if(p==3) l.returnBook();
            else if(p==4) l.showAvailableBooks();
            else if(p==5) l.showIssuedBooks();
            else {
                l.Exit(); break;
            }
        }
    }
}
