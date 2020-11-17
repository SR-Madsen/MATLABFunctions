clear, close all, clc;

SD = readmatrix('SK_STEP.csv'); % Data in column 1 is garbage.

SDtime = SD(1,:);
SDtime = SDtime(2:end);
SDvolt = SD(2,:);
SDvolt = SDvolt(2:end);

figure(1)
plot(SDtime, SDvolt, 'LineWidth', 2)
title('Designed Sallen-Key filter response to 1 V step', 'FontSize', 20)
xlabel('Time [s]', 'FontSize', 16)
ylabel('Voltage [V]', 'FontSize', 16)
grid on

TF = readmatrix('SK_TF.csv'); % Same

TFfreq = TF(1,:);
TFfreq = TFfreq(2:end);
TFampOA = TF(2,:);
TFampOA = TFampOA(2:end);
TFampRC = TF(3,:);
TFampRC = TFampRC(2:end);

figure(2)
semilogx(TFfreq, TFampOA, TFfreq, TFampRC, 'LineWidth', 2)
title('Designed Sallen-Key filter transfer function with and without subsequent RC filter', 'FontSize', 20)
xlabel('Frequency [Hz]', 'FontSize', 16)
ylabel('Amplitude [dB]', 'FontSize', 16)
grid on