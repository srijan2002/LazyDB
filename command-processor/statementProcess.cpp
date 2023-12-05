#include<bits/stdc++.h>
#include "../wrapper-classes/InputBuffer.cpp"
#include "states.cpp"
#include "../wrapper-classes/Table.cpp"

using namespace std;

void print_row(Row* row){}

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

ExecuteResult execute_insert(Statement* statement, Table* table){

    if(table->num_rows>=TABLE_MAX_ROWS)
    return EXECUTE_TABLE_FULL;

    Row* row_to_insert = &(statement->row);

    serialize_row(row_to_insert, row_slot(table, table->num_rows));
    table->num_rows += 1;

    return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement* statement, Table* table){

    Row* row_to_select;

    for(uint32_t i = 0; i< table->num_rows;i++){
        deserialize_row(row_slot(table, i), row_to_select);
        print_row(row_to_select);
    }
    
    return EXECUTE_SUCCESS;
}

ExecuteResult execute_statement(Statement* statement, Table* table){

    switch (statement->type)
    {
    case INSERT:
        return execute_insert(statement,table);

    case SELECT:
        return execute_select(statement,table);
    
    default:
        return EXECUTE_TABLE_FULL;
    }
}

void statementProcess(InputBuffer* input_buffer, Table* table){
    
    Statement statement;
    switch (prepare_statement(input_buffer, &statement))
    {
    case PREPARE_SUCCESS:
        execute_statement(&statement, table);
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