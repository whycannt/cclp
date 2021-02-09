#include<stdio.h>
#include<unistd.h>

//#    Syntax:
//#    Return Value:
//#    If the option takes a value, that value is pointer to the external variable optarg.
//#    ‘-1’ if there are no more options to process.
//#    ‘?’ when there is an unrecognized option and it stores into external variable optopt.
//#    If an option requires a value (such as -f in our example) and no value is given, getopt normally returns ?.
//#    By placing a colon as the first character of the options string, getopt returns: instead of ? when no value is given.
//#    getopt(int argc, char *const argv[], const char *optstring)

int main (int argc , char *argv[]) {
    int opt;

    // put ':' in the starting of the 
    // string so that program can  
    //distinguish between '?' and ':'
    while ((opt = getopt(argc,argv,":if:lrx")) != -1) {
        switch (opt) {  
            case 'i':  
            case 'l':  
            case 'r':  
                printf("option: %c\n", opt);  
                break;  
            case 'f':  
                printf("filename: %s\n", optarg);  
                break;  
            case ':':  
                printf("option needs a value\n");  
                break;  
            case '?':  
                printf("unknown option: %c\n", optopt); 
                break;  
        }  
    }
    // optind is for the extra arguments 
    // which are not parsed 
    for (; optind < argc; optind++) {      
        printf("extra arguments: %s\n", argv[optind]);  
    } 
    return 0;
}
