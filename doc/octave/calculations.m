#this declares a set of values from 0 to 800 with ofset 1; 0,1,2,3 etc.
x = 0:1:800;

#y = 300*sin(100+x*0.01) + 300;
y = motions(x);

plot(x, y);
xlabel("x");
ylabel("sin(x)");
title("Simple 2-D Plot");

printf("motions(0) = %f", motions(0));
a = cos(1);
b = sin(1);