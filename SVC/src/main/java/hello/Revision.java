package hello;
import java.io.Serializable;

class Revision implements Serializable{
	public enum OPERATIONS{
		ADD,DELETE;
	}
	OPERATIONS ops;
	String str;
	int index;
	public  Revision(OPERATIONS name,String str,int index) {
		// TODO Auto-generated constructor stub
		ops=name;
		this.str=str;
		this.index=index;
	}
}
