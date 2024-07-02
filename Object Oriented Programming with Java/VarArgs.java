public class VarArgs {
    static int sum(int ...a){
        int result = 0;
        for(int i : a){
            result+=i;
        }
        return result;
    }

    public static void main(String[] args) {
        
        System.out.println(sum());
        System.out.println(sum(2, 3));
        System.out.println(sum(1,3,5,4));
        System.out.println(sum(1,6,4,3,2,5));
    }
}
