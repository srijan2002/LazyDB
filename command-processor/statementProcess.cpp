#include<bits/stdc++.h>
#include "../wrapper-classes/InputBuffer.cpp"
#include "states.cpp"

using namespace std;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
   if(strncmp(input_buffer->buffer.c_str(),"insert",6)==0){
      statement->type = INSERT;

      // --
        string username, email; int id;
        string command;
        istringstream iss(input_buffer->buffer);
        iss >> command;

        if(command == "insert"){
            iss >> statement->row.id >> statement->row.username >> statement->row.email;
        }else{
            return PREPARE_SYNTAX_ERROR;
        }
        
      // -- 

      return PREPARE_SUCCESS;
   }
   if(strcmp(input_buffer->buffer.c_str(),"select")==0){
      statement->type = SELECT;
      return PREPARE_SUCCESS;
   }

    statement->type = UNDEFINED;
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement* statement){}

void statementProcess(InputBuffer* input_buffer){
    
    Statement statement;
    switch (prepare_statement(input_buffer, &statement))
    {
    case PREPARE_SUCCESS:
        execute_statement(&statement);
        break;

    case PREPARE_UNRECOGNIZED_STATEMENT:
        cout << "Unrecognized statement !" << endl;
        break;
    
    case PREPARE_SYNTAX_ERROR:
        cout << "Syntax error !" << endl;
        break;

    default:
        break;
    }
}