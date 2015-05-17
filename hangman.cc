#include<iostream>
#include<sstream>
#include<map>
#include<cstdlib>
#include<time.h>

using namespace std;

void drawman(int n) {
  if(n == 1) {
    cout << "                                   _________" << endl;
    cout << "                                   |       |" << endl;                     
    cout << "                                ( ͡° ͜ʖ ͡°)   |" << endl;
    //cout << "   ______" << endl;
    //cout << "  o(.)(.)o" << endl;
    //cout << "   ( <> )" << endl;
    //cout << "   (~~~~)" << endl;
  }
  else if(n == 2) {
    drawman(1);
    cout << "                                   ||      |" << endl;
    cout << "                                   ||      |" << endl;
  }
  else if(n == 3) {
    drawman(1);
    cout << "                                ___||      |" << endl;
    cout << "                                   ||      |" << endl;
  }
  else if(n == 4) {
    drawman(1);
    cout << "                                ___||___   |" << endl;
    cout << "                                   ||      |" << endl;
  }
  else if(n == 5) {
    drawman(4);
    cout << "                                  /        |" << endl;
    cout << "                                 /         |" << endl;
  }
  else if(n == 6) {
    drawman(4);
    cout << "                                  /  \\     |" << endl;
    cout << "                                 /    \\    |" << endl;
  }
}

void output(string s, map<int,int>& m) {
  int n = s.length();
  for(int i = 0; i < n; i++) {
    if(s[i] == ' ') {
      cout << "   ";
    }
    else if(m.count(i) == 0) {
      cout << "__ ";
    }
    else if(m.count(i) == 1) {
      cout << s[i] << " ";
    }
  }
  cout << endl;
}

int actuallength(string s) {
  int count = 0;
  stringstream ss(s);
  while(ss >> s) {
    count += s.length();
  }
  return count;
}

int ask() {
  int val = 1;
  string answer;
  while(1) {
    cout << "Would you like to play hangman?! (yes/no)" << endl;
    getline(cin,answer);
    stringstream sss(answer);
    sss >> answer;
    if(answer == "yes" && !(sss >> answer)) {
      break;
    }
    else if(answer == "no" && !(sss >> answer)) {
      cout << "OK, bye!" << endl;
      val = 0;
      break;
    }
    else {
      cout << "Please enter yes or no!" << endl;
    }
  }
  return val;
}

void playgame(string s) {
  int hangman = 0;
  cout << "Let's play hangman!!!" << endl;
  string input;
  map<int,int> m;
  map<string,int> guesses;
  while(1) {
    output(s, m);
    cout << endl << "Make a guess bud!" << endl;
    while(getline(cin,input)) {
      if(input.length() == 1) {
        if(guesses.count(input) == 1) {
          cout << "You already guessed that!" << endl;
        }
        else {
          guesses[input] = 0;
          break;
        }
      }
      else {
        cout << "Must input a single character!" << endl;
      }
    }
    stringstream ss(input);
    char input1;
    ss >> input1;
    int correct = 0;
    for(int i = 0; i < s.length(); i++) {
      if(input1 == s[i]) {
        correct++;
        m[i] = 0;
      }
    }
    if(!correct) {
      cout << "Sorry, no " << input << "'s!" << endl;
      hangman++;
      drawman(hangman);
      if(hangman == 6) {
        cout << "Sorry, you lose!" << endl;
        cout << "The correct answer was: " << s << endl;
        break;
      }
    }
    if(correct) {
      if(correct == 1) {
        cout << "Nice, there is 1 " << input1 << "!" << endl;
      } 
      else {
        cout << "Nice, there are " << correct << " " << input1 << "'s!" << endl;
      }
      if(m.size() == actuallength(s)) {
        cout << "Nice, you won!!!" << endl;
        output(s, m);
        break;
      }
      drawman(hangman);
    }
  }
}

int main() {
  srand (time(NULL));
  string words[] = {"banana", "dance party", "programming language", "fruit salad", "transport truck",
                    "chicken rap", "bbq sauce", "monkey in a tree", "french fries", "apple sauce"};
  while(1) {
    if(ask()) {
      playgame(words[rand() % 10]);
    }
    else {
      break;
    }
  }
}
