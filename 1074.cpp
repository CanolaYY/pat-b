#include <iostream>
#include <string>

using namespace std;

string sum(string a,string b,string radix){
  string result = "";
  if(a.size()<b.size()){
    string tmp = a;
    a = b;
    b = tmp;
  }
  int indix = radix.size();
  int flag = 0;
  for(int i=0,length=b.size();i<length;++i){
    int d = radix[--indix] - '0';
    if(!d){
      d+=10;
    }
    flag += a[a.size()-1-i] + b[length-1-i] - '0' - '0';
    result = (char)(flag % d + '0') + result;
    flag = (flag - flag % d)/d;
  }
  for(int i=b.size(),length=a.size();i<length;++i){
    int d = radix[--indix] - '0';
    if(!d){
      d+=10;
    }
    flag += a[length-1-i] - '0';
    result = (char)(flag % d + '0') + result;
    flag = (flag - flag % d)/d;
  }
  if(flag!=0){
    result = (char)(flag + '0') + result;
  }
  return result;
}

int main(int argc, char const *argv[])
{
  string radix,result;
  string a,b;
  cin >> radix >> a >> b;
  result = sum(a,b,radix);
  bool first = true;
  for(int i=0;i<result.size();++i){
    if(first&&result[i]=='0')
      continue;
    first = false;
    cout << result[i];
  }
  if(first)
    cout << 0;
  return 0;
}