char * reverseWords(char * s){
    if(!s)
	return NULL;

	int i, j, tmp;
	int start = 0, end = 0;
	int len = strlen(s);
	
	for(i = 0; i < len; i++)
	{
		if(s[i] == ' ' || i+1 == len)
		{
			if(i+1 == len)
			i += 1;
			end = i;

			for(j = start; j < (start + end)/2; j++)
			{
				tmp = s[j];
				s[j] = s[start+end-1-j];
				s[start+end-1-j] = tmp;
			}

			start = i + 1;
		}
	}

	return s;
}
