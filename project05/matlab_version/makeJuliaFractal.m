function makeJuliaFractal(c_real, c_imag, bound, incr)
	iters = 40;
	c = complex(c_real, c_imag);
	c

	reals = -bound:incr:bound;
	% imaginaries = -range_imag:incr_imag:range_imag;
	
	% complex_points = makeComplex(reals,reals);

	% julia_reals = zeros(length(reals)*length(imaginaries));
	% julia_imags = zeros(length(reals)*length(imaginaries));
	julia_set = zeros(length(reals)*length(reals));

	'finding julia set'
	it = 1;
	for(i = 1:length(reals))
		for(j = 1:length(reals))
			complexpoint = complex(reals(i), reals(j))
			juliapoint = julia(complexpoint, c, iters);
			if(abs(juliapoint) <= 2)
				% julia_reals(it) = real(juliapoint);
				% julia_imags(it) = imag(juliapoint);
				julia_set(it) = complexpoint;
			else
				julia_set(it) = complex(0,0);
			end
			it = it + 1;
		end
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