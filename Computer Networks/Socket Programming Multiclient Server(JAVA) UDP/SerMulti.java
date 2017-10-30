import java.io.*;
import java.net.*;

class SerMulti {
	DatagramSocket socket;
	DatagramPacket packet;
	BufferedReader in;
	byte[] buff;
	
	int port = 4446;
	InetAddress add;
	
	public void connect() {
		try {
			socket = new DatagramSocket(4445);
			add = InetAddress.getByName("224.0.0.1"); 
			in = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Server up and running...");
		}
		catch(Exception e) {
		
		}
	}
	
	public void readThread() {
		Thread read = new Thread() {
			public void run() {
				String received;
				try {
					while(true) {
						buff = new byte[256];
						packet = new DatagramPacket(buff, buff.length);
						socket.receive(packet);
						
						received = new String(packet.getData(), 0, packet.getLength());
						buff = new byte[256];
						buff = received.getBytes();
						packet = new DatagramPacket(buff, buff.length, add, port);
						socket.send(packet);
					}
				}
				catch(Exception e) {
					System.out.println(e);
					System.exit(0);
				}
			}
		};
		read.start();
	}
	
	public static void main(String args[]) {
		SerMulti server = new SerMulti();
		server.connect();
		
		server.readThread();
	}
}

