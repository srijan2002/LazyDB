#include<bits/stdc++.h>
#include<string>
#include "../wrapper-classes/InputBuffer.cpp"

using namespace std;

// Input prompt
void input_prompt(){ 
    cout<<"lazydb > ";
}

void read_input(InputBuffer* input_buffer){

    // Read input and store it in buffer
    getline(cin, input_buffer->buffer);
    
    // Check for empty buffer
    if(input_buffer->buffer.empty()){
        cout << "Error reading input" << endl;
        close_input_buffer(input_buffer);
        exit(EXIT_FAILURE);
    }

    // Check for exit command
    if(strcmp(input_buffer->buffer.c_str(),"exit")==0){
        cout << "Exit" << endl;
        close_input_buffer(input_buffer);
        exit(EXIT_SUCCESS);
    }

    input_buffer->input_length = input_buffer->buffer.length();

    // Remove the trailing newline character if present
    if (!input_buffer->buffer.empty() && input_buffer->buffer[input_buffer->input_length - 1] == '\n') {
        input_buffer->buffer.pop_back();
        input_buffer->input_length--;
    }
}

void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer);
}