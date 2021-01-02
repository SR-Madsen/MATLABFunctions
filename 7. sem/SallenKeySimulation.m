clear, close all, clc;

SD = readmatrix('SK_STEP.csv'); % Data in column 1 is garbage.

SDtime = SD(1,:);
SDtime = SDtime(2:end);
SDvolt = SD(2,:);
SDvolt = SDvolt(2:end);

figure(1)
plot(SDtime, SDvolt, 'LineWidth', 2)
fig1 = gca;
fig1.FontSize = 14;
title('Designed Sallen-Key filter response to 1 V step', 'FontSize', 22)
xlabel('Time [s]', 'FontSize', 18)
ylabel('Voltage [V]', 'FontSize', 18)
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
fig2 = gca;
fig2.FontSize = 14;
title('Designed Sallen-Key filter transfer function with and without subsequent RC filter', 'FontSize', 22)
xlabel('Frequency [Hz]', 'FontSize', 18)
ylabel('Amplitude [dB]', 'FontSize', 18)
lgd = legend('Without RC filter', 'With RC filter', 'Location', 'northeast')
lgd.FontSize = 18
grid on