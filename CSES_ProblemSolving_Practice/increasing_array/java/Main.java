
import java.util.*;

class Main {
    
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        long n = sc.nextLong();
        
        long res = 0;
        ArrayList<Long> a = new ArrayList<>();
        
        for(int i = 0;i<n;i++){
            a.add(sc.nextLong());
        }
        for(int i = 1;i<n;i++) {
            long diff = a.get(i) - a.get(i-1);
            if(diff < 0){
                res += Math.abs(diff);
                a.set(i, a.get(i) + Math.abs(diff)); 
            }
        }
           System.out.println(res);
    }
}