function main()
	
	c_real = -0.77;
	c_imag = 0.15;

	% c_real = -0.81
	% c_imag = -0.1795

	% c_real = -0.08
	% c_imag = 0.156

	% c_real = -0.04
	% c_imag = -0.684

	% c_real = -0.755
	% c_imag = 0.05

	bound = 2;
	incr = 0.01;

	makeJuliaFractal(c_real, c_imag, bound, incr);

end