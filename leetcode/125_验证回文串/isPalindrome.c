bool isPalindrome(char * s)
{
    if(!s)
	return false;

	int len = strlen(s);
	int left = 0, right = len-1;
	int i;

	for(i = 0; i < len; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 'a' - 'A';
	}

	while(left < right)
	{
		if(((s[left] >= 'A') && (s[left] <= 'Z')) || ((s[left] >= '0') && (s[left] <= '9')))
		{
			if(((s[right] >= 'A') && (s[right] <= 'Z')) || ((s[right] >= '0') && (s[right] <= '9')))
			{
				if(s[left] == s[right])
				{
					left++;
					right--;
					continue;
				}
				else
					return false;
			}
			else
			{
				right--; 
				continue;
			}
		}
		else
			left++;
	}

	return true;
}
