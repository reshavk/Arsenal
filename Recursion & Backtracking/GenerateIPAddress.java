/*
Given a string s containing only digits, Your task is to complete the function genIp which 
returns a vector containing all possible combination of valid IPv4 ip address and takes only 
a string s as its argument . 

For string 11211 the ip address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Originally the problem is to be solved using some backtracking method keeping track of dots and length,
but here is a naiive solution to the same problem.
*/

import java.io.*;
import java.util.*;

public class Solution {	

	public static boolean ok(String a, String b, String c, String d) {
		int A,B,C,D;
		A = Integer.parseInt(a);
		B = Integer.parseInt(b);
		C = Integer.parseInt(c);
		D = Integer.parseInt(d);
		if(A <= 255 && B <= 255 && C <= 255 && D <= 255) 
			return true;
		else
			return false;
	}
	
	public static ArrayList<String> genIp(String s) {
		ArrayList<String> ans = new ArrayList<String>();
		String a, b, c, d, temp;
		int x, y, w, z;
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				for(int k=1; k<=3; k++) {
					for(int l=1; l<=3; l++) {
						if(i+j+k+l == s.length()) {
							a = s.substring(0, i);
							b = s.substring(i, i+j);
							c = s.substring(i+j, i+j+k);
							d = s.substring(i+j+k, i+j+k+l);
							
							if(ok(a, b, c, d)) {
								x = Integer.parseInt(a);
								y = Integer.parseInt(b);
								w = Integer.parseInt(c);
								z = Integer.parseInt(d);
								temp = Integer.toString(x) + "." + Integer.toString(y) + "." + Integer.toString(w) + "." + Integer.toString(z);
								if(temp.length() == s.length() + 3)
									ans.add(temp);
							}
						}
					}
				}
			}
		}
		return ans;
	}
	
	public static void main(String args[]) {
		String s = "50361";
		ArrayList<String> ips = new ArrayList<String>();
		ips = genIp(s);
		
		for(String x : ips) {
			System.out.println(x);
		}
	}
}
