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

	range_real = 2;
	range_imag = 2;
	incr_real = 0.01;
	incr_imag = 0.01;

	makeJuliaFractal(c_real, c_imag, range_real, range_imag, incr_real, incr_imag);
end