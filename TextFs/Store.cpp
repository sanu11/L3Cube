#include <bits/stdc++.h>
#include<string>

using namespace std;

int Store(  int &BlockSize,
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
	fstream FILE(Path);
	string a;
	char *b;
	int len,inode;
	vector<int> ::iterator it;
	
	it=InodeArray.begin();
	map < int , string >::iterator it2;
	map < string , int > ::iterator it3;
	string file;
	int size=InodeArray.size();
	int i=0;
	while(i<size)
	{
		inode=*it;
		if(StartOfBlockAndNumOfBlocksForFile.find(inode)==StartOfBlockAndNumOfBlocksForFile.end())
		{
			size--;
			InodeArray.erase(it);
			it2=InodeToFileNameMap.find(inode);
			cout<<it2->first<<endl;
			file=it2->second;
			InodeToFileNameMap.erase(it2);
			it3=FileNameToInodeMap.find(file);
			cout<<it3->second<<endl;
			FileNameToInodeMap.erase(it3);	
		}
		i++;
		if(it!=InodeArray.end())
		it++;
	}

	//store inode array size
	a = to_string(InodeArray.size())+ " " ;	
    b=(char*)a.c_str();
    len =strlen(b);
    FILE.write(b,len);
	// cout<<InodeArray.size()<<endl;	
	//store last inode number
	a=to_string(NewInodeNumber) + " " ;
	b=(char*)a.c_str();
    len =strlen(b);
    FILE.write(b,len);
	

    //store StartOfFreeBlock
	a=to_string(StartOfFreeBlockNumber) + " " ;
	b=(char*)a.c_str();
    len =strlen(b);
    FILE.write(b,len);

    len=InodeArray.size();
	int len1;
	//store inode array
    for(int i=0;i<len;i++)
    {	
	a=to_string(InodeArray[i])+ " ";
	cout<<a<<"----"<<i<<endl;
	b=(char*)a.c_str();
    len1 =strlen(b);
    FILE.write(b,len1);
	}	

	//store start of block and number of block for a file
	map<int ,pair<int,int> >::iterator p;
	p=StartOfBlockAndNumOfBlocksForFile.begin();
	
	while(p!=StartOfBlockAndNumOfBlocksForFile.end())
	{
	
	//inode
	a=to_string(p->first)+ " ";
	b=(char*)a.c_str();
    len1 =strlen(b);
    FILE.write(b,len1);
	
	//start of block
	a=to_string(p->second.first)+ " ";
	b=(char*)a.c_str();
    len1 =strlen(b);
    FILE.write(b,len1);
	

    //number of blocks
	a=to_string(p->second.second)+ " ";
	b=(char*)a.c_str();
    len1 =strlen(b);
    FILE.write(b,len1);
	
	p++;
	
	}

	//store inode to file map
	map<int,string>::iterator q;
	q=InodeToFileNameMap.begin();
	
	while(q!=InodeToFileNameMap.end())
	{
	//inode
	a=to_string(q->first)+ " ";
	b=(char*)a.c_str();
    len1 =strlen(b);
    FILE.write(b,len1);

    //file
	a=q->second + " ";
	b=(char*)a.c_str();
    len1 =strlen(b);
    FILE.write(b,len1);
	q++;
	}


	//store file to inode map
	map<string,int> ::iterator r;
	r=FileNameToInodeMap.begin();
	while(r!=FileNameToInodeMap.end())
	{

	//file
	a=r->first + " ";
	b=(char*)a.c_str();
    len1 =strlen(b);
    FILE.write(b,len1);

    //inode
	a=to_string(r->second)+ " ";
	b=(char*)a.c_str();
    len1 =strlen(b);
    FILE.write(b,len1);
	
	r++;
	}
	return 1;
}