#include <iostream>
#include <string.h>
using namespace std;

class Reverse  
{
  public:
  char *get(const char *str) {
        char *s = strdup(str);
        char c;
        int n = strlen(s);
        if (n <= 1) {
            return s;
        }

        for(int i = 0; i < n/2; i++) {
            c      = s[i];
            s[i]   = s[n-i -1];
            s[n-i-1] = c;
        }
        return s;
      }
};

int main () {
   string temp;
   Reverse *r = new Reverse();
   cout<<"Input a String\n";
   cin>>temp;
   const char *str = temp.c_str();
   cout<<"Reverse of  String is: " << r->get(temp.c_str()) << endl;
   delete r;
}
