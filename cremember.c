
/*
 * Some C behavior:
 * 
 */

char *tmp  = "I get stored in data section, so I am ok to print from anywhere";
char tmp[] = "I get stored in stack memory  section, I am not ok to use outside a function where I get defined"
