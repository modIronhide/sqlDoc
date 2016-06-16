#include "databaseReader.hpp"
mysqlReader::mysqlReader(string d, string s, string u, string p) {
	this->setServerAddress(s);
	this->setUser(u);
	this->setPassword(p);
	this->setDatabaseName(d);
	this->tablesNames.clear();
	this->tablesList.clear();
	conn(false);
	this->isConnected = false;
}
bool mysqlReader::connect(){
	//this->driv = get_driver_instance();
	if(conn.connect(this->getDatabaseName(),this->getServerAddress(),this->getUser(), this->getPassword())){
			this->isConnected = true;
		return true;
	}
	return false;	
}
void mysqlReader::makeQuery(string s){
	if(this->isConnected){
		this->query = this->conn.query(s);
		this->res = this->query.store();
	}
}
void mysqlReader::saveTableData() {
	this->makeQuery("show tables");
	string dbName="";
	dbName.append("Tables_in_");
	dbName.append(this->getDatabaseName());
	if(this->res){
		for(size_t) i=0; i<this->res.num_rows(); i++){
			this->tablesNames.push_back(res[i][dbName]);
		}
	}
	string tblName="";
	for(int j=0; j<this->tablesNames.size(); j++){
		tblName.append("desc ");
		tblName.append(this->tablesNames[j]);
		this->makeQuery(tblName);
		if(this->res){
			for(size_t) i=0; i<this->res.num_rows(); i++){
				TableStructure tabTmp("","","","");
				tabTmp.setTableName(tblName);
				tabTmp.setFieldName(this->res[i]["Field"]);
				tabTmp.setFieldType(this->res[i]["Type"]);
				string setTmp = "";
				setTmp.append(this->res[i]["Null"]);
				setTmp.append(" ");
				setTmp.append(this->res[i]["Key"]);
				setTmp.append(" ");
				setTmp.append(this->res[i]["Default"]);
				setTmp.append(" ");
				setTmp.append(this->res[i]["Extra"]);
				tabTmp.setSpecialSettings(setTmp);
			}
			this->tablesList.push_back(tabTmp);
		}
	}
}
string mysqlReader::getServerAddress() {
	return this->serverAddress;
}
string mysqlReader::getUser() {
	return this->user;
}
string mysqlReader::getPassword(){
	return this->password;
}
string mysqlReader::getDatabaseName(){
	return this->databaseName;
}
void mysqlReader::setServerAddress(string s){
	this->serverAddress = s;
}
void mysqlReader::setUser(string s){
	this->user = s;
}
void mysqlReader::setPassword(string s){
	this->password = s;
}
void mysqlReader::setDatabaseName(string s){
	this->databaseName = s;
}
vector<string> mysqlReader::getTablesNames(){
	return this->tablesNames;
}
vector<TableStructure> mysqlReader::getTablesList(){
	return this->tablesList;
}
string mysqlReader::getTableName(int index){
	return this->getTablesNames()[index];
}
TableStructure mysqlReader::getTable(int index){
	return this->getTablesList()[index];
}
