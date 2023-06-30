#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int calcIndex(string s,char c){
int count = 0;
int index = -1;
  for(int i=0;i<s.size();i++){
    if(s[i] == '(') count++;
    else if(s[i] == ')') count--;
    else if(s[i] == c && count == 1)index = i;
  }
  return index;

}

int main() {
  int n;
  cin >> n;
  vector<string> arr[n + 1];
  arr[0].push_back("ass");
  for (int i = 1; i < n + 1; i++) {
    string s;
    cin >> s;
    string temp = "";

    for (int j = 0; j < (int)s.size(); j++) {
      if (s[j] != '/') {
        temp += s[j];
      } else {
        arr[i].push_back(temp);
        temp = "";
      }
    }

    arr[i].push_back(temp);
  }
  int prem=0;
  for (int z = 1; z < n+1; z++) {
    if(arr[z][1]=="P")prem++;
  } 
  int steps = prem;
  prem++;
  
  //cout << n << endl;
  for (int j = prem; j < n + 1; j++) {
    string temp,temp2;
    if (arr[j][1] == "^i") {
      temp = "(" + (string)arr[stoi(arr[j][2])][0] + "^" + arr[stoi(arr[j][3])][0] + ")";
      if (temp == arr[j][0]) {
        steps++;
      } else
      { cout << "Not a valid proof"<< endl; break;}
    }

    
    if (arr[j][1] == "^e1") {
      int ind = calcIndex(arr[stoi(arr[j][2])][0],'^');
      for(int k = 0; k<ind;k++){
        //if(arr[stoi(arr[j][2])][0][k]=='^') break;
        temp+= arr[stoi(arr[j][2])][0][k];
      }
      temp.erase(0, 1);
      if (temp == arr[j][0]) {
       steps++;
      } else { cout << "Not a valid proof"<< endl; break;}
    }

    
    if (arr[j][1] == "^e2") {
      int ind = calcIndex(arr[stoi(arr[j][2])][0],'^');ind++;
      //bool f = false;
      for(int k = ind; k<arr[stoi(arr[j][2])][0].length();k++){
        temp+= arr[stoi(arr[j][2])][0][k];
        //if(f)temp+= arr[stoi(arr[j][2])][0][k];
        //if(arr[stoi(arr[j][2])][0][k]=='^') f=true; 
      } 
      temp.pop_back();
      if (temp == arr[j][0]) {
       steps++;
      } 
      else { cout << "Not a valid proof"<< endl; break;}
    }

    if (arr[j][1] == ">e") {
      temp='(' + arr[stoi(arr[j][3])][0] + '>' + arr[j][0] +')' ;
      if (temp == arr[stoi(arr[j][2])][0]) {
        steps++;
      } else { cout << "Not a valid proof"<< endl; break;}
    }

    if (arr[j][1] == "MT") {
      int ind = calcIndex(arr[stoi(arr[j][2])][0],'>');
      bool f = false;temp+='~';temp2+='~';
      for(int k = 0; k<ind;k++){
        //if(arr[stoi(arr[j][2])][0][k]=='^') break;
        temp2+= arr[stoi(arr[j][2])][0][k];
      }
      ind++;
      for(int k = ind; k<arr[stoi(arr[j][2])][0].length();k++){
        //if(f)temp+= arr[stoi(arr[j][2])][0][k];
        temp+= arr[stoi(arr[j][2])][0][k];
        //if(arr[stoi(arr[j][2])][0][k]=='>') f=true;
        //if(!f)temp2+= arr[stoi(arr[j][2])][0][k];
      }
      temp.pop_back();
      temp2.erase(1, 1);
      if(temp == arr[stoi(arr[j][3])][0] && temp2 == arr[j][0])
        steps++;
      else
        { cout << "Not a valid proof"<< endl; break;}
    }

    if (arr[j][1] == "V1" || arr[j][1] == "v1")
    {
        //string t ="";
        int in= calcIndex(arr[j][0], 'v');
        for(int k=0;k<in;k++)
        {
           temp+= arr[j][0][k]; 
        }
      temp.erase(0, 1);
        if( temp==arr[stoi(arr[j][2])][0] )
        {
          steps++;
        } 
        else
        { cout << "Not a valid proof"<< endl; break;} 
        
    }
    if (arr[j][1] == "V2" || arr[j][1] == "v2")
    {
        //string t ="";
        int in= calcIndex(arr[j][0], 'v');
        for(int k=++in;k<arr[j][0].length();k++)
        {
           temp+= arr[j][0][k]; 
        }
      temp.pop_back();
        if( temp==arr[stoi(arr[j][2])][0])
        {
          steps++;
        } 
        else
      { cout << "Not a valid proof"<< endl; break;}
        
    }
    
  }
  if(steps==n)cout<<"Valid Proof"<<endl;
}