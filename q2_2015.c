#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
int res_len(char *str);

char *func(char *str);

int main(){

    printf("%s", func("ha1py0f w1ek0gen0hd"));

    return 0;
}

char *func(char *str){
    int str_len, result_len, i, loc=0;
    char *result;

    str_len = strlen(str);
    result_len = res_len(str);

    /*  allocate new string (plus '\0')*/
    result = (char*) malloc ((result_len+1)* sizeof(char));
    result[result_len] = '\0';

    /*  create new string   */
    for (i=0; i<str_len; i++){

        if (str[i] != '0'){
            if (str[i] == '1'){
                /*  if a[i] is 1 copy following char    */
                result[loc++] = str[i+1];
            } else {
                /*  if a[i] is just a letter --> copy as is */
                result[loc++] = str[i];
            }
        } else {
            /*  if a[i] is 0 skip next char */
            i += 1;
        }
    }
    return result;
}


int res_len(char *str){
    int str_len = strlen(str);
    int count,i;

    count = str_len;
    for (i=0; i<str_len; i++){
        if (str[i] == '0'){
            count -= 2;
        }
    }

    return count;
}