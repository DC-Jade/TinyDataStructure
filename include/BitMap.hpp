#ifndef INCLUDE_BITMAP_H
#define INCLUDE_BITMAP_H

namespace mydatastructure {

class BitMap {
public:
	BitMap(int n = 8) { Init(n); }
	BitMap(char *file, int n = 8) {
		Init(n); 
		FILE *fp = fopen(file, "r");
		fread(_M, sizeof(char), _N, fp);
		fclose(fp);
	}
	~BitMap() { delete [] _M; _M = nullptr; }

	// void Set(int k)		{ Expand(k); _M[k >> 3] |= (0x80 >> (k & 0x07)); }
	// void Clear(int k) { Expand(k); _M[k >> 3] &= ~(0x80 >> (k & 0x07));
	// bool Test(int k)	{ Expand(k); return _M[k >> 3] & (0x80 >> (k & 0x07)); }

	/* k & 0x07 equal to k % 8 */
	void Set(int k)		{ Expand(k); _M[k >> 3] |= (1 << (k & 0x07)); }
	void Clear(int k) { Expand(k); _M[k >> 3] &= ~(1 << (k & 0x07)); }
	bool Test(int k)	{ Expand(k); return _M[k >> 3] & (1 << (k & 0x07)); }

	void Dump(char *file) {
		FILE *fp = fopen(file, "w");
		fwrite(_M, sizeof(char), _N, fp);
		fclose(fp);
	}

	char *Bits2String(int n) {
		Expand(n - 1);
		char *s = new char[n + 1]; s[n] = '\0';
		for (int i = 0; i < n; ++i) s[i] = Test(i) ? '1' : '0';
		return s;
	}
	void Expand(int k) {
		if (k < 8 * _N) return;
		int old_N = _N;
		char *old_M = _M;
		Init(2 * k);
		memcpy_s(_M, _N, old_M, old_N);
		delete [] old_M;
	}
	
protected:
	void Init(int n) { 
		_M = new char[_N = (n + 7) / 8];
		Memset(_M, 0, _N);
	}
private:
	char *_M; int _N;


};	/* class BitMap */

}  /* namespace mydatasturcture */

#endif
