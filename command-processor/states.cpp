#include<bits/stdc++.h>

typedef enum{
    PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum{
    SELECT, INSERT, UNDEFINED
} StatementType;

typedef struct{
    StatementType type;
} Statement;