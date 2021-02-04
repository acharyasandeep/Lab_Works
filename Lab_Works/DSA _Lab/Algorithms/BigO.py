import matplotlib.pyplot as plt
import numpy as np
n=np.linspace(1, 100000)
plt.plot(n, 10000*n, label="10000n")
plt.plot(n, n * n, label="n^2")
plt.legend(loc='upper left')
plt.show()
