#include"stdio.h"
int trap(int *height, int heightSize)
{
    int lp = 0, rp = 1, sum = 0;
    if (heightSize == 0)
        return 0;
    while (height[lp] == 0)
    {
        lp++;
        rp++;
    }
    while (rp < heightSize)
    {
        while (height[rp] < height[lp])
        {
            sum += height[lp] - height[rp];
            rp++;
        }
        lp = rp;
        rp = lp + 1;
    }
    return sum;
}

int main(void){
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, heightSize = 12,s;
    s = trap(height, heightSize);
    printf("%d", s);
}