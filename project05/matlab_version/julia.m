function jp = julia(z, c, n)
	lim = 2;
	lim2 = 10^100;
	jp = z;

	for(it = 1:n)
		if(abs(real(jp)) >= lim2 | abs(imag(jp)) >= lim2)
			break;
		end

		jp = jp^2 + c;

	end
end