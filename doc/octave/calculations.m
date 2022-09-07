#this declares a set of values from 0 to 800 with ofset 1; 0,1,2,3 etc.
x1 = 0:1:800;
x2 = 0:1:800;

#y = 300*sin(100+x*0.01) + 300;
y1 = motions(x1);
y2 = motions(x2+100);

plot(x1, y1, 'r');
hold on
plot(x2, y2, 'g');
hold off
xlabel("x");
ylabel("sin(x)");
title("Simple 2-D Plot");

printf("motions(0) = %f", motions(0));
a = cos(1);
b = sin(1);