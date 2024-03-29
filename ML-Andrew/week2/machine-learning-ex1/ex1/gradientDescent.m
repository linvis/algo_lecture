function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESCENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

a = theta(1);
b = theta(2);
for iter = 1:num_iters

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %
    sum_h0 = 0;
    sum_h1 = 0;

    for n = 1:m
        h = a + b * X(:,2)(n) - y(n);
        sum_h0 += h;
        sum_h1 += h * X(:,2)(n);
    end

    a = a - alpha * 1 / m * sum_h0;
    b = b - alpha * 1 / m * sum_h1;







    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(X, y, theta);

end

theta(1) = a;
theta(2) = b;

end
