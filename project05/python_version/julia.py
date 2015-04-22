# %load julia.py
import matplotlib.pyplot as plt
import numpy as np

def make_complex(real, imag):
    complex_points = [[0 for r in range(len(real))] for c in range(len(imag))]

    for row in range(0, len(real)-1):
    	for col in range(0, len(imag)-1):
    		complex_points[row][col] = complex(real[row], imag[col])
    	#endfor
    #endfor

    return complex_points
#endfunction

def julia(z, c, n):
	lim = 10^100
	it = 0
	jpoint = z
	while((it < n)):
		if(abs(jpoint.real) >= lim or abs(jpoint.imag) >= lim):
			# return complex(0,0)
			break
		#endif

		jpoint = pow(jpoint,2) + c
		it = it + 1
	#endwhile

	return jpoint
#endfunction

def make_julia_fractal(c_real, c_imag, range_real, range_imag, incr_real, incr_imag):
	iterations = 40
	c = complex(c_real, c_imag)
	print c
	reals = list(np.arange(-range_real, range_real, incr_real))
	imaginaries = list(np.arange(-range_imag, range_imag, incr_imag))

	complex_points = make_complex(reals,imaginaries)
	# print complex_points
	julia_real = [0 for x in range(len(reals)*len(imaginaries))]
	julia_imag = [0 for x in range(len(reals)*len(imaginaries))]

	print "finding julia set\n"
	it = 0
	for row in range(0,len(reals)):
		for col in range(0,len(imaginaries)):
			juliapoint = julia(complex_points[row][col], c, iterations)
			# print juliapoint
			if(abs(juliapoint) <= 2 ):
				julia_real[it] = juliapoint.real
				julia_imag[it] = juliapoint.imag
			it = it + 1
		#endfor
	#endfor
	print "plotting julia set\n"
	fig = plt.figure()
	ax = fig.add_subplot(111, aspect="equal")
	ax.plot(julia_real, julia_imag,'.')
	# plt.scatter(julia_real, julia_imag,s=0.001)
	plt.xlim(-2, 2)
  	plt.ylim(-2, 2)
  	plt.show()
  	print "done."

#endfunction

def main():
	c_real = -0.77
	c_imag = 0.15

	# c_real = -0.81
	# c_imag = -0.1795

	# c_real = -0.08
	# c_imag = 0.156

	# c_real = -0.04
	# c_imag = -0.684

	# c_real = -0.755
	# c_imag = 0.05
	range_real = 2
	range_imag = 2
	incr_real = 0.01
	incr_imag = 0.01

	make_julia_fractal(c_real, c_imag, range_real, range_imag, incr_real, incr_imag)
#endmain

if __name__ == '__main__':
	main()
