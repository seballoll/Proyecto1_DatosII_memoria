#include "cards.h"
using namespace std;

Cards::Cards() {
	
	string id;
	string file;
	
}

void Cards::read_image() {
	fstream fs;
	cout << "\n\t file="<< Cards::getFile() << endl;
	fs.open(Cards::getFile());//, fs.binary
	cout << fs.is_open()<<endl;
	filebuf* inbuf= fs.rdbuf();
	char c = inbuf->sbumpc();
	char char_out[1000];
	int i = 0;
	cout << c<<endl;
	while (c != EOF)
	{
		cout << i;
		char_out[i] = c;
		i++;
		c = inbuf->sbumpc();
	}
	cout << "\n\t a " << char_out << endl;
}
string Cards::getId() {
	return Cards::id;
}
void Cards::setFile(string newFile) {
	//cout << newFile;
	Cards::file = newFile;
}
string Cards::getFile() {
	return Cards::file;
}
void Cards::setId(string Id) {
	Cards::id = Id;
}

