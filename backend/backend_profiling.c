#include <stdio.h>

#include "backend_profiling.h"

static void print_filter_count_header(FILE *file, const char *name) {
    fprintf(file, ",%s:zeros,%s:ones,%s:twos,%s:mores", name, name, name, name);
}

static void print_filter_count_counts(FILE *file, const filter_count *counts) {
    fprintf(file, ",%u,%u,%u,%u", counts->zeros, counts->ones, counts->twos, counts->mores);    
}

void save_backend_profile(const char *filename, const struct backend_profile *profile) {
    printf("\n\n\n************** HELLO World! **********************\n\n\n");
    FILE *f = fopen(filename, "w+");
    if (!f) {
        printf("\n\n******************** Unable to open file %s for writing ***************\n\n", filename);
        return;
    }
    
    fprintf(f, "creates,retrieve_from_ids,retrieve_from_filters,updates,deletes,delete_from_filters,lists,retrieve_from_names");
    print_filter_count_header(f, "retrieve_from_counts");
    print_filter_count_header(f, "delete_from_counts");
    print_filter_count_header(f, "list_counts");
    fprintf(f, "\n");
    
    fprintf(f, "%u,%u,%u,%u,%u,%u,%u,%u",
            profile->creates,
            profile->retrieve_from_ids,
            profile->retrieve_from_filters,
            profile->updates,
            profile->deletes,
            profile->delete_from_filters,
            profile->lists,
            profile->retrieve_from_names);
    print_filter_count_counts(f, &profile->retrieve_from_counts);
    print_filter_count_counts(f, &profile->delete_from_counts);
    print_filter_count_counts(f, &profile->list_counts);
    fprintf(f, "\n");
    
    fclose(f);
}