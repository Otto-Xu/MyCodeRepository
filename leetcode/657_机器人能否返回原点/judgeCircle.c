bool judgeCircle(char * moves){
	if(!moves)
		return false;
	
	int up = 0, down = 0, left = 0, right = 0;
	int len = strlen(moves);				
	int i;						
	
	for(i = 0; i < strlen(moves); i++)
	{
		if(moves[i] == 'U')
			up++;
		else if(moves[i] == 'D')			
			down++;
		else if(moves[i] == 'L')
			left++;
		else if(moves[i] == 'R')
			right++;
	}

	if(up == down && left == right)
		return true;
	else 		
		return false;
}
