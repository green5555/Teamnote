const int BSIZE = 524288; char buffer[BSIZE]; int p = BSIZE;
inline char readc() {
	if(p == BSIZE) { fread(buffer, 1, BSIZE, stdin); p = 0; } return buffer[p++];
}
int readi() {
	char c = readc(); while ((c < '0' || c > '9') && c != '-') c = readc();
	int ret = 0; bool neg = c == '-'; if (neg) c = readc();
	while (c >= '0' && c <= '9') { ret = ret * 10 + c - '0'; c = readc(); }
	return neg ? -ret : ret;
}


// don't forget sync_with_stdio && cin.tie
