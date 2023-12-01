#include <stdio.h>
int a[3] = {1, 2, 3};
int main()
{
    void b(void);
    b();
    printf("%d\n",a[1]); 
    return 0;
}
void b(){
    a[1] = 0;
}