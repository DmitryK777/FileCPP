#include<iostream>
#include<fstream>

//#define WRITE_TO_FILE
#define READ_TO_FILE

//using namespace std;
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");

#if defined WRITE_TO_FILE
	cout << "Hello world" << endl;

	std::ofstream fout; 
	fout.open("File.txt", std::ios_base::app);
	fout << "Hello world" << endl;
	fout.close();

	system("notepad File.txt");
#endif

	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//TODO: read from file
		while (!fin.eof())
		{
			const int SIZE = 256;
			char sz_buffer[SIZE]{};
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "File not found" << endl;
	}
}