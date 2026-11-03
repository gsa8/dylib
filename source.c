#include <stdio.h>
attribute((constructor)) void initializer() { printf("Loaded successfully!\n"); }
