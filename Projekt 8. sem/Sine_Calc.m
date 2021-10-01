clear, close all, clc;

input = -pi:0.01:pi;

output_sine = sin(input);
output_taylor = input .* (1 + input.^2 .* (-1/(factorial(3)) + input.^2 .* (1/(factorial(5)) + input.^2 .* (-1/(factorial(7)) + input.^2 .* 1/(factorial(9))))));

figure(1)
plot(input, output_sine, input, output_taylor)

figure(2)
plot(input, output_sine-output_taylor)


% C CODE
%     #include "sleep.h"
% 
%     #define a_zero  (f32)0.1666666666666666666666666666666667
%     #define a_one   (f32)0.0083333333333333333333333333333333
%     #define a_two   (f32)0.0001984126984126984126984126984127
%     #define a_three (f32)0.0000027557319223985892510950593270458
%
%
%     initGpios();
% 
%     f32 input = -PI, output;
% 
%     xil_printf("Starting sine calculation test.\r\n");
% 
%     while(1) {
%     	if (input >= PI) {
%     		input = -PI;
%     	} else {
%     		input += PI/20;
%     	}
% 
%     	enablePrecharge();
%     	output = input*(1 + input*input * (-a_zero + input*input * (a_one + input*input * (-a_two + input*input * a_three))));
%     	disablePrecharge();
% 
%     	printf("Calculated value is: %f\r\n", output);
% 
%     	usleep(500000);
%     }