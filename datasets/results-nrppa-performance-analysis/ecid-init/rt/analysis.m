% NRPPa Performance Analysis - M-Script
%
% created: 10/21/2024, NK
% last modified: 10/30/2024, NK
% tested: GNU/Octave v8.4.0
%

% (0) Loading statistics package, setup figure
pkg load statistics

% (1) Loading CSV files
in0 = dlmread("res_init_256_4.csv");

% (2) Extract last column as vector and map the time vector to ms
t = in0(:,3)/10^6;

% (3) Calculate (sample mean and) sample variance and sample standard deviation (here: period 0 -> 120 ms)
x = sum(t)/numel(t);
s2 = sum((t-x).^2)/(numel(t)-1);
s = sqrt(s2);

% (4) Confidence intervals with 1-alpha = 0.995 -> z = 2.58
se = 2.58*s/sqrt(numel(t));


