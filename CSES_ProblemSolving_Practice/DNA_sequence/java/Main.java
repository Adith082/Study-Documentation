/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int cnt = 1;
		int maxx = 1;
		
		for(int i = 1;i<s.length();i++){
		    
		    if(s.charAt(i) == s.charAt(i-1)) {
		        cnt++;
		    }  else {
		        maxx = Math.max(maxx, cnt);
		        cnt = 1;
		    }
		}       maxx = Math.max(maxx, cnt);
		
	     System.out.println(maxx);
	}
}
