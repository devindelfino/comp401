function makeJuliaFractal(c_real, c_imag, range_real, range_imag, incr_real, incr_imag)
	iters = 40;
	c = complex(c_real, c_imag);
	c

	reals = -range_real:incr_real:range_real;
	% imaginaries = -range_imag:incr_imag:range_imag;
	'getting all complex points'
	complex_points = makeComplex(reals,reals);

	% julia_reals = zeros(length(reals)*length(imaginaries));
	% julia_imags = zeros(length(reals)*length(imaginaries));
	julia_set = zeros(length(reals)*length(reals));

	'finding julia set'
	it = 1;
	for(i = 1:length(reals))
		for(j = 1:length(reals))
			juliapoint = julia(complex_points(i,j), c, iters);
			if(abs(juliapoint) <= 2)
				% julia_reals(it) = real(juliapoint);
				% julia_imags(it) = imag(juliapoint);
				julia_set(it) = juliapoint;
			else
				julia_set(it) = complex(0,0);
			end
			it = it + 1;
		end
		i
	end

	'plotting julia set'
	% length(julia_reals)
	% length(julia_imags)
	% julia_reals
	% scatter(julia_reals, julia_imags,'x')
	plot(julia_set,'.');
	axis equal
	axis([-2 2 -2 2])
	'done.'
end