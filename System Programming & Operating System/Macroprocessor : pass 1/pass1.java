import java.io.*;
import java.util.*;

public class pass1 {
	
	static ArrayList<MNT> mnt;
	static ArrayList<MDT> mdt;
	
	public static int inALA(String s, ArrayList<ALA> ala) {
		for(int i=0; i<ala.size(); i++) {
			if(ala.get(i).argname.equals(s))
				return i;
		}
		return -1;
	}
	
	
	public static void main(String args[])throws Exception {
		mnt = new ArrayList<MNT>();
		mdt = new ArrayList<MDT>();
		
		Scanner input = new Scanner(new FileInputStream("input.asm"));
		BufferedWriter intcode = new BufferedWriter(new FileWriter("intcode.asm"));
		
		
		int mntp = 0;
		int mdtp = 0;
		
		while(input.hasNext()) {
			String line = input.nextLine();
			if(line.equals("MACRO")) {
				line = input.nextLine();
				String words[] = line.split("( |\t)+");
				
				ArrayList<ALA> ala = new ArrayList<ALA>();
				String arg[] = words[1].split(",");
				for(int i=0; i<arg.length; i++) {
					if(arg[i].contains("=")) {
						int pos = arg[i].indexOf('=');
						ala.add(new ALA(arg[i].substring(0,pos), arg[i].substring(pos+1)));
					}
					else {
						ala.add(new ALA(arg[i], ""));
					}
				}
				
				mnt.add(new MNT(mntp, words[0], mdtp, ala));
				int lmdtp = mdtp;
				String md = "";
				while(true) {
					line = input.nextLine();
					if(line.equals("MEND")) {
						md += "MEND" + "\n";
						break;
					}
					else {
						line.trim();
						String token[] = line.split("( |\t|,)+");
						for(int i=0; i<token.length; i++) {
							if(token[i].charAt(0) == '&') {
								int pos = inALA(token[i], ala);
								md += "#"+pos +" ";
							}
							else {
								md += token[i] + " ";
							}
						}
						md += "\n";
					}
					mdtp++;
				}
				mdt.add(new MDT(lmdtp, md));				
			}
			else {
				intcode.write(line + "\n");
			}
		}
		input.close();
		intcode.close();
		
		System.out.println("\tMacro Name Table");
		for(int i=0; i<mnt.size(); i++) {
			System.out.print(mnt.get(i).mntp + " " + mnt.get(i).mname + " " + mnt.get(i).mdtp);
			for(ALA obj : mnt.get(i).ala) {
				System.out.print("[ " + obj.argname + ":" + obj.argval + " ]");
			}
			System.out.println();
		}
		
		System.out.println("\tMacro Definition Table");
		for(int i=0; i<mdt.size(); i++) {
			System.out.println(mdt.get(i).mdtp);
			System.out.println(mdt.get(i).md);
		}
		
	}
}
