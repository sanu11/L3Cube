#include <bits/stdc++.h>

using namespace std;


int List(   int &BlockSize,
  			int &NumberOfFreeBlock,	
  			int &StartOfFreeBlockNumber, 	
  			int &DataOffset,	
  			vector <int> & InodeArray,
  			vector <int> & StartArrayOfFile ,
  			map <int , pair<int,int > > & StartOfBlockAndNumOfBlocksForFile,
  			map < string , int > & FileNameToInodeMap,
  			map < int , string > & InodeToFileNameMap
  		)
{

//	cout<<"Total Number Of files are "<<InodeArray.size()<<endl;

	vector <int> ::iterator  InodeArrayIterator=InodeArray.begin();
	

if(InodeArray.size()==0)
  cout<<"No Files Found. PLease Create one"<<endl;
//	cout<<"File Name\t\tInode"<<endl;
	                                                           // Display The list
else
  for(;InodeArrayIterator!=InodeArray.end();InodeArrayIterator++)
	cout<<InodeToFileNameMap[*InodeArrayIterator]<<"\t\t\t"<<*InodeArrayIterator<<endl;


	return 1;
}