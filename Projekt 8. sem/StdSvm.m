function [d1, d2, d3, sector] = StdSvm(in_alpha, in_beta, Ts)
    % Note: in_alpha and in_beta must be standardized to -1:1.

    % Adjust values for switching period
    alpha = in_alpha * Ts;
    beta = in_beta * Ts;

    
    % Variables to be used for SVM
    X = beta;
    Y = (beta + sqrt(3)*alpha)/2;
    Z = (beta - sqrt(3)*alpha)/2;

    % Determine sector
    if Y < 0
       if Z >= 0
          if X <= 0
              sector = 4;
          else
              sector = 3;
          end
       else
           sector = 5;
       end
    else
        if Z < 0
           if X <= 0
               sector = 6;
           else
               sector = 1;
           end
        else
            sector = 2;
        end
    end

    % Calculate duty cycles in seconds
    if ((sector == 1) | (sector == 4))
        d1 = 1/2 * (Ts+X-Z);
        d2 = d1 + Z;
        d3 = d2 - X;
    elseif ((sector == 2) | (sector == 5))
        d1 = 1/2 * (Ts+Y-Z);
        d2 = d1 + Z;
        d3 = d1 - Y;
    else
        d1 = 1/2 * (Ts-X+Y);
        d3 = d1 - Y;
        d2 = d3 + X;
    end

    % Adjust to between 0 and 1
    d1 = d1/Ts;
    d2 = d2/Ts;
    d3 = d3/Ts;
end