#include <bits/stdc++.h>
#include <dirent.h>
#include <fstream>
#include "md5.h"
using namespace std;
map <string,int> PathToIdMap;	// FilePath and FileId Mapping
map <int,string> IdToPathMap;	// FileId and PathId Mapping 
map <string, set<int> > Hash;
int FileId=0; 					// FileId used for Map Path of File 
int flag=0;   	

//Get content of given input file in a string
string GetHashValue(char FileName[])
{
	ifstream File(FileName);
	string Data,Temp;

	if(File.is_open())
	{
		//Iterate for every line and append it
		while(!File.eof())
		{
			getline(File,Temp);
			Data+=Temp;
		}
	}
	else
		cout<<"Error in Opening the file"<<endl;
	return md5(Data);
}
void Calculate(DIR *RootDir,char Path[])
{
	DIR *CurrDir=RootDir;
	struct dirent *curr;

	while((curr=readdir(CurrDir))!=NULL)
	{
		
		//For the files or folder other than . and  .. 
		if(strcmp(curr->d_name,".")!=0&&strcmp(curr->d_name,"..")!=0)
		{
			//Complete path in next by appending current file or folder to previous path
			char next[1000];
			strcpy(next,Path);
			strcat(next,"/");
			strcat(next,curr->d_name);
			
			//If directory
			if(curr->d_type==DT_DIR)
			{
				//point to it
				DIR *temp=opendir(next);
				//recur (DFS)
				Calculate(temp,next);
			}

			//If file
			else
			{
				//Assign file id to every file and add them to maps
				FileId++;
				PathToIdMap[next]=FileId;
				IdToPathMap[FileId]=next;
		
				//Maps Content to set of file ids (for same files) 
				Hash[GetHashValue(next)].insert(FileId);
			}
		}
	}
}
void ListDuplicateFiles()
{
	map <string,set<int> > ::iterator it1;
	set <int> ::iterator it2;

	//iterate over hash to get content of file and then iterate over its set to get set of file ids for same files
	for(it1=Hash.begin();it1!=Hash.end();it1++)
	{
		string File=it1->first;
		it2=Hash[File].begin();

		// Size > 1 Signifies Duplications of a file 
		if(Hash[File].size()>1)
		{
			flag=1;
			cout<<"Duplicates Files Found :- "<<endl;
		//	cout<<File<<endl;
			cout<<"Ids and Paths "<<endl;

			//Iterate over set of same files using file ids
			while(it2!=Hash[File].end())
			{
				cout<<*it2<<" "<<IdToPathMap[*it2]<<endl;
				it2++;
			}
		}
	}
}
void FileDelete(int fileid)
{
	string path=IdToPathMap[fileid];

	//Deletes file with given path
	remove(path.c_str());

	cout<<"File at "<<path<<" Deleted Successfully !"<<endl;
}
int main(int argc,char *argv[])
{
	//RootPath given as argument
	char RootPath[1000];
	int choice;
	
	if(argc<2)
	{
	cout<<"Please Enter path as argument while Executing"<<endl;
	return 0;
	}

	strcpy(RootPath,argv[1]);

	//Pointer to Directory
	DIR *RootDir=opendir(RootPath);

	//Calculates duplicate files
	Calculate(RootDir,RootPath);

	//List them 
	ListDuplicateFiles();

	//Delete files

	//If Duplications exist
	if(flag)
	{
		while(1)
		{
		cout<<"Enter File ID to be deleted and -1 to return"<<endl;
		cin>>choice;
		if(choice==-1)
			break;
		FileDelete(choice);	
		}
	}
	//If Duplications doesn't exist
	else
		cout<<" No Duplicates Found "<<endl;
	return 0;
}
