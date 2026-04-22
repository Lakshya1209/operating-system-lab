C#include <stdio.h>
#include <unistd.h>

int main() {
    fork(); 
    printf("Process ID: %d\n", getpid());
    return 0;
}



C#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    return 0;
}


C#include <stdio.h>
#include <unistd.h>

int main() {
    fork(); // 2 processes
    fork(); // 4 processes
    fork(); // 8 processes
    
    printf("Hello from Process: %d\n", getpid());
    return 0;
}