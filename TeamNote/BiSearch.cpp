int lo = //(가능한 값 중 최소값)
int hi = //(불가능한 값 중 최대값)
while(lo+1 < hi){
		int mid = (hi+lo)/2;
		if(canBe(mid)) lo = mid;
		else hi = mid;
}