

import java.util.Scanner;

public class A_Sliding {

    public static void main(String args[]){
        
        Scanner takeInput = new Scanner(System.in);
        int t = takeInput.nextInt();

        while (t > 0) {

            solve(takeInput);
            t = t-1;
        }

        takeInput.close();
    }


    public static void solve(Scanner takeInput){
        
        long n, m, r, c;

        n = takeInput.nextInt();
        m = takeInput.nextInt();
        r = takeInput.nextInt();
        c = takeInput.nextInt();

        long x = n*m - ((r-1)*m + c) -1;
        long y = n-r;

        System.out.println((m*y + x) - y +1);
    }
    
}
