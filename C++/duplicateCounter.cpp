#include <iostream>
#include <cstring>
using namespace std;

// PREP

// p : chars
// I will loop over all of the chars and
// then I will have an inner loop that will compare the char
// to the whole array and as soon the count reaches two I will break it and add one to the reps

size_t duplicateCount(const char* in)
{
    size_t reps = 0;
  
    int count = 0;
    
    if (in == nullptr || strcmp(in, "") == 0 || strcmp(in, " ") == 0) {
        return 0;
    }
    
    for (const char* current = in; *current != '\0'; current++) {
      const char c = *current;
      
      for (const char* inner_current = in; *current != '\0'; current++) {
        const char inner_c = *inner_current;

        if(c == inner_c){
            count ++ ;
        }

        if (count == 2 || *current == '\0'){
            reps ++;
            count = 0;
            break;
        }
            
      }
            
    }
    
    
    return reps;
}


int main() {
    
    return 0;
}