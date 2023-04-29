int majorityElement(vector<int> v) {
	int cnt = 0, el;

	int n = v.size();

	for(int i=0;i<n;i++) {

		if(cnt==0) {
			el = v[i];
			cnt = 1;
		}
		else if(v[i]==el) 
		   cnt++;
		else
		   cnt--;
	}

	int k = 0;

	for(int i=0;i<n;i++) {

		if(el==v[i]) k++;
	}

	if(k > (n/2))
	   return el;
	else
	  return -1;
}