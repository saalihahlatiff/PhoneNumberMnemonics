#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct whichNum{
  char option0;
  char option1;
  char option2;
  char option3;
};

whichNum get_letter(char number)
{
  whichNum letter;

  letter.option3 = ' ';
  switch(number) {
      //letter.option3 = 'empty';
    case '2':
       letter.option0 = 'A';
       letter.option1 = 'B';
       letter.option2 = 'C';
       break;
    
    case '3':
       letter.option0 = 'D';
       letter.option1 = 'E';
       letter.option2 = 'F';
       break;
  
    case '4':
       letter.option0 = 'G';
       letter.option1 = 'H';
       letter.option2 = 'I';
       break;
      
    case '5':
       letter.option0 = 'J';
       letter.option1 = 'K';
       letter.option2 = 'L';
       break;
  
    case '6':
       letter.option0 = 'M';
       letter.option1 = 'N';
       letter.option2 = 'O';
       break;
  
    case '7':
       letter.option0 = 'P';
       letter.option1 = 'Q';
       letter.option2 = 'R';
       letter.option3 = 'S';
      
       break;
  
    case '8':
       letter.option0 = 'T';
       letter.option1 = 'U';
       letter.option2 = 'V';
       break;
  
    case '9':
       letter.option0 = 'W';
       letter.option1 = 'X';
       letter.option2 = 'Y';
       letter.option3 = 'Z';
       break;
  }

  return letter;
    
}

  
int main(){
  ifstream f_read;
  
  const int index = 8;
  vector<whichNum> letter {index};
  char userinput[index];

  
  f_read.open("yawl.txt");
  if(!(f_read.is_open())){
    cout << "File not found!" << endl;
    return 1;
  }

  ofstream f_put;
  f_put.open("newyawl.txt");

  string word;
  f_read >> word;

  while(!f_read.eof()){
    if(word.length() == 3 || word.length() == 4){
      f_put << word << endl;
    }
  }

  
  cout << "enter number:" << endl;
  cin >> userinput;        



  char num;
  char punct;
  bool valid = true;

  for(int i = 0; i < index; i++){
    if(isdigit(userinput[i])){
      if(userinput[i] <= 1){
        valid = false;
        break;
      }
    }
    else if(ispunct(userinput[i])){
      if((i != 3) || (userinput[i] != '-')){
        valid = false;
        break;
      }
    }
    else{
      valid = false;
    }
  }

  if(valid == false){
    cout << "Invalid phone number" << endl;
  }
  else{
    cout << "Valid phone number!!!" << endl;
  }

  


  for(int i = 0; i < index; i++){
    if(isdigit(userinput[i])){
      num = userinput[i];
      cout << "num is : " << num << endl;
      letter.at(i).option0 = get_letter(num).option0;
      cout << "letter.at(i).option0 is : " << letter.at(i).option0 << endl;
      letter.at(i).option1 = get_letter(num).option1;
      cout << "letter.at(i).option1 is : " << letter.at(i).option1 << endl;
      letter.at(i).option2 = get_letter(num).option2;
      cout << "letter.at(i).option2 is : " << letter.at(i).option2 << endl;
      
      if(get_letter(num).option3 != ' '){
        letter.at(i).option3 = get_letter(num).option3;
        cout << "letter.at(i).option3 is : " << letter.at(i).option3 << endl;
      }
    }
  }

  /*
  for(int x = 0; x < index; x++){
    if(isdigit(userinput[i])){
      num = userinput[i];
    
      for(int y = 0; y < index; y++){
          
      }
      
      
   }
  }
  */

  ofstream f_write;
  f_write.open("output.txt");


    f_write.close();
    f_put.close();
    f_read.close();
    return 0;
}
