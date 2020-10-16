#include <stdio.h>

unsigned long calculate_no_of_paths(short, short, short);

int main()
{
    short sum, no_of_children, d;
    unsigned long no_of_paths;
    scanf("%hu %hu %hu",&sum, &no_of_children, &d);
    no_of_paths = calculate_no_of_paths(sum, no_of_children, d);
    printf("%lu\n",no_of_paths);
    return 0;
}

unsigned long calculate_no_of_paths(short sum, short no_of_children, short d)
{
    unsigned long no_of_paths[101][2];
    short i, j;
    const unsigned long mod = (1e9 + 7);

    no_of_paths[0][0] = 1;
    no_of_paths[0][1] = 0;
    for(i = 1; i <= sum; i++)
    {
        no_of_paths[i][0] = no_of_paths[i][1] = 0;

        for(j = 1; ((j <= no_of_children) && (i-j >= 0)); j++)
        {
            if(j < d)
            {
                no_of_paths[i][0] =(no_of_paths[i][0]+ no_of_paths[i-j][0])%mod;
                no_of_paths[i][1] = (no_of_paths[i][1] + no_of_paths[i-j][1])%mod;
            }
            else
            {
                no_of_paths[i][1] = (no_of_paths[i][1] + no_of_paths[i-j][0])%mod;
                no_of_paths[i][1] = (no_of_paths[i][1] + no_of_paths[i-j][1])%mod;
            }
        }
    }
    return no_of_paths[sum][1];
}