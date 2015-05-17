#include<iostream>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

void drawman(int n) {
  if(n == 1) {
    cout << "  ( ͡° ͜ʖ ͡°)" << endl;
    //cout << "   ______" << endl;
    //cout << "  o(.)(.)o" << endl;
    //cout << "   ( <> )" << endl;
    //cout << "   (~~~~)" << endl;
  }
  else if(n == 2) {
    drawman(1);
    cout << "     ||" << endl;
    cout << "     ||" << endl;
  }
  else if(n == 3) {
    drawman(1);
    cout << "  ___||" << endl;
    cout << "     ||" << endl;
  }
  else if(n == 4) {
    drawman(1);
    cout << "  ___||___" << endl;
    cout << "     ||" << endl;
  }
  else if(n == 5) {
    drawman(4);
    cout << "    /" << endl;
    cout << "   /" << endl;
  }
  else if(n == 6) {
    drawman(4);
    cout << "    /  \\" << endl;
    cout << "   /    \\" << endl;
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
  for(int i = 0; i < s.length(); i++) {
    if(s[i] != ' ') {
      count++;
    }
  }
  return count;
}

int main() {
  int hangman = 0;
  cout << "Let's play hangman!!!" << endl;
  string s = "side effects";
  char input;
  map<int,int> m;
  while(1) {
    output(s, m);
    cout << endl << "Make a guess bud!" << endl;
    while(!(cin >> input)) {
      cout << "Must input a character!" << endl;
      cin.ignore();
      cin.clear();
    }
    int correct = 0;
    for(int i = 0; i < s.length(); i++) {
      if(input == s[i]) {
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
        break;
      }
    }
    if(correct) {
      if(correct == 1) {
        cout << "Nice, there is 1 " << input << "!" << endl;
      } 
      else {
        cout << "Nice, there are " << correct << " " << input << "'s!" << endl;
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















