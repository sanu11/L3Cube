#include <bits/stdc++.h>
#include "GlobalMem.h"

#include "Create.cpp"
#include "List.cpp"
#include "Delete.cpp"
#include "Copy.cpp"
#include "Echo.cpp"
#include "Load.cpp"
#include "Store.cpp"

using namespace std;
int main()
{
	int choice;
		//load metadata
	if(	!Load(	    BlockSize, 
					NumberOfFreeBlock,
					StartOfFreeBlockNumber,  
					DataOffset,  
					LastInodeNumber,
					InodeArray,
			   	    StartArrayOfFile,
			   	 	StartOfBlockAndNumOfBlocksForFile,
			    	FileNameToInodeMap,
			    	InodeToFileNameMap
				)		
   		);
	while(true)
	{

		char s[50];	
		cin>>s;

		if(!strcmp(s,"create"))
			choice=1;
		else if(!strcmp(s,"copy"))
			choice=2;
		else if(!strcmp(s,"echo"))
			choice=3;
		else if(!strcmp(s,"ls"))
			choice=4;
		else if(!strcmp(s,"delete"))
			choice=5;
		else if(!strcmp(s,"exit"))
			choice=6; 
		else
			choice=7;
		switch(choice)
		{
			case 1:
			{
				if(	!Create(    BlockSize, 
								NumberOfFreeBlock,
								StartOfFreeBlockNumber,  
								DataOffset,  
								LastInodeNumber,
								InodeArray,
   						   	    StartArrayOfFile,
   						   	 	StartOfBlockAndNumOfBlocksForFile,
   						    	FileNameToInodeMap,
   						    	InodeToFileNameMap
   							)		
   					)
   					cout<<"Error in Creating the File"<<endl;

				break;
			}
			case 2:	
			{
				if(	!Copy(      BlockSize, 
								NumberOfFreeBlock,
								StartOfFreeBlockNumber,  
								DataOffset,  
								LastInodeNumber,
								InodeArray,
   						   	    StartArrayOfFile,
   						   	 	StartOfBlockAndNumOfBlocksForFile,
   						    	FileNameToInodeMap,
   						    	InodeToFileNameMap
   							)		
   					)
   	 				cout<<"Error in Copying the File"<<endl;
				break;
			}
			case 3:
			{
				if(	!Echo(      BlockSize, 
								NumberOfFreeBlock,
								StartOfFreeBlockNumber,  
								DataOffset,  
								LastInodeNumber,
								InodeArray,
   						   	    StartArrayOfFile,
   						   	 	StartOfBlockAndNumOfBlocksForFile,
   						    	FileNameToInodeMap,
   						    	InodeToFileNameMap
   							)		
   					)
   					cout<<"Error in Displaying the File"<<endl;
				break;
			}
			case 4:
			{
				if (!List  (   	BlockSize, 
								NumberOfFreeBlock,
								StartOfFreeBlockNumber,  
								DataOffset,  
								InodeArray,
   						   	    StartArrayOfFile,
   						   	 	StartOfBlockAndNumOfBlocksForFile,
   						    	FileNameToInodeMap,
   						    	InodeToFileNameMap
   							)		
   					)
   					cout<<"Error in Listing the File"<<endl;

				break;
			}
			case 5:
			{
				if (!Delete (   BlockSize, 
								NumberOfFreeBlock,
								StartOfFreeBlockNumber,  
								DataOffset,  
								InodeArray,
   						   	    StartArrayOfFile,
   						   	 	StartOfBlockAndNumOfBlocksForFile,
   						    	FileNameToInodeMap,
   						    	InodeToFileNameMap
   							)		
   					)
   					cout<<"Error in Deleting the File"<<endl;
				break;
			}
			case 6:
			{
							if(Store (   	BlockSize, 
								NumberOfFreeBlock,
								StartOfFreeBlockNumber,  
								DataOffset,  
							LastInodeNumber,
								InodeArray,
   						   	    StartArrayOfFile,
   						   	 	StartOfBlockAndNumOfBlocksForFile,
   						    	FileNameToInodeMap,
   						    	InodeToFileNameMap
   							)		
   					);
				return 0;
			}
			default:
			{
				cout<<"Wrong Choice"<<endl;
			}
		}

	}
	return 0;
}