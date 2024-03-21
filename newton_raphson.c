#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double newton_raphson(double intial_approximate){
    double intial_x = intial_approximate,final_x,error,number_of_iterations=1;
    do
    {
        final_x = ((2*pow(intial_x,3)-(pow(intial_x,2)-1))/((3*pow(intial_x,2))-(2*intial_x)));
        error = abs(final_x-intial_x);
        intial_approximate = final_x;
        number_of_iterations++;
    }while (error > 0.005);
    printf("The number of iterations = %d",(int)number_of_iterations);
    return final_x;
}


int main(void){
    double intial_approximate;
    printf("Enter the intial_approximation: ");
    scanf("%lf",&intial_approximate);
    printf("\nThe solution is %.2lf",newton_raphson(intial_approximate));
    return 0;
}