#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


class Book {
private:
	int BookID;
	string Title;
	string Author;
	string Publisher;
	bool Reserved;
public:
	void outputData();
	void reserve();

	Book(int id, string t, string a, string p, bool res) {
		BookID = id;
		Title = t;
		Author = a;
		Publisher = p;
		Reserved = res;
		//constuctor - sets vars when object intailzed
	}
};


static void title(string text, bool banner) {
	string temp = text;
	int MAX = size(temp);		//sets to length of text
	cout << "=======================================================================================================================" << endl;
	cout << endl << "                                           ";
	if (banner) {
		for (int i = 0;i < MAX;i++) {
			cout << "-";
		}
	}
	cout << endl << "                                           " << text;
	cout << endl << "                                           ";
	if (banner) {
		for (int i = 0;i < MAX;i++) {
			cout << "-";
		}		//couts a '-' for the length of the string on the bottom and top
	}			//all titles are passed with a boolean value if they want a banner over the text or not
	cout << endl << endl;
	cout << "=======================================================================================================================" << endl;
}
//used for vanity, displaying titles with a border if passed with a true boolean value


//FUNCTIONS DECLARED - code below main//
Book getData(ifstream& file);

bool openFile(ifstream& file);

void outputFile(string fileName);


int main() {
	//MAIN CODE BLOCK//
	vector<Book> bookVec;	//vector of Book objects (doeesnt work)

	title("  *         Library System         *  ", true);
	string fileN = "Books.txt";
	bool validate;

	ifstream myfile;
	myfile.open(fileN);
	validate = openFile(myfile);
	if (validate) {		//only runs if file opens correctly
		
		for (int i = 0;i > 40;i++) {
			bookVec.push_back(getData(myfile));
		}
	
	}

}


bool openFile(ifstream& file) {
	if (!file) {
		cout << "ERROR, When Opening File!" << endl;
		return false;
	}
	file >> noskipws; //makes it so that whitespace is read
	return true;
}	//function to open files, takes in the fstream file value as refrence returns a bool value depending on if it was opened
//function used for validation as well as opening


void outputFile(string fileName) {
	bool funcValidate = false;
	ifstream myfile;
	myfile.open(fileName);
	funcValidate = openFile(myfile);
	if (funcValidate) {			//open validation
		//displays data file
		string str;
		while (!myfile.eof()) {
			getline(myfile, str);
			cout << str;
			cout << endl;
		}
	}
	myfile.close();
}	//function outputs all contents of a file line by line, takes fstream value by refrence then outputs until it reachs the end of file


Book getData(ifstream& file) {
	string line;
	vector<string> data;

	getline(file, line);
	istringstream ss(line);
	string tmp;

	while (getline(ss, tmp, ',')) {
		data.push_back(tmp);
	}	//splits the line up into words seperated into commars in the vector

	Book books(stoi(data[0]), data[1], data[2], data[3], data[4]);
	return books;
}


//CLASS FUNCS///
void Book::outputData() {
	cout << "BookID: " << to_string(BookID);
	cout << "\nTitle: " << Title;
	cout << "\nAuthor: " << Author;
	cout << "\nPublisher: " << Publisher;
	cout << "\nReserved? : " << to_string(Reserved) << endl;
	//outputs the data of the class - big getter kinda
}
void Book::reserve(){
	if (!Reserved) {
		Reserved = true;
	}
	else {
		cout << "ERROR - book is reserved!" << endl;
	}
}	//reserves a book if free