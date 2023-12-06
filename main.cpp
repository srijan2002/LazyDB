#include<bits/stdc++.h>
#include<string>
#include "io-functions/readInput.cpp"
#include "io-functions/printFunctions.cpp"

using namespace std;


int main(){

    Table* table = new_table();
    InputBuffer* input_buffer = new_input_buffer();

    while(true){
        input_prompt();
        read_input(input_buffer, table);
    }
  return 0;
}