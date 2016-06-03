package hello;
import java.io.Serializable;

class RevisionList implements Serializable{
	int current_rev;
	Revision revision[]=new Revision[100]; 
	
}
