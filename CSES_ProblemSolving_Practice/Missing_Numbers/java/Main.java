import java.util.*;

class Main {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int sum = 0;
        for(int i = 1;i<=n;i++){
            sum ^= i;
        }
        
        for(int i = 1;i<=n-1;i++){
            int val = sc.nextInt();
            sum = sum ^ val;
        }   System.out.println(sum);
        
    }
    
}