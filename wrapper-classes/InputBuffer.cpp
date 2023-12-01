#include<bits/stdc++.h>

using namespace std;

#ifndef MYSTRUCT_H
#define MYSTRUCT_H


typedef struct {
    string buffer;
    size_t buffer_length;
    ssize_t input_length;

} InputBuffer;

InputBuffer* new_input_buffer() {
  
  InputBuffer* input_buffer = new InputBuffer();
  input_buffer->buffer = "";
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}

#endif // MYSTRUCT_H