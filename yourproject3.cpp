#include <iostream>
#include <cstring>
#include <string>
#include <fstream> 
using namespace std;
int main(int argc, char **argv) 
{
    int row;
    int column;
    int ans = 0;
    string filename = "./";
	string studentID = argv[1];
	string matrix = "/matrix.data";
	string final = "/final.peak";
	string filenameinput =filename+studentID+matrix;
	string filenameoutput =filename+studentID+final;
	ifstream fileinput;
	ofstream fileoutput;
	fileinput.open(filenameinput.c_str()); 
	if(fileinput)
	{
		fileinput>>row>>column;
		int array[row][column];
		int b =2*row*column;
		int a[b];
		while(!fileinput.eof())
		{		
			for(int i = 0; i< row; i++)
				for(int j = 0; j< column; j++ )
				{
					int read;
					fileinput>>read;
					array[i][j]	= read;
				}
		    int space;
			fileinput>>space;
		}
		fileinput.close();			 
		fileoutput.open(filenameoutput.c_str());
		int count = 0;
		for(int i = 0; i<row; i++)
			for(int j = 0; j<column; j++)
			{
				if(j==column-1||array[i][j]>=array[i][j+1])
					if(j==0||array[i][j]>=array[i][j-1])
						if(i==row-1||array[i][j]>=array[i+1][j])
							if(i==0||array[i][j]>=array[i-1][j])
							{
								count++;
								a[ans++] = i;
								a[ans++] = j;  
							}
			}	
		if(count)
			fileoutput<<count<<endl;
		else
			fileoutput<<0<<endl;
		for(int i = 0; i < ans; i++ )
		{
			fileoutput<<a[i]+1<<" ";
			if(i % 2 == 1)
			{
				fileoutput<<endl;
			}
		}			
		fileoutput.close();		
	}
	return 0;
}
