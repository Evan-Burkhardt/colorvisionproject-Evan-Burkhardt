//***identify background color and color number in a CSS file-> change it from background color1; to background image: gradient(to right(or left/top/bottom(?)) OriginalColor(red for example), NewColor(yellow for example)) This won't give it a pattern, but it will allow me to change from a single color to a gradient by altering the string values in the CSS file (*read more about gradients and for more examples of gradients on w3schools CSS page*).
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//ADD FUNCTIONS HERE
string colorValueFinder (string text);
string gradient ();
int location (string text);

//
int main(){
  string fileName, text, createdGradient;
  int foundLocation;
  char choice;
  fstream CSSfile;
  size_t position;

  do {
    cout << "Please type the name of the CSS file to open: ";
    getline(cin, fileName);
    CSSfile.open(fileName, std::fstream::in | std::fstream::out);//QUESTION: Does CSSfile.out belong here or do I need to include it in the code later?
    //CSSfile.in and CSSfile.out let me edit the file

    if(CSSfile.is_open()){//checks if file is open.

      while(getline(CSSfile, text)) { //read lines from file 'CSSfile' and put them into string 'text'.
			 position = text.find("background-color:");//defines the keyphrase to search for.
        //replace this with function 1 to find the keyphrase.*****

			  if(position != string::npos) {// string::npos is returned if string is not found
        //NOTE FOR ME: npos basically means 'no matches found' so this if statement reads like 'if position is found then continue/if position value doe not equal 'Not FOund' then continue' meaning the value for position has been found =).END NOTE
        
  //IMPORTANT NOTE DOWN BELOW:
      //ADD the LOCATION FUNCTION into the code here, just figure out what to do with the CSSfile parameter.
      //EX. foundLocation = location()<-- would be the funciton
        createdGradient = gradient();
            cout<< "Found a color value:"<< text<< "| New gradient created: "<< createdGradient<< endl;
      //AFTER i COUT the gradient I want to COUT the location right beneath it.
      //EX. cout<< "color value was found on line: "<< foundLocation<<endl; 

        }//else {cout << "No 'color: #' values found in file.";}<--use to make sure a value is found inside the text.
			}

    }else{cout << "could not open file\n";}//displays if file is not opened/file name is entered incorrectly.

    CSSfile.close();
    cout << "Do you want to add another color pattern? (select 'y'/'Y' to continue or press any other button to exit)" << endl;
    cin >> choice;
    cin.ignore();
    //Gives the user the option to change the gradient.

  }while (choice == 'y' || choice == 'Y');
  

  return 0;
}

//FUNctions begin here
//1111111111111111111111111111111111111111111111111111111111111111111111111

/*string colorValueFinder (string text){
//this function will identify the value 'background-color' inside the file 

 return some string variable;
}*/


//2222222222222222222222222222222222222222222222222222222222222222222222222
//Creates the CSS gradient to be implemented back into the file by having the user add in their input.
string gradient (){//PARAMETERS might need input from location function, text variable in int main, or from function 1 if I decide to do it. Although this function appears to stand on its own without anything else idk
  //Ask user to type in the gradient they want using a prewritten format.
  //VARIABLE CREATION
  string chooseDirection;
  string direction;
  string color;
  string gradient;
  string input1;

//DIRECTION input/output
//create list of user instructions, needs direction and colors.
  cout << "To create your gradient please follow the instructions: \n";
  cout << "First please enter the direction you want the gradient to folow (make sure you are only using undercase letters!): If you want your gradient to go vertically type 'vertical', if you want your gradient to go horizontally type 'horizontal', if you want your gradient to go diagonally type 'diagonal'. (the gradient will begin with the first color you choose and will move top to bottom/left to right/top-left to bottom-right ending with the last color you have chosen.)\n";

//gather user input for DIRECTION
cin>>chooseDirection;

//create the ouptuts to the file as directed by the user.
if (chooseDirection == "vertical"){
  direction = "(to bottom, ";//this output follows immediately after function 1
}//else {cout<<"Make sure you are using undercase letters and are spelling it correctly!";}

if (chooseDirection == "horizontal"){
  direction = "(to right, ";//this output follows immediately after function 1
}//else {cout<<"Make sure you are using undercase letters and are spelling it correctly!";} If i add them in then 2/3 will print out the else statement

if (chooseDirection == "diagonal"){
  direction = "(to bottom right, ";//this output follows immediately after function 1
}//else {cout<<"Make sure you are using undercase letters and are spelling it correctly!";}
//direction = chooseDirection;??

//COLOR 
cout<<"\nNow you can choose which colors you would like to use. You can choose from red, orange, yellow, green, blue, indigo, or violet. Please make sure to type your input values with a ',' between each one like so: 'red,yellow,indigo,green,blue' \n";
cin>>color;

gradient = "background-image: linear-gradient" + direction + color + ")";//this will create our gradient to be edited into the file.

  return gradient;
}


//3333333333333333333333333333333333333333333333333333333333333333333333333

/*      
             void location(string text, fstream CSSfile, size_t position){
  int counter = 1;
  int lineNumber;


  for(int i = 0; i<counter; i++){
    while(getline(CSSfile, text)) { 
    position = text.find("background-color:");
    counter++;
      if(position == true){
        i = lineNumber;
        cout<<lineNumber;
      }
    }


    //i = lineNumber;
  }


  //return lineNumber; only use if I do not make this a VOID type
}
*/
//END OF LOCATION FUNCTION

//NOTES: make a helper function that can find all of the color values inside the file (I can probably use function location to do this || I just create a new function to find it, I can delete first function, kepp 2nd, keep this one, and then create a 3rd for finding color values.)