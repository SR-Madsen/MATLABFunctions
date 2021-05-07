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

#fig2, axs2 = plt.subplots(2)
fig2, axs2 = plt.subplots(1)
error = (taylor_sin - real_sin)
axs2.plot(inputs, error)

#error_LSB = 
#axs2[1].plot(inputs, error_LSB)