# -*- coding: utf-8 -*-
"""
Created on Fri May  7 08:08:09 2021

@author: Sebastian
"""

import numpy as np
import matplotlib.pyplot as plt

inputs = np.linspace(-np.pi, np.pi, 6280)

real_sin = np.sin(inputs)

a1 = -1/np.math.factorial(3)
a2 = 1/np.math.factorial(5)
a3 = -1/np.math.factorial(7)
a4 = 1/np.math.factorial(9)

taylor_sin = (inputs * (1 + inputs**2 * (a1 + inputs**2 * (a2
             + inputs**2 * (a3 + inputs**2 * a4)))))

fig, axs = plt.subplots(2)
axs[0].plot(inputs, real_sin)
axs[1].plot(inputs, taylor_sin)

error = (taylor_sin - real_sin)

plt.figure(3, dpi=1200)
plt.plot(inputs, error)
plt.rcParams.update({'font.size': 12})
plt.xlabel("Input")
plt.ylabel("Absolute error")
plt.title("Error of Taylor approximation as function of input")
plt.grid()

#deviation = (abs(real_sin - taylor_sin))/real_sin * 100
#plt.figure(4)
#plt.plot(inputs, deviation)