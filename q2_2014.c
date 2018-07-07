#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>

char* func(char *letters, char *digits);

int not_all_digits(char *digits);

int not_all_letters(char *letters);

int get_digits_sum(char *digits);

int main() {
    char *res = func("neta","2314");
    if (res){
        printf("%s\n",res);
    } else {
        printf("null\n");
    }
    return 0;
}


char* func(char *letters, char *digits){
    /*  verifications   */
    if (strlen(letters) != strlen(digits)){
        return NULL;
    }

    if (not_all_digits(digits) || not_all_letters(letters)){
        return NULL;
    }
    /*  allocate new string's length    */
    int res_len = get_digits_sum(digits);
    char *res = (char*) malloc((res_len+1)*sizeof(char));

    int loc=0;
    int i,j;
    int len_letters;

    len_letters=strlen(letters);

    for (i=0; i<len_letters; i++){
        for (j=0; j<(digits[i]-'0'); j++){
            res[loc++] = letters[i];
        }
    }
    res[loc] = '\0';
    return res;
}
/*
 *
 * [h][h][h][][][][][][][][][][]
 *
 * */
int get_digits_sum(char *digits) {
    int sum = 0;
    int i, len;

    len = strlen(digits);

    for (i=0; i<len; i++){
        sum += digits[i]-'0';
    }

    return sum;
}

int not_all_letters(char *letters) {
    int len,i;

    len = strlen(letters);


    for (i=0; i<len; i++){
        if (!isalpha(letters[i]) && !islower(letters[i])){
            return 1;
        }
    }

    return 0;
}

int not_all_digits(char *digits) {
    int len,i;

    len = strlen(digits);


    for (i=0; i<len; i++){
        if (!isdigit(digits[i])){
            return 1;
        }
    }

    return 0;
}

int is_digit(char c){
    if ((c >= '0' && c <= '9')){
        return 1;
    }
    return 0;
}