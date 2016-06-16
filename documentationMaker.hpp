#include "TableStructure.hpp"
#include <string>
#include <fstream>
using namespace std;

class docMaker {
	private:
		string filename;
		ofstream file;
	public:
		docMaker(string);
		string getFilename();
		void setFilename(string);
		void makeDocumentation(vector<string>,vector<TableStructure>);
};
