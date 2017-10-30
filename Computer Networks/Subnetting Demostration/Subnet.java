import java.util.*;

class Subnet {
	
	static String appendZeroes(String s) {
		String temp = "00000000";
		return temp.substring(s.length()) + s;
	}
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter IP address : ");
		String ip = in.nextLine();
		String[] ip_split = ip.split("[.]");
		String bip = "";
		
		System.out.print("IP in binary : ");
		for(int i=0; i<4; i++) {
			ip_split[i] = appendZeroes(Integer.toBinaryString(Integer.parseInt(ip_split[i])));
			System.out.print(ip_split[i]);
			if(i != 3){
				System.out.print(".");
			}
			bip += ip_split[i];
		}
		System.out.println();
		System.out.println("IP : " + bip);
		
		System.out.print("Enter no. of addresses : ");
		int n = in.nextInt();
		int bits = (int)Math.ceil(Math.log(n)/Math.log(2));
		System.out.println("Bits required : " + bits);
		System.out.println("Subnet mask : " + (32-bits));
		
		int[] fbip = new int[32];
		for(int i=0; i<32; i++) {
			fbip[i] = (int) (bip.charAt(i) - 48);
		}
		for(int i=31; i>31-bits; i--) {
			fbip[i] &= 0;
		}
		
		String[] fip = {"", "", "", ""};
		for(int i=0; i<32; i++) {
			fip[i/8] = new String(fip[i/8] + fbip[i]);
		}
		System.out.print("First IP address : ");
		for(int i=0; i<4; i++) {
			System.out.print(Integer.parseInt(fip[i],2));
			if(i != 3) {
				System.out.print(".");
			}
		}
		System.out.println();
		
		int[] lbip = new int[32];
		for(int i=0; i<32; i++) {
			lbip[i] = (int) (bip.charAt(i) - 48);
		}
		for(int i=31; i>31-bits; i--) {
			lbip[i] |= 1;
		}
		
		String[] lip = {"", "", "", ""};
		for(int i=0; i<32; i++) {
			lip[i/8] = new String(lip[i/8] + lbip[i]);
		}
		System.out.print("Last IP address : ");
		for(int i=0; i<4; i++) {
			System.out.print(Integer.parseInt(lip[i],2));
			if(i != 3) {
				System.out.print(".");
			}
		}
		System.out.println();	
	}
}
