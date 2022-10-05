#ifndef OPTIONS_H_
#define OPTIONS_H_

struct options {
    unsigned int base;
    char* input;
};

int parse_options(int argc, char **argv, struct options *options);

#endif /* !OPTIONS_H_ */
