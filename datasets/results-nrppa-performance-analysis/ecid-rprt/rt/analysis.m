% NRPPa Performance Analysis - M-Script
%
% created: 10/21/2024, NK
% last modified: 10/30/2024, NK
% tested: GNU/Octave v8.4.0
%

% (0) Loading statistics package, setup figure
pkg load statistics

t = zeros(10000,4);
x = zeros(1,4);
s2 = zeros(1,4);
s = zeros(1,4);
ci = zeros(2,4);
se = zeros(1,4);

% (1) Loading CSV files
in0 = dlmread("res_rprt_1_8_p0.csv");
in1 = dlmread("res_rprt_1_8_p1.csv");
in2 = dlmread("res_rprt_1_8_p2.csv");
in3 = dlmread("res_rprt_1_8_p3.csv");

% (2) Extract last column as vector and map the time vector to ms
t(:,1) = in0(:,3)/10^6;
t(:,2) = in1(:,3)/10^6;
t(:,3) = in2(:,3)/10^6;
t(:,4) = in3(:,3)/10^6;


for i=1:4
	%figure, hold on

	% (3) Calculate (sample mean and) sample variance and sample standard deviation (here: period 0 -> 120 ms)
	x(i) = sum(t(:,i))/numel(t(:,i));
	s2(i) = sum((t(:,i)-x(i)).^2)/(numel(t(:,i))-1);
	s(i) = sqrt(s2(i));

	% (4) Plotting Normal Distribution
	%tt = [x(i)-10:0.1:x(i)+10];
	%plot(tt, normpdf(tt, x(i), s(i)))
	%plot([p(i),p(i)],[0,0.2], 'r')

	% (5) Confidence intervals with 1-alpha = 0.995 -> z = 2.85
	se(i) = 2.58*s(i)/sqrt(numel(t(:,i)));
	ci(1,i) = x(i)-2.58*s(i)/sqrt(numel(t(:,i)));
	ci(2,i) = x(i)+2.58*s(i)/sqrt(numel(t(:,i)));
	%plot([ci(1,i),ci(1,i)],[ci(2,i),ci(2,i)], 'b')
endfor


