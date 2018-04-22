import java.util.ArrayList;

class MNT {
	String mname;
	int mntp, mdtp;
	ArrayList<ALA> ala;
	
	MNT(int mntp, String mname, int mdtp, ArrayList<ALA> ala) {
		this.ala = new ArrayList<ALA>();
		this.mntp = mntp;
		this.mdtp = mdtp;
		this.mname = mname;
		for(int i=0; i<ala.size(); i++) {
			this.ala.add(ala.get(i));
		}
	}
	
}

class MDT {
	int mdtp;
	String md;
	
	MDT(int mdtp, String md) {
		this.mdtp = mdtp;
		this.md = md;
	}
}

class ALA {
	String argname, argval;
	
	ALA(String argname, String argval) {
		this.argname = argname;
		this.argval = argval;
	}
}