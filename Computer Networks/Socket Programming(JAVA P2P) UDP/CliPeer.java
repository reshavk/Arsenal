import java.net.*;
import java.io.*;

class CliPeer {
	DatagramSocket socket;
	DatagramPacket packet;
	BufferedReader in;
	InetAddress add;
	int port;
	
	byte[] buff;
	
	public void connect() {
		try {
			socket = new DatagramSocket();
			in = new BufferedReader(new InputStreamReader(System.in));
			add = InetAddress.getByName("127.0.0.1");
			port = 5000;
		
			buff = new byte[256];
			packet = new DatagramPacket(buff, buff.length, add, port);
			socket.send(packet);
			System.out.println("Connected to server.");
		}
		catch(Exception e) {
			System.out.println(e);
			System.exit(0);
		}
	}
	
	public void readThread() {
		Thread read = new Thread() {
			public void run() {
				String received;
				byte buffer[];
				DatagramPacket pack;
				try {
					while(true) {
						buffer = new byte[256];
						pack = new DatagramPacket(buffer, buffer.length);
						socket.receive(pack);
						
						received = new String(pack.getData(), 0, pack.getLength());
						System.out.println("Server : " + received );
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
	
	public void writeThread() {
		Thread write = new Thread() {
			public void run() {
				String sent;
				byte[] buffer;
				DatagramPacket pack;
				try {
					while(true) {
						sent = in.readLine();
						buffer = new byte[256];
						buffer = sent.getBytes();
						pack = new DatagramPacket(buffer, buffer.length, add, port);
						socket.send(pack);
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
	
	public static void main(String args[]) {
		CliPeer client = new CliPeer();
		client.connect();
		
		client.writeThread();
		client.readThread();
	}
}
