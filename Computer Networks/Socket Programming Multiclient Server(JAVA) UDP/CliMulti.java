import java.net.*;
import java.io.*;

class CliMulti {
	MulticastSocket socket;
	DatagramSocket socketData;
	DatagramPacket packet;
	BufferedReader in;
	
	InetAddress addBroad,addDirect;
	int port = 4445;
	String name;
	byte[] buff;
	
	public void connect() {
		try {
			socket = new MulticastSocket(4446);
			addBroad = InetAddress.getByName("224.0.0.1");
			socket.joinGroup(addBroad);
			System.out.println("Client connected to multicast socket.");
			socketData = new DatagramSocket();
			addDirect = InetAddress.getByName("127.0.0.1");
			in = new BufferedReader(new InputStreamReader(System.in));
		
			System.out.print("Enter your screen name : ");
			name = in.readLine();
			String msg = name + " joined chat !";
			buff = new byte[256];
			buff = msg.getBytes();
			packet = new DatagramPacket(buff, buff.length, addDirect, port);
			socketData.send(packet);
		}
		catch(Exception e) {
			
		}
		
	}
	
	public void writeThread() {
		Thread write = new Thread() {
			public void run() {
				String sent;
				try{
					while(true) {
						sent = in.readLine();
						sent = name + " : " + sent;
						buff = new byte[256];
						buff = sent.getBytes();
						packet = new DatagramPacket(buff, buff.length, addDirect, port);
						socketData.send(packet);
					}
				}
				catch(Exception e) {
					System.out.println(e);
					System.exit(0);
				}
			}
		};
		write.start();
	}
	
	public void readThread() {
		Thread read = new Thread() {
			public void run() {
				String received;
				try{
					while(true) {
						buff = new byte[256];
						packet = new DatagramPacket(buff, buff.length);
						socket.receive(packet);
						
						received = new String(packet.getData(), 0, packet.getLength());
						System.out.println(received);
					}
				}
				catch(Exception e) {
				
				}
			}
		};
		read.start();
	}
	
	public static void main(String args[]) {
		CliMulti client = new CliMulti();
		client.connect();
		
		client.writeThread();
		client.readThread();
	}
}
