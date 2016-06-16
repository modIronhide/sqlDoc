#include "TableStructure.hpp"
#include <stdlib.h>
#include <iostream>
#include "cmdline.h"
#include "printdata.h"
#include "mysql++.h"

//#define CPPCONN_DONT_TYPEDEF_MS_TYPES_TO_C99_TYPES 
//#include <mysql_connection.h>
//#include <mysql_driver.h>
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>


class mysqlReader {
	private:
		string serverAddress;
		string user;
		string password;
		string databaseName;
		vector<string> tablesNames;
		vector<TableStructure> tablesList;
		bool isConnected;
		
		//sql::Driver* driv;
		//sql::Connection* conn;		
		//sql::Statement* sta;
		//sql::ResultSet* res;
		mysqlpp::Connection conn;
		mysqlpp::Query query;
		mysqlpp::StoreQueryResult res;
		
	
	public:
		mysqlReader(string,string,string,string);
		bool connect();
		void makeQuery(string);
		void saveTableData();
		string getServerAddress();
		string getUser();
		string getPassword();
		string getDatabaseName();
		void setServerAddress(string);
		void setUser(string);
		void setPassword(string);
		void setDatabaseName(string);
		vector<string> getTablesNames();
		vector<TableStructure> getTablesList();
		string getTableName(int);
		TableStructure getTable(int);
};
