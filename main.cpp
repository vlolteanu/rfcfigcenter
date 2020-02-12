#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "rfcfigcenter <string>" << endl;
		return EXIT_FAILURE;
	}
	
	string line(argv[1]);
	vector<string> cells;
	split(cells, line, is_any_of("|"));
	
	cout << "|";
	for (const string &cell: cells)
	{
		if (cell.length() == 0)
			continue;
		
		size_t first = cell.find_first_not_of(' ');
		size_t last  = cell.find_last_not_of(' ');
		string text  = cell.substr(first, (last - first + 1));
		
		size_t leftSpaces  = (cell.length() - text.length()) / 2;
		size_t rightSpaces = cell.length() - text.length() - leftSpaces;
		
		cout << string(leftSpaces, ' ') << text << string(rightSpaces, ' ') << "|";
	}
	cout << endl;
	
	return 0;
}
