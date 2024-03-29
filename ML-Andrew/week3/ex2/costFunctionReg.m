function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta


sum_j = 0;
z = X*theta;
for i = 1:m
    sum_j += -y(i)*log(sigmoid(z(i))) -  (1 - y(i))*log(1 - sigmoid(z(i)));
end

sum_theta  = 0;
for j = 2:size(theta)
    sum_theta += theta(j)^2;
end

J = 1 / m * sum_j + lambda / (2*m)*sum_theta;

for j = 1:size(theta)
    sum_g = 0;
    for i = 1:m
        sum_g += (sigmoid(z(i)) - y(i))*X(:,j)(i);
    end
    if j == 1
        p_theta = 0;
    else
        p_theta = lambda / m * theta(j);
    end
    grad(j) = sum_g / m + p_theta;
end




% =============================================================

end
