#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;


int  Copy(      int &BlockSize,
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

  char SrcFilePath[150],DestFileName[150];
  // Accept the Source file path

  cin>>SrcFilePath;

  // Accept the Destinition File Name

  cin>>DestFileName;

  // Find the size of Source File 
  FILE *fp=fopen(SrcFilePath,"r");                        // Open the file 
  if(!fp)
  {
    cout<<"PLease Enter correct path"<<endl;
return 0;
  }
  fseek(fp,0,SEEK_END);                                   // point the File Pointer at Last
 

  int RequiredNumberOfBlocks;                             // Find the Reqired Number Of Blocks
  
  RequiredNumberOfBlocks=ceil((float)ftell(fp)/(float)BlockSize);
 
 

  int Temp2=ftell(fp)%BlockSize;                                  
  fclose(fp);                                                   // close the Source file pointer  

  int InodeOfFile=FileNameToInodeMap[DestFileName];             // find inode number of destinition file

  vector <int> ::iterator  InodeArrayIterator=find(InodeArray.begin(),InodeArray.end(),InodeOfFile);

  if(InodeArrayIterator!=InodeArray.end())                      // check wheather such file exist or not
  {
                                                                // Store the required number of blocks
      StartOfBlockAndNumOfBlocksForFile[*InodeArrayIterator].second=RequiredNumberOfBlocks;
    
     
      StartOfBlockAndNumOfBlocksForFile[*InodeArrayIterator].first=StartOfFreeBlockNumber;

      // This is the Actual File System
      fstream s("TextFs");                            // use option std::ios_base::binary if necessary

                                                                // Point to Start 
      s.seekp(DataOffset+(StartOfFreeBlockNumber*BlockSize), std::ios_base::beg);
    
      char buffer[BlockSize];                                   // Buffer To Read and Write                 
      fp=fopen(SrcFilePath,"r");                                // Source file Pointer
      fseek(fp,0,SEEK_SET);                                     // Point it to Start
      int i=0;
      while(i<RequiredNumberOfBlocks)
      { 
          i++;
          memset(buffer,'\0',BlockSize);
          fread(buffer, BlockSize, 1, fp);
          s.write(buffer,BlockSize);
      }
      s.close();
                                                                // Update the Start  
      StartOfFreeBlockNumber+=RequiredNumberOfBlocks;
      fclose(fp);                                               // Close file ptr
  } 
  else
    cout<<"File Does Not Exist"<<endl;
 
  return 1;
}