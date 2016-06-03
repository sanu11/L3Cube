#include <bits/stdc++.h>

using namespace std;


int  Echo(      int &BlockSize,
  		    	    int &NumberOfFreeBlock,	
  			       	int &StartOfFreeBlockNumber, 	
  				      int &DataOffset,	
  				      int &NewInodeNumber,
  			  	    vector <int> & InodeArray,
  			  	    vector <int> & StartArrayOfFile ,
  				      map <int , pair<int,int > > & StartOfBlockAndNumOfBlocksForFile,
  				      map < string , int > & FileNameToInodeMap,
  				      map < int , string > & InodeToFileNameMap
  			   )
{

  // Accept the File Name
  char FileName[100];
 // cout<<"Enter the File Name"<<endl;
  cin>>FileName;

  int InodeOfFile=FileNameToInodeMap[FileName];             // find inode number of destinition file

  vector <int> ::iterator  InodeArrayIterator=find(InodeArray.begin(),InodeArray.end(),InodeOfFile);

  if(InodeArrayIterator!=InodeArray.end())                      // check wheather such file exist or not
  {

                                                                //  Get the start block and number of 
                                                                //  Blocks required     
      int NumberOfBlocks=StartOfBlockAndNumOfBlocksForFile[*InodeArrayIterator].second;
      int StartBlockNumber=StartOfBlockAndNumOfBlocksForFile[*InodeArrayIterator].first;

      fstream s("TextFs");                                      // use option std::ios_base::binary if necessary
                                                                // Point to the Location of File
      s.seekp(DataOffset+(StartBlockNumber*BlockSize), std::ios_base::beg);
      char buffer[BlockSize]; 
     
      while(NumberOfBlocks--)
      {
        memset(buffer,'\0',BlockSize);
        s.read(buffer,BlockSize);                               // Read File 
        cout<<buffer;                                           // Display Contet
      }
      s.close();
      cout<<endl;
  }
  else
  {
    cout<<"File Not Found"<<endl;
  }
  return 1;
}