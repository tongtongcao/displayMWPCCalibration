#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void run(){
  ifstream input("dirname");
  vector<string> vect_str;
  string str;
  while(input>>str){
    vect_str.push_back(str);
  }

  ostringstream sstr;
  for(int i=0;i<vect_str.size();i++){
    sstr<<"/home/caot/trek-e36/analysis/MWPC/pedestal/"<<vect_str[i];
    chdir(sstr.str().c_str());
    system("pwd");
    sstr.str("");

    sstr<<"rm *.png *.pdf";
    system(sstr.str().c_str());
    sstr.str("");

    sstr<<"source "<<"/home/caot/trek-e36/analysis/MWPC/pedestal/"<<vect_str[i]<<"/run.sh";
    system(sstr.str().c_str());
    sstr.str("");
  }
}
