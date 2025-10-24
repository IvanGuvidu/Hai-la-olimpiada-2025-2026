#include <bits/stdc++.h>
 
#define Nmax 100005
#define ll long long

using namespace std;
ifstream fin("permutariab.in");
ofstream fout("permutariab.out");
int N, A[Nmax], B[Nmax], pos[Nmax];
ll mergesort(int le, int ri)
{
	if(le == ri)
		return 0;
	int mid = (le + ri) / 2;
	ll ret = mergesort(le, mid) + mergesort(mid + 1, ri);
	int pos = le;
	int j = mid + 1;
	for(int i = le; i <= mid; i++)
	{
		while(j <= ri && A[j] < A[i])
			B[pos++] = A[j++];
		ret += j - mid - 1;
		B[pos++] = A[i];
	}
	while(j <= ri)
		B[pos++] = A[j++];
	for(int i = le; i <= ri; i++)
		A[i] = B[i];
	return ret;
}
 
int main()
{
	fin >> N;
	for(int i = 1; i <= N; i++)
	{
		int x;
		fin >> x;
		pos[x] = i;
	}
	for(int i = 1; i <= N; i++)
	{
		int x;
		fin >> x;
		A[i] = pos[x];
	}
	fout << mergesort(1, N) << "\n";
	return 0;
}
