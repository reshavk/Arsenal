import java.util.*;
import java.net.*;

class DNSlookup {
	static InetAddress add;
	
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter IP address/URL : ");
		String data = in.nextLine();
		
		try {
			if(data.charAt(0) >= '0' && data.charAt(0) <= '9') {
				byte[] b = new byte[4];
				String[] ip_split = data.split("[.]");
				for(int i=0; i<4; i++) {
					b[i] = new Integer(ip_split[i]).byteValue();
				}
				add = InetAddress.getByAddress(b);
				System.out.println("URL for given ip address : " + add.getHostName());
			}
			else{
				add = InetAddress.getByName(data);
				System.out.println("IP for given url : " + add.getHostAddress());
			}
		}
		catch(Exception e) {
			System.out.println(e);
			System.exit(0);
		}
	}
}
