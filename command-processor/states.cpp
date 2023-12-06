#include<bits/stdc++.h>
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

typedef enum{
    PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT, PREPARE_SYNTAX_ERROR
} PrepareResult;

typedef enum{
    EXECUTE_SUCCESS, EXECUTE_TABLE_FULL
} ExecuteResult;

typedef enum{
    SELECT, INSERT, UNDEFINED
} StatementType;

// Hardcoded table of id, username & email
typedef struct{
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE+1];
    char email[COLUMN_EMAIL_SIZE+1];
} Row;


typedef struct{
    StatementType type;
    Row row;
} Statement;

