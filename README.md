# CSS Color Pattern Changer

## Description

This program is designed to identify background color values in CSS files. Later this program will be updated to identify background color values and ask the user if they want to change the color pattern. This program will look for key-phrases in the CSS code which will allow it to identify color values.

## Developer

Evan Burkhardt

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
example where it finds 'color: #' in the text

Please type the name of the CSS file to open: test.txt
Found a color value: color: #
Do you want to add another color pattern (y/n)?
n

example where it does not find 'color: #' in the text & what happens when you open another file that does contain 'color: #' in the text.

Please type the name of the CSS file to open: test2.txt
Do you want to add another color pattern (y/n)?
y
Please type the name of the CSS file to open: test.txt
Found a color value: color: #
Do you want to add another color pattern (y/n)?
```

## C++ Guide

### Variables and Data Types

The program uses string, char, ifstream, and size_t types. the string variables used are: 'fileName' which lets the user type in the name of the file to analyze and 'text' which will store the text from the file inside it. The char variable used is 'choice' which asks the user if they want to analyze another file after the program runs. The ifstream variable 'CSSfile' is used to access the file we are looking at and is opened according to the input typed in by the user in the 'fileName' string variable, and lastly the size_t variable 'pos' is used to find the position of the keyword inside the file.

  string fileName, text;
  char choice;
  ifstream CSSfile;
  size_t pos;


### Input and Output

THis program asks the user to input the name of the file by using 'getline(cin, fileName);' and it also gets input from the user to decide if it needs to re-run the program using 'cout << "Do you want to add another color pattern (y/n)?" << endl;
    cin >> choice;
    cin.ignore();'.

### Decisions

This program uses an if-else statement to check that the file has been opened and it also uses and if statement to find the keyword 'color: #' inside the file.

### Iteration

This program uses a do-while loop to first run the block of code for the user so they can change the color patter for a color and then repeat to ask them if they want to make another color pattern change and it also uses a while loop to read through the lines in the file to find the keyword 'color: #'.
```
if(CSSfile.is_open()){
  ~~~~~~~~~~~~
}else{cout << "could not open file\n";}
```


### File Input and Output

The file is opened and read by using 'CSSfile.open(fileName, CSSfile.in);' and is closed by using 'CSSfile.close();'

# v0.2 Updates
In v0.2 I added functions to the program and allowed the user to create their gradient.

###Functions
I added the functions:
```
string gradient ()
```
-which will allow the user to type in their preferred gradient by following instructions in case they do not know how.
```
int location (string text)
```
-which will allow the user to find the location of the keyphrase. This can be used in case they want to look inside the file themselves to alter it.

I currently 11/19/2020 have not been able to get the location function to work within the main program so I have excluded it for the time being so that the main program can be run without any errors.