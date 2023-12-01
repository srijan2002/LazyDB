#include<bits/stdc++.h>
#include "../wrapper-classes/InputBuffer.cpp"
#include "states.cpp"

using namespace std;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
   if(strcmp(input_buffer->buffer.c_str(),"insert")==0){
      statement->type = INSERT;
      return PREPARE_SUCCESS;
   }
   if(strcmp(input_buffer->buffer.c_str(),"select")==0){
      statement->type = SELECT;
      return PREPARE_SUCCESS;
   }

    statement->type = UNDEFINED;
    return PREPARE_UNRECOGNIZED_STATEMENT;

}

void statementProcess(InputBuffer* input_buffer){
    
    Statement statement;
    switch (prepare_statement(input_buffer, &statement))
    {
    case PREPARE_SUCCESS:
        
        break;

    case PREPARE_UNRECOGNIZED_STATEMENT:
        cout << "Unrecognized statement !" << endl;
        break;

    default:
        break;
    }
}