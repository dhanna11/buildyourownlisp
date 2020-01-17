#include <stdio.h>
#include <stdlib.h>

#include <histedit.h>
#include <editline/readline.h>
#include <mpc.h>

int main(int argc, char** argv) {
   
  /* Print Version and Exit Information */
  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr = mpc_new("expr");
  mpc_parser_t* Lispy = mpc_new("lispy"); 

  mpca_lang(MPCA_LANG_DEFAULT, 
          "                                                 \
            number : -?[0-9]+ ;                             \
            operator : '+' | '-' | '*' | '/' ;              \
            expr : <number> | '(' <operator> <expr>+ ')' ;  \
            lispy : /^/ <operator> <expr>+ /$/ ;            \
          ",
          Number, Operator, Expr, Lispy);
  /* In a never ending loop */
  while (1) {
    
    /* Output our prompt and get input */
    char* input = readline("lispy> ");
    
    /* Add input to history */
    add_history(input);
    
    /* Echo input back to user */    
    printf("No you're a %s\n", input);

    /* Free retrived input */
    free(input);
    
  }
  
  return 0;
}
