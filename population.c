#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    int end_size;
    do {
        start_size = get_int("What is the initial population size of..lamas? \n ");
    }
    while (start_size < 9);

    do {
        end_size = get_int("What is the target population size? \n");
    }
    while (end_size < start_size);



    int n_years;
    int increase = start_size;
    for (n_years = 0 ; increase < end_size; n_years++) {
        increase = (int)increase + (int)(increase / 3) - (int)(increase / 4);
     // printf("Population after %i year is %i \n", n_years, (int)increase); // optional code
    }
    printf("Start size: %i \n", start_size);
    printf("End size: %i \n", end_size);
    printf("Years: %i \n", n_years);


}
