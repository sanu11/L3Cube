/*
		File System Name :  TextFs
		Author : Code_overflow

		First 1024 Bytes to Store Meta Data of file system 	i.e SuperBlock
		Rest of all will have actual data 					i.e DataBlock
		DataBlock id Divided into N number of Blocks each of it having size of 512 Bytes		
*/
#include <bits/stdc++.h>
using namespace std;
#define MIN 			0
#define BLOCKSIZE 		512
#define MetaDataBlocks  1024

// Global Memory
  int BlockSize 					= 		BLOCKSIZE;
  int NumberOfFreeBlock				=		MIN;
  int StartOfFreeBlockNumber 		= 		MIN;
  int DataOffset 					= 		MetaDataBlocks;
  int LastInodeNumber				=		0;
  
  vector <int> InodeArray;
  vector <int> StartArrayOfFile; 
  map <int , pair<int,int > >  StartOfBlockAndNumOfBlocksForFile;

  map < string , int > FileNameToInodeMap;
  map < int , string > InodeToFileNameMap;
  
