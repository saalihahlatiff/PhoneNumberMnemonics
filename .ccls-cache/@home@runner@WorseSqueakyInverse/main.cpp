#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#define MAX_SIZE 100

using namespace std;

string get_letter(float grade)
{
  if(grade >= 92){
    return "A";
  }
  else if(grade >= 80){
    return "B";
  }
  else if(grade >= 70){
    return "C";
  }
  else if(grade >= 60){
    return "D";
  }
  else{
    return "F";
  }

}

int main(){
  ifstream f_read;
  string input_number;
  int num;
  char punct;
  bool valid = false;
  
  cin >> input_number;
  /* You will then accept, from user input, a phone number as a string. Then you will validate that the phone number is in the correct format and contains valid numbers. If the phone number is not valid, you should display the message "Invalid phone number" and exit. */
  
  for(int i=0; i<9; i++){
    if(isdigit(input_number[i])){
      input_number[i] >> num;
    }
    else if(ispunct(input_number[i])){
      input_number[i] >> punct;
    }
    if((num < 1) || (punct == '-')){
      valid = true;
    }
    else{
      valid = false;
      cout << "Invalid phone number" << endl;
      break;
    }
  }
  
  f_read.open("yawl.txt");
  int student_num;
  f_read >> student_num;
  cout << student_num << endl;

  f_read.ignore();
  string names[student_num];
  float grades[student_num];

  int highest = 0;
  int lowest = 100;

  for(int i = 0; i < student_num; i++){
    getline(f_read, names[i]);
    int grade = 0;
    for(int a = 0; a < 3; a++){
      float num;
      f_read >> num;
      grade += num;
    }
  
  f_read.ignore();

  grade /= 3;

  if(grade > highest){
    highest = grade;
  }
  if(grade < lowest){
    lowest = grade;
  }

  grades[i] = grade;
}
  

  ofstream f_write;
  f_write.open("output.txt");
  f_write << "Highest grade: " << highest << endl << "Lowest grade: " << lowest << endl << endl;

  for(int i = 0; i < student_num; i++){
    f_write << names[i] << ": " <<   get_letter(grades[i]) << endl;
  }

    f_write.close();
    f_read.close();
    return 0;
}