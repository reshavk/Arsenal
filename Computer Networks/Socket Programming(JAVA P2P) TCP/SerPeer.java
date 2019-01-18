import java.io.*;
import java.net.*;

class SerPeer {
	public static int portnumber;
	Socket socket;
	ServerSocket serverSocket;
	BufferedReader in, stdin;
	PrintWriter out;
	
	public SerPeer() {};
	
	public void connect() {
		try {
			serverSocket = new ServerSocket(portnumber);
			System.out.println("Server up and running...");
			socket = serverSocket.accept();
			System.out.println("Client connected to server...");
		
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
						System.out.println("Client : " + data );
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
		portnumber = 8000;
		SerPeer server = new SerPeer();
		
		server.connect();
		
		server.readThread();
		server.writeThread();
	}
}
	
	
	
	
