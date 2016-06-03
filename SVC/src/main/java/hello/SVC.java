package hello;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;


public class SVC {
	private static int source_len=0;
	private static int recent_len=0;
	private static String SOURCE_FILE;
	private static String RECENT_FILE="/home/sumit/svc/recent.txt";
	private static String REVISION="/home/sumit/svc/.version/rev.ser";
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Scanner sc=null;
		 sc=new Scanner(System.in);
		String string=args[0];
	    try
	    {
			int N=Integer.valueOf(string);
			revertBack(N);
	    }
	    catch(Exception e){
	    SOURCE_FILE=string;
		File source=new File(SOURCE_FILE);
		File recent=null;
		if(!new File(RECENT_FILE).exists())
		{	
			File file=new File(REVISION);
			RevisionList list=new RevisionList();
			FileOutputStream stream3=new FileOutputStream(REVISION);
		    ObjectOutputStream stream4=new ObjectOutputStream(stream3);
		    stream4.writeObject(list);
			recent=new File(RECENT_FILE);
			copyWhole(source, recent);
			System.out.println("Commit 0 successful.");
		}
		else{
		BufferedReader reader=new BufferedReader(new FileReader(source));
		recent=new File(RECENT_FILE);
		while(reader.readLine()!=null)
			source_len++;
	    reader=new BufferedReader(new FileReader(recent));
	    while(reader.readLine()!=null)
	    	recent_len++;
	    int differ=source_len-recent_len;
	    switch(differ)
	    {
	    case 1:
	    	 addAtLast(source, recent,null);
	    	break;
	    case -1:
	    		deleteInMiddle(source, recent);
	    		break;
	    default:
	    	deleteInMiddle(source, recent);
	    }	
	    }

		}
	}	
	public  static  void copyWhole(File source,File recent) throws IOException
	{
		FileReader reader=new FileReader(source);
		FileWriter writer=new FileWriter(recent);
		int k=0;
		while(( k=reader.read())!=-1)
		{
			writer.write(k);
		}
		writer.close();
		reader.close();
	}
	public static void  deleteInMiddle(File source,File recent) throws IOException, ClassNotFoundException
	{
		int j=1;
		int i=1;
		int index=recent_len;
		String str=null;
		String str2=null;
		BufferedReader reader=new BufferedReader(new FileReader(source));
		BufferedReader reader2=new BufferedReader(new FileReader(recent));
		while(j<=recent_len && i<=source_len)
		{
			str=reader2.readLine();
			str2=reader.readLine();
			if(!(str2.equals(str)))
			{
				index=j;
				break;
			}
			j++;
			i++;
		}
		copyWhole(source, recent);
		if(index==recent_len)
			str=reader2.readLine();
		Revision revision=new Revision(Revision.OPERATIONS.DELETE, str, index);
		revise(revision);
		System.out.println("Deleted "+"line number "+index);
		reader.close();
		reader2.close();
	}
	public static void revertBack(int N) throws ClassNotFoundException, IOException
	{
		FileInputStream stream=new FileInputStream(REVISION);
	    ObjectInputStream stream2=new ObjectInputStream(stream);
	    RevisionList list=(RevisionList)stream2.readObject();
	    int current=list.current_rev;
	    if( N>current)
	    	System.out.println("Invalid version number");
	    else
	    {
	    	Scanner sc = new Scanner(new File(RECENT_FILE));
			sc.useDelimiter("\n");
			List<String> lines = new ArrayList<String>();
			while (sc.hasNextLine()) {
			  lines.add(sc.nextLine());
			}
			Revision revision=null;
	    	for(int i=current;i>N;i--)
	    	{
	    		revision=list.revision[i];
	    		if(revision.ops==Revision.OPERATIONS.ADD)
	    		{
	    			lines.remove(revision.index-1);
	    		}
	    		else
	    		{
	    			lines.add(revision.index-1, revision.str);
	    		}
	    	}
	    	for(String str1:lines)
	    		System.out.print(str1+"\n");
	    		
	    }
	}
	public static void addAtLast(File source,File recent,File diff) throws IOException, ClassNotFoundException
	{
		Scanner sc = new Scanner(source);
		sc.useDelimiter("\n");
		List<String> lines = new ArrayList<String>();
		while (sc.hasNextLine()) {
		  lines.add(sc.nextLine());
		}
	    String str=lines.get(source_len-1);
	    copyWhole(source, recent);
	    Revision revision=new Revision(Revision.OPERATIONS.ADD, str, source_len);
	    revise(revision);
	    System.out.println("Added- " +str);
	}
	public static void revise(Revision revision) throws IOException, ClassNotFoundException
	{
		  	FileInputStream stream=new FileInputStream(REVISION);
		    ObjectInputStream stream2=new ObjectInputStream(stream);
		    RevisionList list=(RevisionList)stream2.readObject();
		    int current=list.current_rev;
		    list.revision[current+1]=revision;
		    list.current_rev++;
		    FileOutputStream stream3=new FileOutputStream(REVISION);
		    ObjectOutputStream stream4=new ObjectOutputStream(stream3);
		    stream4.writeObject(list);
		    System.out.println("Commit "+ (current+1)+" Successful.");
		    stream.close();
		    stream2.close();
		    stream3.close();
		    stream4.close();
	}
}
