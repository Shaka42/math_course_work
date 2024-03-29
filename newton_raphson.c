#include<stdio.h>
#include<math.h>

double f(double x){
    return pow(x,3)-pow(x,2)-1;//original function
}
double df(double x){
    return (3*pow(x,2))-(2*x);//derivative of the function
}
// Newton Raphson Method function 
double newton_raphson(double intial_approximate){
    double intial_x = intial_approximate,final_x,error; int number_of_iterations=0;
    do{//application of the Newton Raphson Formula
        final_x = intial_x - (f(intial_x)/df(intial_x));
        error = fabs(final_x-intial_x);
        //checking for convergence
        if(error > 0.005){printf("x%d=%lf      x%d=%lf\n",(number_of_iterations),intial_x,(number_of_iterations+1),final_x);
        printf("Error = |%lf - %lf|=%lf \n\n",final_x, intial_x,error);}
        else{printf("x%d=%lf      x%d=%lf\n",(number_of_iterations),intial_x,(number_of_iterations+1),final_x);
        printf("Error = |%lf - %lf|=%lf  < 0.005\n\n",final_x, intial_x,error);}
        intial_x = final_x;
        number_of_iterations++;
    }while(error > 0.005 );
    printf("The number of iterations = %d",number_of_iterations);
    printf("\nThe final value of x is %lf",final_x);
    return final_x;
}
int main(void){
    double intial_approximate;
    printf("Enter the intial_approximation (Using 0.005 as error bound): ");
    scanf("%lf",&intial_approximate);
    printf("\nThe solution is %.2lf(2dps)",newton_raphson(intial_approximate));
    return 0;
}