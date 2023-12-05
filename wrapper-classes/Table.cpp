#include<bits/stdc++.h>
#include "../command-processor/row_representation.cpp"

//Average Page size used in vm of most computer architectures is 8KB
const uint32_t PAGE_SIZE = 8192;

#define TABLE_MAX_PAGES 100

const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
} Table;

Table* new_table(){

    Table* table = new Table();
    table->num_rows = 0;
    for(uint32_t i =0; i< TABLE_MAX_PAGES; i++)
        table->pages[i] = NULL;
    
    return table;
}

void free_table(Table* table){
    for(uint32_t i =0; i< TABLE_MAX_PAGES; i++)
        free(table->pages[i]);
    free(table);
}

void* row_slot(Table* table, uint32_t row_num){
    uint32_t page_num = row_num/ROW_SIZE;

    //Allocate page number in table
    void* page = table->pages[page_num];
    if(page==NULL){
        table->pages[page_num] = malloc(PAGE_SIZE);
        page = table->pages[page_num];
    }

    uint32_t row_no_offset = row_num%ROW_SIZE;
    uint32_t byte_offset = row_no_offset*ROW_SIZE;

    //returns a serialized location of the new row in a page
    return page + byte_offset;
}