#include<bits/stdc++.h>
#include<string>
#include "io-functions/readInput.cpp"
#include "io-functions/printFunctions.cpp"
#include "wrapper-classes/InputBuffer.cpp"

using namespace std;


int main(){

    InputBuffer* input_buffer = new_input_buffer();

    while(true){
        input_prompt();
        read_input(input_buffer);
    }

    return 0;
}