clear, close all, clc;

%% Problem 5.1
% This exercise goes through usage of the most common Kalman filter
% algorithm. The Kalman filter behaves like the Wiener filter, except it is
% more approprite for non-stationary signals due to recursion.
% Discrete-time signals are used here, but it would be similar for
% continuous-time signals. The exercise treats both stationary and
% non-stationary signals.