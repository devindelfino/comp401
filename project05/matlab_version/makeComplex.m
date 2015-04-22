function complex_points = makeComplex(reals,imags)
	complex_points = zeros(length(reals),length(imags));

	for(i= 1:length(reals))
		for(j= 1:length(imags))
			complex_points(i,j) = complex(reals(i), imags(j));
		end
	end
end