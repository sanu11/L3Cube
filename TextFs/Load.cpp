#include <bits/stdc++.h>
#include <string>  
using namespace std;
int Load (    	int &BlockSize,
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
    char Path[50];
    strcpy(Path,"./TextFs");
    ifstream FILE(Path);
 
    //load inode array size and inode number
    string InodeArraySize,InodeNumber,StartOfFreeBlock;
    FILE>>InodeArraySize>>InodeNumber>>StartOfFreeBlock;
 
    int inode=stoi(InodeNumber);
    NewInodeNumber=inode;
    int len= stoi(InodeArraySize);
    string x,y,z;
   
    //load start of free block number
    StartOfFreeBlockNumber=stoi(StartOfFreeBlock);
   
    //load inode array
    for(int i=0;i<len;i++)
    {
      FILE>>x;
      InodeArray.push_back(stoi(x));
    }

    //load blocks array
    for(int i=0;i<len;i++)
    {
      FILE>>x;
      FILE>>y;
      FILE>>z;
      StartOfBlockAndNumOfBlocksForFile.insert(make_pair(stoi(x),make_pair(stoi(y),stoi(z))));
    }
    
    // load inode to file map
    for(int i=0;i<len;i++)
    {
      FILE>>x;
      FILE>>y;
     
      InodeToFileNameMap.insert(make_pair(stoi(x),y));
    }

    //load file to inode map
    for(int i=0;i<len;i++)
    {
      FILE>>x;
      FILE>>y;
      FileNameToInodeMap.insert(make_pair(x,stoi(y)));
    }

    return 1;
    }