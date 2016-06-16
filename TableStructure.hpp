#ifndef table_hpp
#define table_hpp

#include <vector>
#include <string>
using namespace std;

class TableStructure {
	private: 
		string tableName;
		vector<string> fieldName;
		vector<string> fieldType;
		vector<string> specialSettings;
	
	public:
  	TableStructure(string);
		string getFieldName(int);
		string getFieldType(int);
		string getSpecialSettings(int);
		string getTableName();
		void setFieldName(string);
		void setFieldType(string);
		void setSpecialSettings(string);
		void setTableName(string);
		vector<string> getFieldName();
};
#endif
