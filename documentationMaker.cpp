#include "documentationMaker.hpp"

docMaker::docMaker(string s) {
	this->setFilename(s);
}

string docMaker::getFilename() {
	return this->filename;
}

void docMaker::setFilename(string s) {
	this->filename = s+",xml";
}

void docMaker::makeDocumentation(vector<string> tN, vector<TableStructure> tL) {
	this->file.open(this->getFilename(),ios::out);
	if(this->file.is_open()) {
		this->file<<"Ilosc tabel w bazie danych: "<<tN.size()<<endl<<endl;
		for(int i=0; i<tN.size(); i++) {
			this->file<<"<TABELA>\n";
			this->file<<"\t<NAZWA_TABELI>"<<tN[i]<<"</NAZWA_TABELI>\n";
			for(int j=0; j<tL[i].getFieldName().size(); j++){
				this->file<<"\t<POLE>\n";
				this->file<<"\t\t<NAZWA_POLA>"<<tL[i].getFieldName(j)<<"</NAZWA_POLA>\n";
				this->file<<"\t\t<TYP_DANYCH>"<<tL[i].getFieldType(j)<<"</TYP_DANYCH>\n";
				this->file<<"\t\t<OPCJE_SPECJALNE>"<<tL[i].getSpecialSettings(j)<<"</OPCJE_SPECJALNE>\n";
				this->file<<"\t</POLE>\n";
			}
			this->file<<"</TABELA>\n";
		}
	}
}
