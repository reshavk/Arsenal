import java.util.*;
import java.io.*;

public class pass2 {
	
	static ArrayList<MNT> mnt;
	static ArrayList<MDT> mdt;
	
	public static int inmnt(String s) {
		for(int i=0; i<mnt.size(); i++) {
			if(mnt.get(i).mname.equals(s))
				return i;
		}
		return -1;
	}
	
	public static void main(String args[])throws Exception {
		mnt = new ArrayList<MNT>();
		mdt = new ArrayList<MDT>();
		
		Scanner intcode = new Scanner(new FileInputStream("intcode.asm"));
		Scanner mntfile = new Scanner(new FileInputStream("mnt.txt"));
		Scanner mdtfile = new Scanner(new FileInputStream("mdt.txt"));
		BufferedWriter output = new BufferedWriter(new FileWriter("output.asm"));
		
		while(mntfile.hasNext()) {
			int mntp = mntfile.nextInt();
			String mname = mntfile.next();
			int mdtp = mntfile.nextInt();
			ArrayList<ALA> ala = new ArrayList<ALA>();
			
			String s = mntfile.nextLine();
			String arg[] = s.split(",");
			for(int i=0; i<arg.length; i++) {
				if(arg[i].contains("=")) {
					int pos = arg[i].indexOf('=');
					ala.add(new ALA(arg[i].substring(0,pos), arg[i].substring(pos+1)));
				}
				else {
					ala.add(new ALA(arg[i], ""));
				}
			}
			
			mnt.add(new MNT(mntp, mname, mdtp, ala));
		}
		
		while(mdtfile.hasNext()) {
			int mdtp = mdtfile.nextInt();
			String mdef = "";
			String s = mdtfile.nextLine();
			while(!s.equals("MEND")) {
				mdef += s + "\n";
				s = mdtfile.nextLine();
			}
			mdt.add(new MDT(mdtp, mdef));
		}
		mntfile.close();
		mdtfile.close();
		
		while(intcode.hasNext()) {
			String line = intcode.nextLine();
			String words[] = line.split("( |\t)+");
			int pos = inmnt(words[0]);
			if(pos != -1) {
				String arg[] = words[1].split(",");
				
				
				for(int i=0; i<arg.length; i++) {
					mnt.get(pos).ala.get(i).argval = arg[i];
				}
				
				String md = mdt.get(pos).md;
				String l[] = md.split("\n");
				for(int i=0; i<l.length; i++) {
					String token[] = l[i].split("( |\t|,)+");
					for(int j=0; j<token.length; j++) {
						if(token[j].length() > 0) {
							if(token[j].charAt(0) == '#') {
								int p = Integer.parseInt(token[j].substring(1));
								output.write(mnt.get(pos).ala.get(p).argval + " ");
							}
							else {
								output.write(token[j] + " ");
							}
						}
					}
					output.write("\n");
				}
			}
			else {
				output.write(line + "\n");
			}
		}
		intcode.close();
		output.close();
	}
}
