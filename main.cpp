#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
  string fileName, text, color;
  char choice;
  ifstream CSSfile;
  size_t pos;

  do {
    cout << "Please type the name of the CSS file to open: ";
    getline(cin, fileName);
    CSSfile.open(fileName, CSSfile.in);

    if(CSSfile.is_open()){
      while(getline(CSSfile, text)) { //read lines from file 'CSSfile' and put them into string 'text'
			 pos = text.find("color: #");
			  if(pos!=string::npos) {// string::npos is returned if string is not found
            cout <<"Found a color value: "<< text<<endl;
            break;
        }//else {cout << "No 'color: #' values found in file.";}<--use to make sure a value is found inside the text.
			}

    }else{cout << "could not open file\n";}

    CSSfile.close();
    cout << "Do you want to add another color pattern (y/n)?" << endl;
    cin >> choice;
    cin.ignore();

  }while (choice == 'y');
  

  return 0;
}