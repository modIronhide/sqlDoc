#include "TableStructure.hpp"

TableStructure::TableStructure(string s) {
	this->setTableName(s);
	this->fieldName.clear();
	this->fieldType.clear();
	this->specialSettings.clear();
}

string TableStructure::getFieldName(int index) {
	return this->fieldName[index];
}

string TableStructure::getFieldType(int index) {
	return this->fieldType[index];
}

string TableStructure::getSpecialSettings(int index) {
	return this->specialSettings[index];
}

string TableStructure::getTableName() {
	return this->tableName;
}

void TableStructure::setFieldName(string s) {
	this->fieldName.push_back(s);
}

void TableStructure::setFieldType(string s) {
	this->fieldType.push_back(s);
}

void TableStructure::setSpecialSettings(string s) {
	this->specialSettings.push_back(s);
}

void TableStructure::setTableName(string s) {
	this->tableName = s;
}

vector<string> TableStructure::getFieldName() {
	return this->fieldName;
}
