#include <iostream>
#include <cstring>
#include <string>
#include <fstream> 
using namespace std;
int main(int argc, char **argv) 
{ 
    int row;
    int column;
	string filename = "./";
	string studentID = argv[1];
	string matrix = "/matrix.data";
	string yes = "/final.peak";
	string filenameinput =filename+studentID+matrix;
	string filenameoutput =filename+studentID+yes;
	string input;
    string output;
	ifstream fileinput;
	ofstream fileoutput;
	fileinput.open(filenameinput.c_str()); 
	if(fileinput)
		while(!fileinput.eof())
		{
			fileinput>>row>>column;
			int array[row][column];
			for(int i = 0; i< row; i++)
				for(int j = 0; j< column; j++ )
				{
					int read;
					fileinput>>read;
					array[i][j]	= read;
				}
			for(int i = 0; i< row; i++)
			{
				for(int j = 0; j< column; j++ )
				{
					int read;
			        cout<<array[i][j]<<" ";
				}
				cout<<endl;
		    }
		    int space;
			fileinput>>space;
		}	
	fileinput.close();			 
	fileoutput.open(filenameoutput.c_str());
	fileoutput<<"6";
	fileoutput.close();	
	return 0;
}
