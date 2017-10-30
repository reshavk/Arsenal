import java.io.*;
import java.net.*;

class CliPeer {
	public static int portnumber;
	public static String hostname;
	Socket socket;
	BufferedReader in, stdin;
	PrintWriter out;
	
	public CliPeer() {};
	
	public void connect() {
		try {
			socket = new Socket(hostname, portnumber);
			System.out.println("Connection setablished with server...");
		
			in = new BufferedReader( new InputStreamReader( socket.getInputStream() ) );
			stdin = new BufferedReader( new InputStreamReader( System.in ) );
			out = new PrintWriter( socket.getOutputStream(), true );
		}
		catch( Exception e ) {
			System.out.println( e );
			System.exit(0);
		}		 
	}
	
	public void readThread() {
		Thread read = new Thread() {
			public void run () {
				String data;
				try {
					while( (data = in.readLine()) != null ) {
						System.out.println("Server : " + data );
					}
				}
				catch (Exception e) {
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
				while(true) {
					try {
						out.println( stdin.readLine() );
					}
					catch( Exception e ) {
						System.out.println(e);
						System.exit(0);
					}
				}
			}
		};
		write.start();
	}
	
	public static void main( String args[] ) {
		hostname = "localhost";
		portnumber = 8000;
		CliPeer client = new CliPeer();
		
		client.connect();

		client.writeThread();
		client.readThread();
	}
}
	
	
	
	
