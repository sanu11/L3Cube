#include <bits/stdc++.h>

using namespace std;


int  Create(    int &BlockSize,
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

	string FileName;
	//cout<<"Enter the file name"<<endl;	
		cin>>FileName;													// Get the Filename

	int InodeTest=FileNameToInodeMap[FileName];							// Get the Inode
																		// Verify Already Exist or Not	
	vector <int> ::iterator it=find(InodeArray.begin(),InodeArray.end(),InodeTest);
	if(it==InodeArray.end())
	{
		FileNameToInodeMap[FileName]			=	++NewInodeNumber; // FileName and its Inode number mapping
		InodeArray.push_back(NewInodeNumber);							// Update the Inode list				
		InodeToFileNameMap[NewInodeNumber]	= 	FileName;

		// deletion of any file will craete a free block 
		// if such free blocks are avilable


		if(NumberOfFreeBlock)
		{
			// if Previous blocks are Available 
			// Fragmentation 
		}

		// if no free blocks then allocate at last
		else
		{
			// StartArrayOfFile.push_back(DataOffset+((NewInodeNumber)*BlockSize));	
			//cout<<"StartOfFreeBlockNumber is updated to "<<StartOfFreeBlockNumber<<endl;
		}

		cout<<"New File "<<FileName<<" with Inode "<<NewInodeNumber<<" created "<<endl;
	}
	else
	{
		cout<<"FileName Already Exist"<<endl;
	}
	return 1;
}