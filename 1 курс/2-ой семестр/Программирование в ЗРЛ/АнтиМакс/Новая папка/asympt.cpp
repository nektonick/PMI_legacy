	std::vector<int> vec(n);
	/*vec заполнили*/
	int m = vec[0];

	for(int i = 0; i < nl ++i){
	    if(vec[i] >= m)
	        m = vec[i];
	}