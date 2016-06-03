#include <bits/stdc++.h>

using namespace std;


int Delete( int &BlockSize,
  			int &NumberOfFreeBlock,	
  			int &LastUsedBlockNumber, 	
  			int &DataOffset,	
  			vector <int> & InodeArray,
  			vector <int> & StartArrayOfFile ,
  			map <int , pair<int,int > > & StartOfBlockAndNumOfBlocksForFile,
  			map < string , int > & FileNameToInodeMap,
  			map < int , string > & InodeToFileNameMap
  		)
{
		string FileNameTobeDeleted;
		cin>>FileNameTobeDeleted;
    	map < string , int >::iterator p;
    	map < int , string >::iterator q;
    	map <int , pair<int,int > >::iterator s;
    	vector<int> ::iterator r;

    	p=FileNameToInodeMap.find(FileNameTobeDeleted);
    	int inode;
    	if(p!=FileNameToInodeMap.end())
    	{
    		inode=p->second;
    		
    		// //remove from file to inode
    		
    		FileNameToInodeMap.erase(p);
    	

			//find in inode to file and remove
			q=InodeToFileNameMap.find(inode);
			
			InodeToFileNameMap.erase(q);
			

			//find in inode array and remove
			r=find(InodeArray.begin(),InodeArray.end(),inode);
			
			InodeArray.erase(r);
		

			//find inode in blocks array and remove 
			s=StartOfBlockAndNumOfBlocksForFile.find(inode);
			if(s!=StartOfBlockAndNumOfBlocksForFile.end())
				StartOfBlockAndNumOfBlocksForFile.erase(s);
		}
		else
		{
			cout<<"File not found"<<endl;
		}
 	return 1;
}