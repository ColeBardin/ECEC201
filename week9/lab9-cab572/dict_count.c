struct list {
    char *key;
    unsigned long hash;
    void *user_data;
    struct list *next;
};

struct dict {
    struct list **bins;
    unsigned int nbins;
    void (*deleter)(void *user_data);
};


unsigned long int dict_count(struct dict *D)
{
    /* Rewrite this function to return the number
       of items stored in the dictionary pointed
       to by the variable D! */
    return 0;
}